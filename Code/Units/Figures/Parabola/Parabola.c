proc Figures.Parabola uses es di bx,\
     x1, y1, x2, y2, signA, color: BYTE

        locals
                x0      dw ?
                y0      dw ?
                offset  dw ?
                a       dw ?
                yStart  dw ?
        endl

        mov     ax, cs
        add     ax, 1000h
        mov     es, ax

        ;высчитываем параметры параболы
        mov     ax, [x1]
        add     ax, [x2]
        shr     ax, 1
        mov     [x0], ax

        cmp     [signA], 0
        jl      .NegSignA
.PosSignA:
        mov     ax, [y1]
        jmp     @F
.NegSignA:
        mov     ax, [y2]
        jmp     @F
@@:
        mov     [y0], ax

        mov     ax, [x0]
        sub     ax, [x1]
        mov     [offset], ax

        xor     dx, dx
        imul    ax, ax
        mov     bx, [y1]
        add     bx, [y2]
        sub     bx, [y0]
        sub     bx, [y0]
        idiv    bx
        mov     [a], ax

        ;корректировка границ
        inc     [x1]
        dec     [x2]
        
        ;устанавливаем начальные координаты для рисовки
        mov     ax, [y1]
        add     ax, [y2]
        sub     ax, [y0]
        mov     [yStart], ax

.Loop1:
        ;(x-x0)^2/a+y0
        xor     dx, dx
        mov     ax, [x1]
        sub     ax, [x0]
        imul    ax, ax
        mov     cx, [a]
        idiv    cx
        add     ax, [y0]

        ;((x-x0)^2/a+y0 - yStart) * signA * (-1)
        sub     ax, [yStart]
        imul    ax, [signA]
        imul    ax, -1
        mov     cx, ax

        imul    di, [yStart], 320
        add     di, [x1]

        mov     al, [color]

.Loop2:
        mov     [es:di], al

        imul    dx, [signA], -320
        add     di, dx

        loop    .Loop2

        inc     [x1]
        mov     dx, [x2]
        cmp     [x1], dx
        jbe     .Loop1

        ret
endp