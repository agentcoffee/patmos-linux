#
# linux/arch/c6x/Makefile
#
# This file is subject to the terms and conditions of the GNU General Public
# License.  See the file "COPYING" in the main directory of this archive
# for more details.
#

#KBUILD_DEFCONFIG := dsk6455_defconfig

#cflags-y += -mno-dsbt -msdata=none -D__linux__

#KBUILD_CFLAGS_MODULE   += -mlong-calls -mno-dsbt -msdata=none

CROSS_COMPILE   = patmos-

CHECKFLAGS      +=

KBUILD_CFLAGS   += $(cflags-y)
KBUILD_AFLAGS   += $(cflags-y)

head-y          := arch/patmos/kernel/head.o
core-y          += arch/patmos/kernel/ arch/patmos/platforms/
#libs-y          += arch/patmos/lib/

# Default to vmlinux.bin, override when needed
all: vmlinux.bin

boot := arch/$(ARCH)/boot

# Are we making a dtbImage.<boardname> target? If so, crack out the boardname
DTB:=$(subst dtbImage.,,$(filter dtbImage.%, $(MAKECMDGOALS)))
export DTB

core-y	+= $(boot)/dts/

# With make 3.82 we cannot mix normal and wildcard targets

vmlinux.bin: vmlinux
	$(Q)$(MAKE) $(build)=$(boot) $(patsubst %,$(boot)/%,$@)

dtbImage.%: vmlinux
	$(Q)$(MAKE) $(build)=$(boot) $(patsubst %,$(boot)/%,$@)

archclean:
	$(Q)$(MAKE) $(clean)=$(boot)

define archhelp
  @echo '  vmlinux.bin     - Binary kernel image (arch/$(ARCH)/boot/vmlinux.bin)'
  @echo '  dtbImage.<dt>   - ELF image with $(arch)/boot/dts/<dt>.dts linked in'
  @echo '                  - stripped elf with fdt blob'
endef
