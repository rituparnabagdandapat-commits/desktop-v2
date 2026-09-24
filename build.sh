sudo apt install nasm gcc qemu -y
nasm -f elf64 boot.asm -o boot.o
gcc -c kernel.c -o kernel.o -ffreestanding -nostdlib -m64
ld -T linker.ld -o mbs_kernel.elf boot.o kernel.o
mkdir -p iso_root/boot
cp mbs_kernel.elf limine.cfg iso_root/boot/
git clone https://github.com/limine-bootloader/limine.git
make -C limine
cp limine/bin/limine-bios.sys iso_root/boot/
xorriso -as mkisofs -b boot/limine-bios.sys --no-emul-boot -o mbs-os.iso iso_root/
