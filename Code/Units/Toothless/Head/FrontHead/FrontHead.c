proc Toothless.FrontHead\
     x, y, color, eyesColor

        locals
                x1      dw ?
                y1      dw ?
                x2      dw ?
                y2      dw ?
        endl

        ;ФОН------------------------------------------------------------------
        mov     ax, [x]
        sub     ax, FRONT_FACE_WIDTH / 2
        mov     [x1], ax

        mov     ax, [y]
        sub     ax, FRONT_FACE_HEIGHT
        mov     [y1], ax

        mov     ax, [x1]
        add     ax, FRONT_FACE_WIDTH
        mov     [x2], ax

        mov     ax, [y]
        mov     [y2], ax

        stdcall Figures.Parabola, [x1], [y1], [x2], [y2], -1, black

        ;ЛИЦО-----------------------------------------------------------------
        inc     [x1]

        dec     [x2]

        dec     [y2]

        stdcall Figures.Parabola, [x1], [y1], [x2], [y2], -1, [color]

        ;УХО------------------------------------------------------------------

        ;левое----------------------------------------------------------------
        mov     ax, [earHeight]
        sub     [y1], ax

        mov     ax, [x1]
        add     ax, FRONT_FACE_WIDTH / 4
        mov     [x2], ax

        mov     ax, [y]
        sub     ax, FRONT_FACE_HEIGHT
        mov     [y2], ax

        stdcall Figures.Parabola, [x1], [y1], [x2], [y2], 1, [color]

        ;ЧЕШУЙКА--------------------------------------------------------------

        ;левая----------------------------------------------------------------
        mov     ax, [x2]
        mov     [x1], ax

        mov     ax, [y2]
        mov     dx, [earHeight]
        shr     dx, 1
        sub     ax, dx
        mov     [y1], ax

        mov     ax, [x]
        mov     [x2], ax

        stdcall Figures.Parabola, [x1], [y1], [x2], [y2], 1, [color]

        ;ГЛАЗ-----------------------------------------------------------------

        ;левый----------------------------------------------------------------
        mov     ax, [x]
        sub     ax, FRONT_FACE_WIDTH / 4
        sub     ax, EYE_SIZE
        mov     [x1], ax

        mov     ax, [y]
        sub     ax, FRONT_FACE_HEIGHT / 2
        mov     [y1], ax

        mov     ax, [x1]
        add     ax, EYE_SIZE
        mov     [x2], ax

        mov     ax, [y1]
        add     ax, EYE_SIZE
        mov     [y2], ax

        stdcall Figures.Circle, [x1], [y1], [x2], [y2], [eyesColor]

        ;ЗРАЧОК---------------------------------------------------------------

        ;левый----------------------------------------------------------------
        add     [x1], EYE_SIZE / 4

        add     [y1], EYE_SIZE / 4

        sub     [x2], EYE_SIZE / 4

        sub     [y2], EYE_SIZE / 4

        stdcall Figures.Circle, [x1], [y1], [x2], [y2], black

        ;НОЗДРЯ---------------------------------------------------------------

        ;левая----------------------------------------------------------------
        mov     ax, [x]
        dec     ax
        mov     [x1], ax

        mov     ax, [y]
        sub     ax, FRONT_FACE_HEIGHT / 2
        add     ax, EYE_SIZE
        mov     [y1], ax

        mov     ax, [x1]
        mov     [x2], ax

        mov     ax, [y1]
        add     ax, NOSTRIL_HEIGHT
        mov     [y2], ax

        stdcall Figures.Rectangle, [x1], [y1], [x2], [y2], black

        ;ПРАВАЯ СТОРОНА-------------------------------------------------------
        mov     ax, [x]
        sub     ax, FRONT_FACE_WIDTH / 2
        mov     [x1], ax

        mov     ax, [y]
        sub     ax, FRONT_FACE_HEIGHT
        sub     ax, [earHeight]
        mov     [y1], ax

        mov     ax, [x1]
        add     ax, FRONT_FACE_WIDTH
        mov     [x2], ax

        mov     ax, [y]
        sub     ax, FRONT_FACE_HEIGHT / 2 - (EYE_SIZE + NOSTRIL_HEIGHT + 1)
        mov     [y2], ax

        stdcall FrontHead.Copy

        ret
endp

proc FrontHead.Copy uses es di,\
     x1, y1, x2, y2

        locals
                x      dw ?
                y      dw ?
        endl

        mov     ax, cs
        add     ax, 1000h
        mov     es, ax

        ;устанавливаем начальные координаты для копирования
        mov     ax, [x1]
        mov     [x], ax

        mov     ax, [y1]
        mov     [y], ax

        ;рассчитываем число повторений
        mov     ax, [y2]
        sub     ax, [y1]
        inc     ax
        mov     cx, [x2]
        sub     cx, [x1]
        inc     cx
        imul    cx, ax
        shr     cx, 1

.Loop:
        mov     di, [y]
        imul    di, 320
        add     di, [x]

        mov     al, [es:di]

        mov     dx, [x1]
        add     dx, [x2]
        sub     dx, [x]

        sub     di, [x]
        add     di, dx

        mov     [es:di], al

        mov     ax, [x1]
        add     ax, [x2]
        shr     ax, 1
        cmp     [x], ax
        je      .IncY

.IncX:
        inc     [x]

        jmp     @F
.IncY:
        inc     [y]

        mov     ax, [x1]
        mov     [x], ax
        jmp     @F

@@:
        loop    .Loop

        ret
endp