proc Toothless.Tail\
     x, y, direction, color

        locals
                x1      dw ?
                y1      dw ?
                x2      dw ?
                y2      dw ?
        endl

        ;мхфмхи убняр---------------------------------------------------------
        mov     ax, [y]
        sub     ax, BOTTOM_TAIL_HEIGHT / 2
        mov     [y1], ax

        mov     ax, [y1]
        add     ax, BOTTOM_TAIL_HEIGHT
        mov     [y2], ax

        cmp     [direction], 0
        jl      .bRight

.bLeft:
        mov     ax, [x]
        sub     ax, BOTTOM_TAIL_WIDTH
        mov     [x1], ax

        mov     ax, [x]
        mov     [x2], ax
        jmp     @F
.bRight:
        mov     ax, [x]
        add     ax, BOTTOM_TAIL_WIDTH
        mov     [x2], ax

        mov     ax, [x]
        mov     [x1], ax
        jmp     @F

@@:
        stdcall Figures.Rectangle, [x1], [y1], [x2], [y2], [color]

        ;бепумхи убняр--------------------------------------------------------
        mov     ax, [topTailHeight]
        sub     [y1], ax

        sub     [y2], BOTTOM_TAIL_HEIGHT

        cmp     [direction], 0
        jl      .tRight

.tLeft:
        mov     ax, [x1]
        add     ax, TOP_TAIL_WIDTH
        mov     [x2], ax
        jmp     @F
.tRight:
        mov     ax, [x2]
        sub     ax, TOP_TAIL_WIDTH
        mov     [x1], ax
        jmp     @F

@@:
        stdcall    Figures.Rectangle, [x1], [y1], [x2], [y2], [color]

        ;веьсийх--------------------------------------------------------------
        mov     ax, [y1]
        add     ax, SCALE_SIZE
        mov     [y2], ax

        cmp     [direction], 0
        jl      .sRight

.sLeft:
        mov     ax, [x2]
        sub     ax, SCALE_SIZE  / 2
        mov     [x1], ax

        add     [x2], SCALE_SIZE  / 2
        jmp     @F
.sRight:
        mov     ax, [x1]
        add     ax, SCALE_SIZE  / 2
        mov     [x2], ax

        sub     [x1], SCALE_SIZE  / 2
        jmp     @F

@@:
        stdcall Figures.Circle, [x1], [y1], [x2], [y2], [color]

        add     [y1], SCALE_SIZE
        add     [y2], SCALE_SIZE

        stdcall Figures.Circle, [x1], [y1], [x2], [y2], [color]

        ret
endp