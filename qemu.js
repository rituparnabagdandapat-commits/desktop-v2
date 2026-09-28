- name: Install QEMU
  run: qemu-system-x86_86 -cdrom MBS-OS.iso -m 1024 -cpu qemu86 -boot d
    sudo apt-get update
    sudo apt-get install -y qemu-system
