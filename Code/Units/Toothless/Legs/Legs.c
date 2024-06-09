proc Toothless.Legs\
     x, y, direction, color, shadowColor

        locals
                x1      dw ?
                y1      dw ?
                x2      dw ?
                y2      dw ?
        endl

        ;“≈Õ‹-----------------------------------------------------------------
        mov     ax, [x]
        sub     ax, LEGS_WIDTH / 2
        mov     [x1], ax

        mov     ax, [y]
        mov     [y1], ax

        mov     ax, [x1]
        add     ax, LEGS_WIDTH
        mov     [x2], ax

        mov     ax, [y]
        add     ax, [legsHeight]
        mov     [y2], ax

        stdcall Figures.Parabola, [x1], [y1], [x2], [y2], 1, [shadowColor]

        ;ÕŒ√»-----------------------------------------------------------------
        imul    ax, [direction], -1
        add     [x1], ax

        add     [x2], ax

        stdcall Figures.Parabola, [x1], [y1], [x2], [y2], 1, [color]

        ;‘ŒÕ------------------------------------------------------------------
        add     [x1], FEET_WIDTH

        add     [y1], PELVIS_WIDTH

        sub     [x2], FEET_WIDTH

        stdcall Figures.Parabola, [x1], [y1], [x2], [y2], 1, legsBackgroundColor

        ret
endp