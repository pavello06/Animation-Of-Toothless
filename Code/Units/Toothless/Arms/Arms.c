proc Toothless.Arms\
     x, y, direction, color, shadowColor

        locals
                x1      dw ?
                y1      dw ?
                x2      dw ?
                y2      dw ?
        endl

        ;“≈Õ‹-----------------------------------------------------------------
        mov     ax, [x]
        sub     ax, ARMS_WIDTH / 2
        mov     [x1], ax

        mov     ax, [y]
        sub     ax, [armsHeight]
        mov     [y1], ax

        mov     ax, [x1]
        add     ax, ARMS_WIDTH
        mov     [x2], ax

        mov     ax, [y]
        mov     [y2], ax

        stdcall Figures.Parabola, [x1], [y1], [x2], [y2], -1, [shadowColor]

        ;–” »-----------------------------------------------------------------
        imul    ax, [direction], -1
        add     [x1], ax

        add     [x2], ax

        stdcall Figures.Parabola, [x1], [y1], [x2], [y2], -1, [color]

        ;‘ŒÕ------------------------------------------------------------------
        add     [x1], WRISTS_WIDTH

        sub     [x2], WRISTS_WIDTH

        sub     [y2], SHOULDERS_WIDTH

        stdcall Figures.Parabola, [x1], [y1], [x2], [y2], -1, armsBackgroundColor

        ret
endp