proc Figures.Circle uses es di,\
     x1, y1, x2, y2, color: BYTE

        locals
                x0      dw ?
                y0      dw ?
                r^2     dw ?
                x       dw ?
                y       dw ?
        endl

        mov     ax, cs
        add     ax, 1000h
        mov     es, ax

        ;высчитываем параметры круга
        mov     ax, [x1]
        add     ax, [x2]
        shr     ax, 1
        mov     [x0], ax

        mov     ax, [y1]
        add     ax, [y2]
        shr     ax, 1
        mov     [y0], ax

        mov     ax, [x2]
        sub     ax, [x0]
        imul    ax, ax
        mov     [r^2], ax
        
        ;устанавливаем начальные координаты для рисовки
        mov     ax, [x1]
        mov     [x], ax

        mov     ax, [y1]
        mov     [y], ax

        mov     di, [y1]
        imul    di, 320
        add     di, [x1]

        ;рассчитываем число повторений
        mov     cx, [x2]
        sub     cx, [x1]
        inc     cx
        imul    cx, cx

.Loop:
        ;высчитываем попадание в круг
        mov     ax, [x]
        sub     ax, [x0]
        imul    ax, ax

        mov     dx, [y]
        sub     dx, [y0]
        imul    dx, dx

        add     ax, dx

        ;(x-x0)^2+(y-y0)^2 < r^2 - закрашиваем
        cmp     ax, [r^2]
        ja      @F

        ;красим
        mov     al, [color]
        mov     [es:di], al

        ;сдвигаем точку
@@:
        mov     ax, [x2]
        cmp     [x], ax
        je      .IncY

.IncX:
        inc     [x]

        inc     di
        jmp     @F
.IncY:
        inc     [y]

        mov     ax, [x1]
        mov     [x], ax

        add     di, 320
        add     di, [x1]
        sub     di, [x2]
        jmp     @F

@@:
        loop    .Loop

        ret
endp