.POSIX:
CC=clang
LD=lld-link
DD=dd

CFLAGS=-Iincludes -target x86_64-pc-win32-coff -fno-stack-protector -fshort-wchar -mno-red-zone -fno-builtin -O0 -ffreestanding -fno-stack-check -fno-stack-protector -mno-stack-arg-probe
LDFLAGS=-entry:efi_main -subsystem:efi_application -nodefaultlib

FATIMG=fat32.img
PARTIMG=partition.img
DISKIMG=uefi.img

all: $(DISKIMG)

$(DISKIMG): $(PARTIMG) $(FATIMG)
	$(DD) if=/dev/zero of=$@ bs=512 count=200000
	sfdisk $@ < uefi.sfdisk
	$(DD) if=$(FATIMG) of=$@ bs=512 count=91669 seek=2048 conv=notrunc
	$(DD) if=$(PARTIMG) of=$@ bs=512 count=90000 seek=93717 conv=notrunc

$(PARTIMG):
	$(DD) if=/dev/zero of=$@ bs=512 count=90000
	mkfs.ext4 $@

$(FATIMG): main.efi
	$(DD) if=/dev/zero of=$@ bs=512 count=91669	
	mkfs.vfat -F32 $@
	mmd -i $@ ::/EFI
	mmd -i $@ ::/EFI/BOOT
	mcopy -i $@ main.efi ::/EFI/BOOT/bootx64.efi
	mcopy -i $@ main.efi ::

kuefi.lib: lib/kuefi.c lib/print.c lib/fs.c lib/input.c
	$(CC) $(CFLAGS) -c lib/kuefi.c -o kuefi.o
	$(CC) $(CFLAGS) -c lib/input.c -o input.o
	$(CC) $(CFLAGS) -c lib/print.c -o print.o
	$(CC) $(CFLAGS) -c lib/fs.c -o fs.o
	$(LD) -lib -out:$@ -subsystem:efi_application fs.o kuefi.o print.o input.o

main.efi: main.o kuefi.lib
	$(LD) $(LDFLAGS) -out:$@ main.o kuefi.lib

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o $@

clean:
	rm *.o main.efi *.img *.lib

