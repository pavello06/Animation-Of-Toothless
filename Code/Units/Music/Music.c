proc Note\
     note: BYTE

        mov     dx, $330
        mov     al, $90
        out     dx, al
        mov     al, [note]
        out     dx, al
        mov     al, $7F
        out     dx, al
        mov     al, $F7
        out     dx, al

        ret
endp