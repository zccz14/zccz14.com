.386
.model flat, stdcall
option casemap: none

include kernel32.inc
includelib kernel32.lib

.code
main proc
  mov si, 0010H
  mov di, 0028H
  mov ecx, 6
  .while ecx
    mov eax, [esi]
    mov [edi], eax
    dec ecx
    inc esi
    inc edi
  .endw
  invoke ExitProcess, 0
  ret
main endp
end main
