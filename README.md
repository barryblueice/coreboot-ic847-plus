**This is an UNOFFICIAL fork orginated from coreboot official!**

***

Everything started with I got this strange but interesting board:

<img width="731" height="480" alt="EF6A27DD692FC194CD9A6E87237D9208" src="https://github.com/user-attachments/assets/b4fef6cf-777c-499f-be23-6b90fcd5a802" />

The motherboard model is IC847-PLUS. It looks like a graphic card, but actually it's a computer, running on Intel® Core Sandy Bridge/Ivy Bridge platform.

The connector below PCB is used for PCIE out, in order to connect mining graphic card. About 8 PCIe 2.0 x1 lanes are routed out.

This product is affordable and in high demand in China, with the majority of users leveraging it for NAS or Openwrt router.

***

### About coreboot

This is an official release build and modified for IC847-PLUS.

The UEFI payload is powered by EDKII.

#### Known Issue:

 - This board cannot reach turbo boost clocking, CPU can only run under basic frequency.

I suspect that the power delivery scheme on this motherboard is locked, which prevents the CPU from requesting turbo boost.<br>
The non-turbo boost bug will effect ICS67-2000 version (UP1625P), another version IC847-PLUS (RT8859M) can trigger turbo boost.

 - The SPI flash is too small (4MB) on board. If running coreboot need 8MB (64Mbit) or 16MB (128Mbit for debugging) to replace.

### About PCIE lane combination:


PCIe lanes can combine to x4 or x2 to achieve greater PCIe bandwidth.

But the PCIE layout on IC847-PLUS is really weird. 1 lane from CPU, other 7 lanes are from chipset:

<img width="439" height="854" alt="6a7cc4cee03d493cb70a7b36fad41cd6" src="https://github.com/user-attachments/assets/1c0b0fa3-5ea2-48d9-b419-7445b9950ff4" />

and the last PCIE lane from chipset is for RTL8111.

So the PCIE allocation on IC847-PLUS is only support 4+2+1+1, 4+1+1+1+1 or 8x1.

The PCIE combination setting can be adjusted in Intel Flash Image Tool:

<img width="800" height="613" alt="image" src="https://github.com/user-attachments/assets/25e07ab9-2af9-4c46-a61e-0ee3bf90e2ef" />

<img width="442" height="180" alt="image" src="https://github.com/user-attachments/assets/1d89b514-9b75-4e16-b15d-9b604135f0f7" />

> [!IMPORTANT]  
> MFIT only change PCIE allocation in descriptor. If you want to modify PCIE allocation setting, coreboot source code also need to be modified!<br>
> If only one of them is modified, the PCIE device will not be enumerated.

Related PCIE layout and extension board by myself can be found in this project: [Oshwhub - The 3rd generation extension board for IC847-PLUS](https://oshwhub.com/barryblueice/project_gwkznlak)

### About Build:

Default setting has uploaded.

1. Clone the repository:
```bash
https://github.com/barryblueice/coreboot-ic847-plus.git
```
2. Build the BIOS under Linux:
```bash
cd coreboot-ic847-plus
make -j$(nproc)
```

### About flashing:

> [!WARNING]
> SPI flash need to replace with 16MB SPI flash first!<br>Recommanded SPI flash part number (supported by default):
> - W25Q128_V - EF 40 18
> - MX25L12805D - C2 20 18
> - GD25Q128 - C8 40 18
> <br>If used unsupported SPI flash, the BIOS may boot fail.

#### Flashing by Intel CSME:

1. Open `Intel ME System Tools v8 r3` -> `Flash Programming Tool`.

2. Open Powershell / cmd in this folder with Administrator privileges.

3. Backup Flash the BIOS with command:

```bash
#Backup BIOS:
.\\fptw64.exe -d backup.bin

# Flashing BIOS:
.\\fptw64.exe -f coreboot.rom
```

#### Flashing SPI flash directly:

Using CH341A or similar SPI programmer to flash BIOS. The SPI flash is under MSATA slot.

<img width="1080" height="1920" alt="5a906e2ce173878cdb588b9117ee1f35_720" src="https://github.com/user-attachments/assets/485a7181-b622-4bf0-ac06-0be4912192dc" />

coreboot README
===============

coreboot is a Free Software project aimed at replacing the proprietary
firmware (BIOS/UEFI) found in most computers. coreboot performs the
required hardware initialization to configure the system, then passes
control to a different executable, referred to in coreboot as the
payload. Most often, the primary function of the payload is to boot the
operating system (OS).

With the separation of hardware initialization and later boot logic,
coreboot is perfect for a wide variety of situations. It can be used
for specialized applications that run directly in the firmware, running
operating systems from flash, loading custom bootloaders, or
implementing firmware standards, like PC BIOS services or UEFI. This
flexibility allows coreboot systems to include only the features
necessary in the target application, reducing the amount of code and
flash space required.


Copyrights and Licenses
---------------------


### Uncopyrightable files

There are many files in the coreboot tree that we feel are not
copyrightable due to a lack of creative content.

"In order to qualify for copyright protection in the United States, a
work must satisfy the originality requirement, which has two parts. The
work must have “at least a modicum” of creativity, and it must be the
independent creation of its author."

  <https://guides.lib.umich.edu/copyrightbasics/copyrightability>

Similar terms apply to other locations.

These uncopyrightable files include:

- Empty files or files with only a comment explaining their existence.
  These may be required to exist as part of the build process but are
  not needed for the particular project.
- Configuration files either in binary or text form. Examples would be
  files such as .vbt files describing graphics configuration, .apcb
  files containing configuration parameters for AMD firmware binaries,
  and spd files as binary .spd or text \*spd\*.hex representing memory
  chip configuration.
- Machine-generated files containing version numbers, dates, hash
  values or other "non-creative" content.

As non-creative content, these files are in the public domain by
default.  As such, the coreboot project excludes them from the project's
general license even though they may be included in a final binary.

If there are questions or concerns about this policy, please get in
touch with the coreboot project via the mailing list.


### Copyrights

The copyright on coreboot is owned by quite a large number of individual
developers and companies. A list of companies and individuals with known
copyright claims is present at the top level of the coreboot source tree
in the 'AUTHORS' file. Please check the git history of each of the
source files for details.


### Licenses

Because of the way coreboot began, using a significant amount of source
code from the Linux kernel, it's licensed the same way as the Linux
Kernel, with GNU General Public License (GPL) Version 2. Individual
files are licensed under various licenses, though all are compatible
with GPLv2. The resulting coreboot image is licensed under the GPL,
version 2. All source files should have an SPDX license identifier at
the top for clarification.

Files under coreboot/Documentation/ are licensed under CC-BY 4.0 terms.
As an exception, files under Documentation/ with a history older than
2017-05-24 might be under different licenses.

Files in the coreboot/src/commonlib/bsd directory are all licensed with
the BSD-3-clause license.  Many are also dual-licensed GPL-2.0-only or
GPL-2.0-or-later.  These files are intended to be shared with libpayload
or other BSD licensed projects.

The libpayload project contained in coreboot/payloads/libpayload may be
licensed as BSD or GPL, depending on the code pulled in during the build
process. All GPL source code should be excluded unless the Kconfig
option to include it is set.


The Software Freedom Conservancy
--------------------------------

Since 2017, coreboot has been a member of [The Software Freedom
Conservancy](https://sfconservancy.org/), a nonprofit organization
devoted to ethical technology and driving initiatives to make technology
more inclusive. The conservancy acts as coreboot's fiscal sponsor and
legal advisor.
