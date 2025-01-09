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
		LTRL1 byte 'test', 0
		LTRL2 sdword 1
		LTRL3 byte 'test string', 0
		LTRL4 byte '17', 0
		LTRL5 sdword 0
		LTRL6 sdword 3
		LTRL7 byte ' ', 0
		LTRL8 sdword 53
		LTRL9 sdword 2
.data
		temp sdword ?
		buffer byte 256 dup(0)
		mainstr dword ?
		maindig dword ?
		mainnum sdword 0
		maincounter sdword 0
		mainbin sdword 0
.code

;----------- fnwrt ------------
wrt PROC 
	
; --- save registers ---
push ebx
push edx
; ----------------------

push offset LTRL1
call outstr

push offset newline
call outstr

; --- restore registers ---
pop edx
pop ebx
; -------------------------
ret
wrt ENDP
;------------------------------


;----------- fnsdvig ------------
sdvig PROC,
	sdviga : sdword  
; --- save registers ---
push ebx
push edx
; ----------------------
push sdviga
push LTRL2
pop ebx 
pop eax 
mov cl, bl 
shl eax, cl
push eax

pop ebx
mov sdviga, ebx

; --- restore registers ---
pop edx
pop ebx
; -------------------------
mov eax, sdviga
ret
sdvig ENDP
;------------------------------


;----------- MAIN ------------
main PROC
mov mainstr, offset LTRL3
mov maindig, offset LTRL4

push maindig
push offset buffer
call ston
push eax

pop ebx
mov mainnum, ebx


push mainnum
call outnum

push offset newline
call outstr


call wrt


push mainnum
call sdvig
push eax

pop ebx
mov mainnum, ebx


push mainnum
call outnum

push offset newline
call outstr

push LTRL5

pop ebx
mov maincounter, ebx

mov edx, maincounter
cmp edx, LTRL6

jnz cycle1
jmp cyclenext1
cycle1:
push maincounter
push LTRL2
pop ebx
pop eax
add eax, ebx
push eax

pop ebx
mov maincounter, ebx


push maincounter
call outnum


push offset LTRL7
call outstr

mov edx, maincounter
cmp edx, LTRL6

jnz cycle1
cyclenext1:
push offset newline
call outstr


push offset buffer
call date

push LTRL8

pop ebx
mov mainbin, ebx


push mainbin
call outnum

push offset newline
call outstr

push mainbin
push LTRL9
pop ebx 
pop eax 
mov cl, bl 
shr eax, cl
push eax

pop ebx
mov mainbin, ebx


push mainbin
call outnum

push offset newline
call outstr

push mainbin
push LTRL9
pop ebx 
pop eax 
mov cl, bl 
shl eax, cl
push eax

pop ebx
mov mainbin, ebx


push mainbin
call outnum

push offset newline
call outstr

push 0
call ExitProcess
main ENDP
end main
