.586
.model flat, stdcall
includelib libucrt.lib
includelib kernel32.lib
includelib "C:/DKD-2024/DKD-2024/Generation/Debug/GenLib.lib"
ExitProcess PROTO:DWORD 
.stack 4096


 outnum PROTO : DWORD

 outstr PROTO : DWORD

 date PROTO 
 ston  PROTO : DWORD,  : DWORD

.const
		newline byte 13, 10, 0
		LTRL1 sdword 15
		LTRL2 sdword 1
		LTRL3 sdword 2
		LTRL4 sdword 3
		LTRL5 sdword 4
.data
		temp sdword ?
		buffer byte 256 dup(0)
		maina sdword 0
.code

;----------- MAIN ------------
main PROC
push LTRL1

pop ebx
mov maina, ebx

push LTRL2
push LTRL3
pop ebx
pop eax
add eax, ebx
push eax
push LTRL4
pop ebx
pop eax
add eax, ebx
push eax
push LTRL5
pop ebx
pop eax
sub eax, ebx
push eax

pop ebx
mov maina, ebx

push 0
call ExitProcess
main ENDP
end main
