proc Toothless.SideHead\
     x, y, direction, color, eyesColor

        locals
                x1      dw ?
                y1      dw ?
                x2      dw ?
                y2      dw ?
        endl

        ;À»÷Œ-----------------------------------------------------------------
        mov     ax, [y]
        sub     ax, SIDE_FACE_HEIGHT
        mov     [y1], ax

        cmp     [direction], 0
        jg      .fRight

.fLeft:
        mov     ax, [x]
        add     ax, BODY_WIDTH / 2
        mov     [x2], ax

        mov     ax, [x2]
        sub     ax, SIDE_FACE_WIDTH
        mov     [x1], ax
        jmp     @F
.fRight:
        mov     ax, [x]
        sub     ax, BODY_WIDTH / 2
        mov     [x1], ax

        mov     ax, [x1]
        add     ax, SIDE_FACE_WIDTH
        mov     [x2], ax
        jmp     @F

@@:
        stdcall Figures.Rectangle, [x1], [y1], [x2], [y], [color]

        ;”’Œ------------------------------------------------------------------
        mov     ax, [earHeight]
        sub     [y1], ax

        mov     ax, [y]
        sub     ax, SIDE_FACE_HEIGHT
        mov     [y2], ax

        cmp     [direction], 0
        jg      .eRight

.eLeft:
        mov     ax, [x2]
        sub     ax, EAR_WIDTH
        mov     [x1], ax
        jmp     @F
.eRight:
        mov     ax, [x1]
        add     ax, EAR_WIDTH
        mov     [x2], ax
        jmp     @F

@@:
        stdcall Figures.Parabola, [x1], [y1], [x2], [y2], 1, [color]

        ;◊≈ÿ”… »--------------------------------------------------------------
        mov     ax, [y2]
        mov     [y1], ax

        add     [y2], SIDE_FACE_HEIGHT / 2

        cmp     [direction], 0
        jg      .sRight

.sLeft:
        add     [x2], SIDE_FACE_HEIGHT / 4

        mov     ax, [x2]
        sub     ax, SIDE_FACE_HEIGHT / 2
        mov     [x1], ax
        jmp     @F
.sRight:
        sub     [x1], SIDE_FACE_HEIGHT / 4

        mov     ax, [x1]
        add     ax, SIDE_FACE_HEIGHT / 2
        mov     [x2], ax
        jmp     @F

@@:
        stdcall Figures.Circle, [x1], [y1], [x2], [y2], [color]

        add     [y1], SIDE_FACE_HEIGHT / 2

        add     [y2], SIDE_FACE_HEIGHT / 2

        stdcall Figures.Circle, [x1], [y1], [x2], [y2], [color]

        ;√À¿«-----------------------------------------------------------------
        mov     ax, [y]
        sub     ax, SIDE_FACE_HEIGHT
        sub     ax, EYE_SIZE / 2
        mov     [y1], ax

        mov     ax, [y1]
        add     ax, EYE_SIZE
        mov     [y2], ax

        cmp     [direction], 0
        jg      .yRight

.yLeft:
        mov     ax, [x]
        add     ax, BODY_WIDTH / 2
        sub     ax, SIDE_FACE_WIDTH - 2 * EYE_SIZE
        mov     [x2], ax

        mov     ax, [x2]
        sub     ax, EYE_SIZE
        mov     [x1], ax
        jmp     @F
.yRight:
        mov     ax, [x]
        sub     ax, BODY_WIDTH / 2
        add     ax, SIDE_FACE_WIDTH - 2 * EYE_SIZE
        mov     [x1], ax

        mov     ax, [x1]
        add     ax, EYE_SIZE
        mov     [x2], ax
        jmp     @F

@@:
        stdcall Figures.Circle, [x1], [y1], [x2], [y2], [eyesColor]

        ;«–¿◊Œ ---------------------------------------------------------
        add     [x1], EYE_SIZE / 4

        add     [y1], EYE_SIZE / 4

        sub     [x2], EYE_SIZE / 4

        sub     [y2], EYE_SIZE / 4

        stdcall Figures.Circle, [x1], [y1], [x2], [y2], black

        ;ÕŒ—------------------------------------------------------------------
        add    [y1], EYE_SIZE / 4

        add    [y2], NOSE_SIZE - EYE_SIZE / 4

        cmp     [direction], 0
        jg      .nRight

.nLeft:
        sub    [x2], 7 * EYE_SIZE / 4 - NOSE_SIZE / 2

        sub    [x1], 5 * EYE_SIZE / 4 + NOSE_SIZE / 2
        jmp     @F
.nRight:
        add    [x1], 7 * EYE_SIZE / 4 - NOSE_SIZE / 2

        add    [x2], 5 * EYE_SIZE / 4 + NOSE_SIZE / 2
        jmp     @F

@@:
        stdcall    Figures.Circle, [x1], [y1], [x2], [y2], [color]

        ;ÕŒ«ƒ–ﬂ---------------------------------------------------------------
        mov     ax, [direction]
        add     [x1], NOSE_SIZE / 2
        add     [x1], ax

        add     [y1], NOSE_SIZE / 2 - NOSTRIL_HEIGHT / 2

        sub     [y2], NOSE_SIZE / 2 - NOSTRIL_HEIGHT / 2

        stdcall Figures.Rectangle, [x1], [y1], [x1], [y2], black

        ;–Œ“------------------------------------------------------------------
        mov     ax, [y]
        sub     ax, 5
        mov     [y1], ax

        cmp     [direction], 0
        jg      .mRight

.mLeft:
        mov     ax, [x]
        mov     [x2], ax

        mov     ax, [x]
        sub     ax, SIDE_FACE_WIDTH - BODY_WIDTH / 2
        mov     [x1], ax
        jmp     @F
.mRight:
        mov     ax, [x]
        mov     [x1], ax

        mov     ax, [x]
        add     ax, SIDE_FACE_WIDTH - BODY_WIDTH / 2
        mov     [x2], ax
        jmp     @F

@@:
        stdcall Figures.Rectangle, [x1], [y1], [x2], [y1], black

        ret
endp