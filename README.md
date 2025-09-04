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
│   ├── Toolchain、           # Prebuilt toolchain + env setup script
│   ├── U-Boot/               # U-Boot bootloader
│   ├── Kernel/               # Linux kernel sources
│   ├── Buildroot/            # Rootfs & toolchain build system
│   └── SignTool/             # Image signing utility
└── README                    # Instructions
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
source Toolchain/devel_leipzig   # Needed for rest of the steps
```
---

## 4. Build Trusted Firmware-A (TF-A)

The **Trusted Firmware-A (TF-A)** provides the EL3 runtime firmware (e.g., `bl31.bin`) that initializes the SoC and hands off control to U-Boot.  
Using the following command to compile BL31:

```bash
cd TF-A
make distclean
make PLAT=wagner DEBUG=0 bl31
```

Output:  
```
build/leipzig/release/bl31/bl31.bin
```

---

## 5. Build U-Boot  

```bash
cd U-Boot
make distclean
make leipzig_defconfig
make 
```

Output: `u-boot.bin`  

---

## 6. Build Kernel + DTB  

```bash
cd Kernel
make clean
make menuconfig   # add/remove kernel modules
make leipzig_defconfig
make

# Just to build device tree
make dtbs
```

Output:  
- Kernel: `arch/arm64/boot/Image`  
- Device Trees: `arch/arm64/boot/dts/*.dtb`  

---

## 7. Build Rootfs  

```bash
cd Buildroot
make clean
make leipzig_rootfs_defconfig
make menuconfig   # add/remove packages
make target-post-image
```

Output: `output/images/rootfs.squashfs`  

---
