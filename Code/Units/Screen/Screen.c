proc Screen.SetMode\
     modeInfo

        mov        ah, $0F
        int        10h
        mov        bl, al

        movzx      ax, byte [modeInfo]
        int        10h
        mov        ah, $05
        mov        al, byte [modeInfo + 1]
        int        10h

        xchg       ax, bx

        ret
endp

proc Screen.Copy uses ds es si di

        mov     ax, cs
        add     ax, 1000h
        mov     ds, ax

        push    $A000
        pop     es

        mov     cx, 32000
        xor     si, si
        xor     di, di
        rep     movsw

        ret
endp

proc Screen.Clear uses es di

        mov        ax, cs
        add        ax, 1000h
        mov        es, ax

        mov        cx, 64000
        xor        di, di
        mov        al, backgroundColor
        rep        stosb

        ret
endp    