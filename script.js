var emulator = new V86Starter({
    wasm_path: "v86.wasm",
    memory_size: 256 * 1024 * 1024,
    vga_memory_size: 8 * 1024 * 1024,
    screen_container: document.getElementById("screen_container"),
    bios: { url: "seabios.bin" },
    vga_bios: { url: "vgabios.bin" },
    cdrom: { url: "MBS-OS.iso" },
    autostart: true,
    // THIS FIXES YOUR PANIC:
    cpu: "x86_64"
});
