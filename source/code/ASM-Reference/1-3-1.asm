.386
.model flat, stdcall
option casemap: none

include kernel32.inc
include msvcrt.inc
includelib kernel32.lib
includelib msvcrt.lib

.data
temp dword ?
SIn db '%d', 0
SOut db '%d', 13, 10, 0
.code
main proc
  .while 1
    mov eax, 0
    push eax
    mov ecx, 0
    .while 1
      push ecx
      invoke crt_scanf, addr SIn, addr temp
      pop ecx
      .break .if eax != 1
      pop eax
      add eax, temp
      push eax
      inc ecx
      .break .if ecx == 4
    .endw
    .break .if ecx < 4
    invoke crt_printf, addr SOut, eax
    invoke crt_fflush, 0
  .endw
  invoke ExitProcess, 0
  ret
main endp
end main
