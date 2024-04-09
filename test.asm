section .data
    hello db 'Hello, World!', 0xA   ; String to be printed, with newline character (0xA)
    hello_len equ $ - hello           ; Length of the string

section .text
    global _start                    ; Entry point for the program

_start:
    ; Write 'Hello, World!' to stdout
    mov rax, 1                       ; System call for sys_write
    mov rdi, 1                       ; File descriptor 1 (stdout)
    mov rsi, hello                   ; Pointer to the message
    mov rdx, hello_len               ; Length of the message
    syscall                          ; Invoke syscall

    ; Exit the program
    mov rax, 60                      ; System call for sys_exit
    xor rdi, rdi                     ; Exit code 0
    syscall                          ; Invoke syscall
