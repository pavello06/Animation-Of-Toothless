proc Bird uses es di bx si,\
     x, y, bird

        mov     ax, cs
        add     ax, 1000h
        mov     es, ax

        mov     di, [y]
        imul    di, 320
        add     di, [x]

        mov     cx, 12

.Loop1:
        push    cx

        mov     cx, 17
.Loop2:
        xor     bh, bh
        mov     bl, [birdOffset]
        mov     si, [bird]
        add     si, bx
        mov     bl, byte [si]
        cmp     bl, 0
        jl      .EndLoop2

        mov     [es:di], bl

.EndLoop2:
        inc     di
        inc     [birdOffset]

        loop    .Loop2

        add     di, 319 - 16

        pop     cx
        loop    .Loop1

        mov     [birdOffset], 0

        ret
endp