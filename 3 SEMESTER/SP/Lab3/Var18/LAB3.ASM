.MODEL LARGE

DATA1 SEGMENT 
	SUMC4 DW 0
	SUMNC4 DW 0
	A1 dd 3 *5 *1 dup(1020201h)
DATA1 ENDS

DATA2 SEGMENT
	A2 dw 2*8*4 dup(0)
	A3 dw 4*4*4 dup(0)
DATA2 ENDS

CODE1 SEGMENT
	ASSUME CS:CODE1, DS:DATA1

	start:
		mov ax, DATA1
		mov ds, ax
		mov cx, size A1
		xor si, si

		loops:
			lea ax, A1[si]
			mov bx, 4
			div bx
			cmp dx, 0
			je crat
				mov ax, SUMNC4
				xor bx, bx
				mov bl, BYTE PTR A1[si]
				add ax, bx
				mov SUMNC4, ax
				jmp cend
			crat:
				mov ax, SUMC4
				xor bx, bx
				mov bl, BYTE PTR A1[si]
				add ax, bx
				mov SUMC4, ax
			cend:

			inc si

			cmp si, cx
			jl loops

			jmp seg2start


CODE1 ENDS

CODE2 SEGMENT
	ASSUME CS:CODE2, DS:DATA1, ES:DATA2
	seg2start LABEL FAR
	mov ax, DATA1
	mov ds, ax
	mov ax, DATA2
	mov es, ax

	mov ax, SUMC4
	lea di, A2
	mov cx, size A2
	rep STOSB

	mov ax, SUMNC4
	lea di, A3
	mov cx, size A3
	rep STOSB


	mov ax, 4C00h
	int 21h

	end start

CODE2 ENDS
