proc Toothless.Body\
     x, y, direction, color, shadowColor

        locals
                x1      dw ?
                y1      dw ?
                x2      dw ?
                y2      dw ?
        endl

        ;ремэ-----------------------------------------------------------------
        mov     ax, [x]
        sub     ax, BODY_WIDTH / 2
        mov     [x1], ax

        mov     ax, [y]
        sub     ax, BODY_HEIGHT / 2
        mov     [y1], ax

        mov     ax, [x1]
        add     ax, BODY_WIDTH
        mov     [x2], ax

        mov     ax, [y1]
        add     ax, BODY_HEIGHT
        mov     [y2], ax

        stdcall    Figures.Rectangle, [x1], [y1], [x2], [y2], [shadowColor]

        ;рекн-----------------------------------------------------------------
        imul    ax, [direction], -1
        add     [x1], ax

        add     [x2], ax

        stdcall    Figures.Rectangle, [x1], [y1], [x2], [y2], [color]

        ret
endp