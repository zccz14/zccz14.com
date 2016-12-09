.model small
option casemap: none

.data
num dw 1111H, 2222H, 3333H, 4444H
.code
main proc
  mov ax, @data
  mov ds, ax
  mov ax, 0
  mov dx, 0
  lea si, num
  mov cx, 4
  L1S:
    cmp cx, 0
    jz L1E
    add ax, [si]
    jnc T1E
      inc dx
    T1E:
    add si, 2
    dec cx
    jmp L1S
  L1E:
  mov ax, 4c00h
  int 21h
  ret
main endp
end main
