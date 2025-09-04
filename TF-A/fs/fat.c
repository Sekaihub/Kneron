/*
 * fat.c
 *
 * R/O (V)FAT 12/16/32 filesystem implementation by Marcus Sundberg
 *
 * 2002-07-28 - rjones@nexus-tech.net - ported to ppcboot v1.1.6
 * 2003-03-10 - kharris@nexus-tech.net - ported to uboot
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <linux/types.h>
#include <linux/kernel.h>
#include <lib/libc/string.h>

#include <fs/fat.h>
#include <wagner_buf.h>

#define VOLUME_BOOT_LABEL "bootext"
#define CHECK_VOLUME_LABEL 1
/*
 * Convert a string to lowercase.
 */
static void
downcase(char *str)
{
	while (*str != '\0') {
		TOLOWER(*str);
		str++;
	}
}

block_dev_desc_t   block_dev;
static unsigned long part_offset = 0;

#define DOS_PART_TBL_OFFSET	0x1be
#define DOS_PART_MAGIC_OFFSET	0x1fe
#define DOS_FS_TYPE_OFFSET	0x36
#define DOS_FS32_TYPE_OFFSET    0x52

//#define __aligned(x)			__attribute__((aligned(x)))
#define DEFINE_ALIGN_BUFFER(type, name, size, align)			\
	char __##name[fatroundup(size * sizeof(type), align)]	\
			__aligned(align);				\
									\
	type *name = (type *)__##name

int disk_read (__u32 startblock, __u32 getsize, __u8 * bufptr)
{
	unsigned long begin;
	unsigned long blkcnt;

	begin = startblock + part_offset;
	blkcnt = block_dev.block_read(begin, getsize, (unsigned long *)bufptr);
	if (getsize && blkcnt == 0)
		return -1;
	else
		return blkcnt;
}

static int
cluster_is_eof(__u32 cluster)
{
    if (cluster >= 0x0FFFFFF8)
        return 1;
    return 0;
}

#define compare_sign(s1, s2)	strncmp(s1, s2, SIGNLEN)

#if defined(DEBUG) && defined(IO_HEX_DEBUG)
void hexDump (char *desc, void *addr, int len) {
123
	int i;
	unsigned char buff[17];
	unsigned char *pc = (unsigned char*)addr;

	// Output description if given.
	if (desc != NULL)
		printf ("%s:\n", desc);

	// Process every byte in the data.
	for (i = 0; i < len; i++) {
		// Multiple of 16 means new line (with line offset).

		if ((i % 16) == 0) {
			// Just don't print ASCII for the zeroth line.
			if (i != 0)
				printf ("  %s\n", buff);

			// Output the offset.
			printf ("  %04x ", i);
		}

		// Now the hex code for the specific character.
		printf (" %02x", pc[i]);

		// And store a printable ASCII character for later.
		if ((pc[i] < 0x20) || (pc[i] > 0x7e))
			buff[i % 16] = '.';
		else
			buff[i % 16] = pc[i];
		buff[(i % 16) + 1] = '\0';
	}

	// Pad out last line if not exactly 16 characters.
	while ((i % 16) != 0) {
		printf ("   ");
		i++;
	}

	// And print the final ASCII bit.
	printf ("  %s\n", buff);
}
#else
void hexDump (char *desc, void *addr, int len) 
{
	//do nothing
}
#endif
			

/*
 * Extract zero terminated short name from a directory entry.
 */
static void get_name (dir_entry *dirent, char *s_name)
{
	char *ptr;

	memcpy (s_name, dirent->name, 8);
	s_name[8] = '\0';
	ptr = s_name;
	while (*ptr && *ptr != ' ')
		ptr++;
	if (dirent->ext[0] && dirent->ext[0] != ' ') {
		*ptr = '.';
		ptr++;
		memcpy (ptr, dirent->ext, 3);
		ptr[3] = '\0';
		while (*ptr && *ptr != ' ')
			ptr++;
	}
	*ptr = '\0';
	if (*s_name == DELETED_FLAG)
		*s_name = '\0';
	else if (*s_name == aRING)
		*s_name = DELETED_FLAG;
	downcase (s_name);
}

/*
 * Get the entry at index 'entry' in a FAT (12/16/32) table.
 * On failure 0x00 is returned.
 */
static __u32
get_fatent(fsdata *mydata, __u32 entry)
{
	__u32 bufnum;
	__u32 offset;
	__u32 ret = 0x00;

	bufnum = entry / FAT32BUFSIZE;
	offset = entry - bufnum * FAT32BUFSIZE;

	FAT_DPRINT("%s: entry %u, bufnum %u offset %u\n", __func__, entry, bufnum, offset);

	/* Read a new block of FAT entries into the cache. */
	if (bufnum != mydata->fatbufnum) {
		int getsize = FATBUFSIZE/FS_BLOCK_SIZE;
		__u8 *bufptr = mydata->fatbuf;
		__u16 fatlength = mydata->fatlength;
		__u32 startblock = bufnum * FATBUFBLOCKS;

		//fatlength *= SECTOR_SIZE;	/* We want it in bytes now */
		startblock += mydata->fat_sect;	/* Offset from start of disk */

		FAT_DPRINT("FAT bufptr %p\n",bufptr); 
		if (getsize > fatlength) getsize = fatlength;
		if (disk_read(startblock, getsize, bufptr) < 0) {
			FAT_DPRINT("Error reading FAT blocks\n");
			mydata->fatbufnum = -1;
			return 0x0FFFFFF8;
		}
		hexDump("FAT", bufptr, getsize*512);
		mydata->fatbufnum = bufnum;
	}

	/* Get the actual entry from the table */
	ret = FAT2CPU32(((__u32*)mydata->fatbuf)[offset]);

	FAT_DPRINT("ret: %u, offset: %u\n", ret, offset);
	return ret;
}
/*
 *	DEFINE_ALIGN_BUFFER(__u8,
 *			do_fat_read_block,
 *			FS_BLOCK_SIZE, sizeof(dir_entry));
 */
__u8 *do_fat_read_block = (__u8 *)overlaid_buffer.mshc_buf.do_fat_read_block;
/*
 * Read at most 'size' bytes from the specified cluster into 'buffer'.
 * Return 0 on success, -1 otherwise.
 */
static int
get_cluster(fsdata *mydata, __u32 clustnum, __u8 *buffer, unsigned long size)
{
	int idx = 0;
	__u32 startsect;

	if (clustnum > 0) {
		startsect = mydata->data_begin + clustnum*mydata->clust_size;
	} else {
		startsect = mydata->rootdir_sect;
	}

	FAT_DPRINT("gc - clustnum: %d, startsect: %d, size %lu, buffer %p\n", clustnum, startsect, size, buffer);
	if (size / FS_BLOCK_SIZE
	 && disk_read(startsect, size/FS_BLOCK_SIZE , buffer) < 0) {
		FAT_DPRINT("Error reading data\n");
		return -1;
	}
	if (size % FS_BLOCK_SIZE) {
		__u8 *tmpbuf = do_fat_read_block;
		idx= size/FS_BLOCK_SIZE;
		if (disk_read(startsect + idx, 1, tmpbuf) < 0) {
			FAT_DPRINT("Error reading data\n");
			return -1;
		}
		buffer += idx*FS_BLOCK_SIZE;

		memcpy(buffer, tmpbuf, size % FS_BLOCK_SIZE);
		return 0;
	}

	return 0;
}


/*
 * Read at most 'maxsize' bytes from the file associated with 'dentptr'
 * into 'buffer'.
 * Return the number of bytes read or -1 on fatal errors.
 */
static long
get_contents(fsdata *mydata, dir_entry *dentptr, __u8 *buffer,
	     unsigned long maxsize)
{
	unsigned long filesize = FAT2CPU32(dentptr->size), gotsize = 0;
	unsigned int bytesperclust = mydata->clust_size * SECTOR_SIZE;
	__u32 curclust = START(dentptr);
	__u32 endclust, newclust;
	unsigned long actsize;

	FAT_DPRINT("Filesize: %ld bytes\n", filesize);

	if (maxsize > 0 && filesize > maxsize) filesize = maxsize;

	FAT_DPRINT("Reading: %lu bytes, cluster_size %u\n", filesize, mydata->clust_size);

	actsize=bytesperclust;
	endclust=curclust;
	do {
		/* search for consecutive clusters */
		while(actsize < filesize) {
			newclust = get_fatent(mydata, endclust);
			if((newclust -1)!=endclust)
				goto getit;
			if (cluster_is_eof(newclust)) {
				FAT_DPRINT("Got EOF cluster\n");
				return -1;
			}
			endclust=newclust;
			actsize+= bytesperclust;

			FAT_DPRINT("%s: endclust %u bytesperclust %u actsize %lu filesize %lu\n", __func__, endclust, bytesperclust, actsize, filesize);
		}
		/* actsize >= file size */
		actsize -= bytesperclust;
		/* get remaining clusters */
		if (actsize > 0 && get_cluster(mydata, curclust, buffer, actsize) != 0) {
			FAT_DPRINT("Error reading cluster\n");
			return -1;
		}
		gotsize += actsize;
		filesize -= actsize;
		buffer += actsize;

		/* get remaining bytes */
		actsize= filesize;
		if (actsize > 0 && get_cluster(mydata, endclust, buffer, actsize) != 0) {
			FAT_DPRINT("Error reading cluster\n");
			return -1;
		}
		gotsize += actsize;
		FAT_DPRINT("%s: return size %lu\n", __func__, gotsize);
		return gotsize;
getit:
		FAT_DPRINT("%s: gotit: curclust %u actsize %lu buffer %p\n", __func__, curclust, actsize, buffer);
		if (get_cluster(mydata, curclust, buffer, actsize) != 0) {
			FAT_DPRINT("Error reading cluster\n");
			return -1;
		}
		FAT_DPRINT("%s: gotsize %lu actsize %lu\n", __func__, gotsize, actsize);
		gotsize += actsize;
		filesize -= actsize;
		buffer += actsize;

		FAT_DPRINT("%s: gotsize %lu actsize %lu\n", __func__, gotsize, actsize);
		curclust = get_fatent(mydata, endclust);
		if (cluster_is_eof(curclust)) {
			FAT_DPRINT("Got EOF cluster return %lu\n", gotsize);
			return -1;
		}

		actsize=bytesperclust;
		endclust=curclust;
	} while (1);
}

/*
 * Read boot sector and volume info from a FAT filesystem
 */
static int
read_bootsectandvi(boot_sector *bs, int *fatsize)
{
	__u8 *block = do_fat_read_block;
	unsigned char part_table[16*4];
	unsigned char * part_ptr;
	int part_index;
	
	if (block_dev.block_read(0, 1, (unsigned long *)block) == 0)
		return -1;

	hexDump ("BootSecotr", block, SECTOR_SIZE);

	/* Check Magic */
	if (block[DOS_PART_MAGIC_OFFSET] != 0x55 ||
	    block[DOS_PART_MAGIC_OFFSET+1] != 0xAA) {
		FAT_DPRINT ("Magic error %02x-%02x\n", block[DOS_PART_MAGIC_OFFSET], block[DOS_PART_MAGIC_OFFSET+1]);
		return -1;
	}

	if (compare_sign(FAT32_SIGN, (char *)&block[DOS_FS32_TYPE_OFFSET]) == 0) {
		/* MBR not existed */
		FAT_DPRINT("MBR not existed\n");
		part_offset = 0;
	} else {

		/* Backup partition table */
		memcpy(part_table, &block[0x1be], 16 * 4);

		for (part_index = 0; part_index < 4; part_index++) {
			part_ptr = &part_table[part_index * 16];

			/* Active or Not-set */
			if (part_ptr[0] != 0 && part_ptr[0] != 0x80)
				continue;

			part_offset = FAT2CPU32(*(u32 *)&part_ptr[8]);

			FAT_DPRINT("PART %d [4] part_type = %02x part_offset %lu\n", part_index, part_ptr[4], part_offset);
			if (disk_read(0, 1, block) < 0) {
				FAT_DPRINT("Error: reading block\n");
				return -1;
			}

			hexDump ("Vol Header", block, SECTOR_SIZE);

			/* Check Magic */
			if (block[DOS_PART_MAGIC_OFFSET] != 0x55 ||
			    block[DOS_PART_MAGIC_OFFSET+1] != 0xAA) {
				FAT_DPRINT ("Part %d Magic error\n", part_index);
				FAT_DPRINT ("Magic error %02x-%02x\n", block[DOS_PART_MAGIC_OFFSET], block[DOS_PART_MAGIC_OFFSET+1]);
				continue;
			}
			/* Check VBR */
			if (compare_sign(FAT32_SIGN, (char *)&block[DOS_FS32_TYPE_OFFSET]) != 0) {
				FAT_DPRINT("Part %d Error: NON-FAT32 oft %u = %02x-%02x-%02x-%02x-%02x\n", part_index,
					   DOS_FS32_TYPE_OFFSET,
					   block[DOS_FS32_TYPE_OFFSET],
					   block[DOS_FS32_TYPE_OFFSET+1],
					   block[DOS_FS32_TYPE_OFFSET+2],
					   block[DOS_FS32_TYPE_OFFSET+3],
					   block[DOS_FS32_TYPE_OFFSET+4]);
				continue;
			}
			break;
		}
		if (part_index >= 4)
			return -1;
	}


	memcpy(bs, block, sizeof(boot_sector));
	bs->reserved	= FAT2CPU16(bs->reserved);
	bs->fat_length	= FAT2CPU16(bs->fat_length);
	bs->secs_track	= FAT2CPU16(bs->secs_track);
	bs->heads	= FAT2CPU16(bs->heads);
#if 0 /* UNUSED */
	bs->hidden	= FAT2CPU32(bs->hidden);
#endif
	bs->total_sect	= FAT2CPU32(bs->total_sect);

	FAT_DPRINT("FAT32: total sect %u\n", bs->total_sect);

	/* FAT32 entries */
	if (bs->fat_length == 0) {
		/* Assume FAT32 */
		bs->fat32_length = FAT2CPU32(bs->fat32_length);
		bs->flags	 = FAT2CPU16(bs->flags);
		bs->root_cluster = FAT2CPU32(bs->root_cluster);
		bs->info_sector  = FAT2CPU16(bs->info_sector);
		bs->backup_boot  = FAT2CPU16(bs->backup_boot);
		*fatsize = 32;
	} else {
		FAT_DPRINT("Error: broken fat_length \n");
		return -1;
	}

	return 0;
}
long
do_fat_read (const char *filename, void *buffer, unsigned long maxsize)
{
    char fnamecopy[32] = {0};
    int  file_match = 0;
#ifdef CHECK_VOLUME_LABEL
    char label[32] = {0};
    int  label_match = 0;
#endif
    char s_name[16] = {0};
    boot_sector bs;
//	DEFINE_ALIGN_BUFFER(fsdata, datablock, 1, 4);
	fsdata *datablock = (fsdata *)overlaid_buffer.mshc_buf.datablock;
	fsdata *mydata = datablock;
    dir_entry *dentptr;
    dir_entry file_dent;
    __u32 cursect;
#ifdef FAT_DEBUG
    __u32 rootdir_size;
#endif
    unsigned long ret = 0;
    __u32 curclust;

    FAT_DPRINT("%s: filename %s maxsize %lu, buffer %p\n", __func__, filename, maxsize, buffer);

    if (block_dev.block_read == NULL) {
	FAT_DPRINT ("Error: NO Storage Device registered\n");
	return -1;
    }
    if (read_bootsectandvi (&bs, &mydata->fatsize)) {
	FAT_DPRINT ("Error: reading boot sector\n");
	return -1;
    }

    FAT_DPRINT("%s: filename %p\n", __func__, filename);
    /* How many clusters a FAT occupied. */
    mydata->fatlength = bs.fat32_length;

    /* The FAT Sector Number */
    mydata->fat_sect = bs.reserved;

    /* Root sector */
    cursect = mydata->rootdir_sect
	    = mydata->fat_sect + mydata->fatlength * bs.fats;

    /* Root cluster */
    curclust = bs.root_cluster;

    /* Sectors per Cluster */
    mydata->clust_size = bs.cluster_size;

#ifdef FAT_DEBUG
    rootdir_size = mydata->clust_size;
#endif
    mydata->data_begin = mydata->rootdir_sect   /* + rootdir_size */
	    - (mydata->clust_size * 2);

    mydata->fatbufnum = -1;

    FAT_DPRINT ("filename %s FAT%d, fatlength: %d\n", filename, mydata->fatsize,
		mydata->fatlength);
    FAT_DPRINT ("Rootdir begins at sector: %u, offset: %#x, size: %u\n"
		"Data begins at: %d\n",
		mydata->rootdir_sect, mydata->rootdir_sect * SECTOR_SIZE,
		rootdir_size, mydata->data_begin);
    FAT_DPRINT ("Cluster size: %u\n", mydata->clust_size);

    /* "cwd" is always the root... */
    while (ISDIRDELIM (*filename))
	filename++;
    /* Make a copy of the filename and convert it to lowercase */
    //strncpy (fnamecopy, filename, sizeof(fnamecopy));
    //strcpy (fnamecopy, filename);
	strlcpy(fnamecopy, filename, sizeof(fnamecopy));
    downcase (fnamecopy);


    while (!cluster_is_eof(curclust)) {
		int i, sec_oft;

		/* Loop sector in this cluster */
		for (sec_oft = 0;sec_oft < mydata->clust_size; sec_oft++) {

			FAT_DPRINT ("cursect %d, sec_oft %d\n", cursect, sec_oft);
			FAT_DPRINT ("FAT%d, fatlength: %hu, maxsize %lu\n", mydata->fatsize,
				mydata->fatlength, maxsize);
			if (disk_read (cursect, 1, do_fat_read_block) < 0) {
				FAT_DPRINT ("Error: reading rootdir block\n");
				return -1;
			}
			hexDump("Sector", do_fat_read_block, SECTOR_SIZE);
			dentptr = (dir_entry *) do_fat_read_block;
			for (i = 0; i < DIRENTSPERBLOCK; i++) {
				memset (s_name, 0x0 , sizeof(s_name));
				FAT_DPRINT ("entry %d, name[0] %p=%#02x attr %#02x\n", i,
					    dentptr->name, dentptr->name[0], dentptr->attr);
				if (dentptr->name[0] == 0xE5) {
					FAT_DPRINT ("Skip deleted entry- %d\n", i);
					dentptr++;
					continue;
				} else if (dentptr->attr & ATTR_VOLUME) {
#ifdef CHECK_VOLUME_LABEL
					if (dentptr->attr == ATTR_VOLUME) {
						get_name (dentptr, label);
						FAT_DPRINT ("Volname: %s\n", label);
						if (strcmp(label, VOLUME_BOOT_LABEL)) {
							FAT_DPRINT ("Volname: %s not matched with %s\n", label, VOLUME_BOOT_LABEL);
							return -1;
						}

						label_match = 1;
						if (file_match && label_match)
							goto rootdir_done;
					}
#endif
					/* Volume label or VFAT entry */
					FAT_DPRINT ("Skip Long Entry %d\n", i);
					dentptr++;
					continue;
				} else if (dentptr->attr & ATTR_DIR) {
					FAT_DPRINT ("Skip directory index %d\n", i);
					dentptr++;
					continue;
				} else if (dentptr->name[0] == 0) {
					FAT_DPRINT ("RootDentname == NULL - %d\n", i);
					return -1;
				} else if (!file_match ) {
					get_name (dentptr, s_name);
					if (strcmp (fnamecopy, s_name)) {
						FAT_DPRINT ("RootMismatch: |%s| <=> %s\n", s_name, fnamecopy);
						dentptr++;
						continue;
					}
					file_dent = *dentptr;
					file_match = 1;


					FAT_DPRINT ("RootName: %s", s_name);
					FAT_DPRINT (", start: 0x%x", START (dentptr));
					FAT_DPRINT (", size:  0x%x %s\n",
						    FAT2CPU32 (dentptr->size), "");
				}
				dentptr++;
#ifdef CHECK_VOLUME_LABEL
				if (label_match)
					goto rootdir_done;

#else
				goto rootdir_done;  /* We got a match */
#endif
			}
			cursect++;
		}
		curclust = get_fatent(mydata, curclust);
    }
    return -1;

  rootdir_done:

    FAT_DPRINT ("%s: rootdir_done-> FAT %d, fatlength: %u maxsize %lu, buffer %p\n", __func__,
		mydata->fatsize, mydata->fatlength, maxsize, buffer);
    //check SRAM_SIZE
    if (FAT2CPU32(file_dent.size) > maxsize) {
	FAT_DPRINT("Size: %d over MAX SIZE %lu\n",
			FAT2CPU32(file_dent.size), maxsize);
	return -1;
    }

    ret = get_contents (mydata, &file_dent, buffer, maxsize);
    FAT_DPRINT ("Size: %d, got: %ld\n", FAT2CPU32 (file_dent.size), ret);

    return ret;
}

long
file_fat_read(const char *filename, void *buffer, unsigned long maxsize)
{
	FAT_DPRINT("\n>>>>>>>>>> FAT <<<<<<<<<<\n");
	FAT_DPRINT("reading %s\n",filename);
	return do_fat_read(filename, buffer, maxsize);
}
