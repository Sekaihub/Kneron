# KL730 Build Instructions

This guide walks you through setting up your Linux build environment and building everything you need to boot the Kneron KL730 platform:  

- Bootloader (**TF-A / U-Boot**)  
- Linux kernel  
- Root filesystem (rootfs)  
- Firmware packages  

By the end, you’ll have all the images ready to flash onto your KL730 board. 🚀  

---

## Build Flow Overview  

```text
+-------------------+
|   Toolchain       |
| (cross-compiler)  |
+---------+---------+
          |
          v
+-------------------+
|   Trusted FW-A    |
|    (bl31.bin)     |
+---------+---------+
          |
          v
+-------------------+
|      U-Boot       |
|   (u-boot.bin)    |
+---------+---------+
          |
          v
+-------------------+
|      Kernel       |
|   (Image + DTB)   |
+---------+---------+
          |
          v
+-------------------+
|      Rootfs       |
| (rootfs.squashfs) |
+---------+---------+
          |
          v
+-------------------+
|   Signing Tool    |
| (package images)  |
+---------+---------+
          |
          v
+-------------------+
|    Flash Board    |
|   (via fastboot)  |
+-------------------+
```

---

## 1. Build Machine Setup  

Make sure you’re on **Ubuntu 20.04 LTS (x86_64)** or similar. Other distros may work, but YMMV.  

### 1.1 Install required packages  
```bash
sudo apt-get update
sudo apt-get install -y   zlib1g-dev libssl-dev liblzma-dev build-essential   bison flex gettext libncurses5-dev texinfo autoconf automake libtool   python-is-python3 android-tools-fastboot fastboot
```

### 1.2 Serial console (optional but recommended)  
- **115200 baud, 8N1, no flow control**  
- Works with `minicom`, `picocom`, `screen`, etc.  

---

## 2. Repo Layout  

Your SDK should look like this after extraction:  

```
.
├── Knneron/
│   ├── Buildroot/            # Rootfs & toolchain build system
│   ├── Toolchain、           # Prebuilt toolchain + env setup script
```

---

## 3. Toolchain  

### 3.1 Use the prebuilt toolchain (fastest)  
```bash
cd Toolchain
sudo tar -zxvf vtcs_toolchain.tar.gz -C /opt
export PATH=/opt/vtcs_toolchain/leipzig/usr/bin:$PATH
aarch64-linux-gcc --version   # Test the toolchain
```

Then use the helper script:  
```bash
source Toolchain/devel_leipzig
```
---

## 4. Build Components  

### 4.1 Rootfs  
```bash
cd Buildroot
make clean
make leipzig_rootfs_defconfig
make menuconfig   # add/remove packages
make target-post-image
```
Result: `output/images/rootfs.squashfs`  

---


