;###########################################################################################
code SEGMENT        ; 
    ASSUME CS:code  ; 
                    ;     PROBLEM 2
                    ;#7 6 5 4 3 2 1 0
                    ; 1 1 1 1 0 0 0 0
                    ;#2 6 0 0 2 6 4 4
                    ; 0 1 0 0 0 1 0 0
;###########################################################################################
start:
    mov dl, 11110000b  ; send params in the register dl
    xor dh, dh         ; The result will be in the register dh
    mov cl, 4          ; Cycling shift by 4 bits
    
    ; x0 level
    mov bh, dl
    and bh, 00000001b  ;#al# - - - - - - - x0
    shl bh, cl         ;#al# - - - x0 - - - -
    or dh, bh          ;#dh# - - - x0 - - - -
    shl bh, 1          ;#al# - - x0 - - - - -
    or dh, bh          ;#dh# - - x0 x0 - - - -
    
    ; x2 level
    mov bh, dl  
    and bh, 00001000b  ;#al# - - - - x2 - - -
    shl bh, 1          ;#al# - - - x2 - - - -
    or dh, bh          ;#dh# - - x0 x0 x2 - - -
    shl bh, cl         ;#al# x2 - - - - - - -
    or dh, bh          ;#dh# x2 - x0 x0 x2 - - -

    ; x4 level
    sub cl, 1          ;Subctruct #cl# - 1 = 3
    mov bh, dh 
    and bh, 00010000b  ;#al# - - - x4 - - - -
    shr bh, cl         ;#al# - - - - - - x4 -
    or dh, bh          ;#dh# x2 - x0 x0 x2 - x4 - 
    shr al, 1          ;#al# - - - - - - - x4
    or dh, bh          ;#dh# x2 - x0 x0 x2 - x4 x4
    
    ; x6 level
    add cl, 1          ;Add to #cl# + 1 = 4 
    mov bh, dh
    and bh, 01000000b  ;#al# - x6 - - - - - -
    or dh, al          ;#dh# x2 x6 x0 x0 x2 - x4 x4
    shr bh, cl         ;#al# - - - - - x6 - -
    or dh, bh          ;#dh# x2 x6 x0 x0 x2 x6 x4 x4

    xor bh, bh           

    mov ax, 4c00h    
    int 21h          
 
code ENDS ;
end start