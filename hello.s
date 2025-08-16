    .global _start
    .extern _write        // функция write из libSystem
    .extern _exit         // функция exit из libSystem

    .section __TEXT,__text,regular,pure_instructions
_start:
    // write(1, msg, MSG_LEN)
    mov     x0, #1                        // fd = 1 (stdout)
    adrp    x1, msg@PAGE                  // x1 := страница, где лежит msg
    add     x1, x1, msg@PAGEOFF           // x1 := точный адрес msg
    mov     x2, #3                        // длина "Hi\n" = 3 байта
    bl      _write                        // вызвать write(fd, buf, len)

    // exit(0)
    mov     x0, #0
    bl      _exit

    .section __TEXT,__cstring
msg:
    .asciz  "Hi\n"

