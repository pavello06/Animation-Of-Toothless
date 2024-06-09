timer:
        push    ds ax cx dx bx
        push    cs
        pop     ds

        dec     [musicTicksLeft]
        jnz     .SkipMusic

        mov     bx, [musicOffset]

        stdcall Note, word [music + bx]

        movzx   bx, [musicTicks + bx]
        mov     [musicTicksLeft], bx

        inc     [musicOffset]
        cmp     [musicOffset], music.Length
        jb      .SkipMusic
        mov     [musicOffset], 0

.SkipMusic:
        dec     [animationTicksLeft]
        jnz     .SkipAnimation

        stdcall Animation

        mov     [animationTicksLeft], MAX_ANIMATION_TICKS_LEFT

.SkipAnimation:
        pop     bx dx cx ax ds

        jmp     far [cs:oldTimer]

proc SetIntVector uses es,\
     bIntNumber: BYTE, segISR, ofsISR

        xor        ax, ax
        mov        es, ax
        movzx      bx, [bIntNumber]
        shl        bx, 2

        mov        dx, [segISR]
        mov        ax, [ofsISR]

        pushf
        cli
        xchg       [es:bx], ax
        xchg       [es:bx + 2], dx
        popf

        ret
endp