.model small
option casemap: none
.data
org 0EH
from db 'hello, world', 0
org 26H
to db 11 dup(?)
.code
main proc far
  mov ax, @data
  mov ds, ax
  mov si, offset from
  mov di, offset to
  mov cx, 10
  L1S:
    cmp cx, 0
    jz L1E
    mov al, [si]
    mov [di], al
    inc si
    inc di
    dec cx
    jmp L1S
  L1E:
  mov ax, 4c00h
  int 21h
  ret
main endp
end main
