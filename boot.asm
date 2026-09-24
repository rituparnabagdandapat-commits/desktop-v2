[BITS 64]
section.text
global _start
_start:
    cli
    hlt
    jmp _start
