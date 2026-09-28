- name: Install QEMU
  run: qemu-system-x86_64 -cdrom MBS-OS.iso -m 1024 -cpu qemu64 -boot d
    sudo apt-get update
    sudo apt-get install -y qemu-system-x86
