.model small
option casemap: none
.data
org 0EH
from db 6 dup(2BH)
org 26H
to db 6 dup(1BH)
.code
main proc far
  mov ax, @data
  mov ds, ax
  mov si, offset from
  mov di, offset to
  mov cx, 6
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
