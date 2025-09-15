# a simple method to check VM
# compile:
# as ./31bit_linux.asm -o 31bit_linux.o
# ld ./31bit_linux.o -o 31bit_linux

.intel_syntax noprefix
.global _start
_start:
    mov eax, 1
    cpuid
    shr ecx, 31
    and ecx, 1      # check if the HyperV bit is on
    mov edi, ecx
    mov eax, 60
    syscall
