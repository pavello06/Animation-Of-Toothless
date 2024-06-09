proc Figures.Rectangle uses es di,\
     x1, y1, x2, y2, color: BYTE

        mov     ax, cs
        add     ax, 1000h
        mov     es, ax

        ;устанавливаем начальные координаты для рисовки
        mov     di, [y1]
        imul    di, 320
        add     di, [x1]

        mov     dx, [x2]
        sub     dx, [x1]
        inc     dx
        mov     cx, [y2]
        sub     cx, [y1]
        inc     cx

        mov     al, [color]

.Loop:
        push    cx
        mov     cx, dx
        rep     stosb
        pop     cx

        add     di, 320
        sub     di, dx

        loop    .Loop

        ret
endp