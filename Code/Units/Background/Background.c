proc Background

        stdcall Sky

        stdcall Grass

        stdcall Tree, TREE1_X, TREE1_Y
        stdcall Tree, TREE2_X, TREE2_Y

        stdcall Stone, STONE1_X, STONE1_Y
        stdcall Stone, STONE2_X, STONE2_Y
        stdcall Stone, STONE3_X, STONE3_Y
        stdcall Stone, STONE4_X, STONE4_Y

        stdcall Draw2024, CLOUD_X, CLOUD_Y

        ret
endp

proc Sky

        stdcall Figures.Rectangle, SKY_X1, SKY_Y1, SKY_X2, SKY_Y2, skyColor

        ret
endp

proc Grass

        stdcall Figures.Rectangle, GRASS_X1, GRASS_Y1, GRASS_X2, GRASS_Y2, grassColor

        ret
endp

proc Tree\
     x, y

        locals
                x1      dw ?
                y1      dw ?
                x2      dw ?
                y2      dw ?
        endl

        ;—“¬ŒÀ--------------------------------------------------------------------
        mov     ax, [x]
        sub     ax, TREE_WIDTH / 2
        mov     [x1], ax

        mov     ax, [y]
        sub     ax, TREE_HEIGHT
        mov     [y1], ax

        mov     ax, [x1]
        add     ax, TREE_WIDTH
        mov     [x2], ax

        mov     ax, [y]
        mov     [y2], ax

        stdcall Figures.Rectangle, [x1], [y1], [x2], [y2], treeColor

        ; –ŒÕ¿--------------------------------------------------------------------
        mov     ax, [x]
        sub     ax, LEAVES_SIZE / 2
        mov     [x1], ax

        mov     ax, [y]
        sub     ax, TREE_HEIGHT + LEAVES_SIZE / 2
        mov     [y1], ax

        mov     ax, [x1]
        add     ax, LEAVES_SIZE
        mov     [x2], ax

        mov     ax, [y1]
        add     ax, LEAVES_SIZE
        mov     [y2], ax

        stdcall Figures.Circle, [x1], [y1], [x2], [y2], leavesColor

        ;ﬂ¡ÀŒ »-------------------------------------------------------------------
        add     [x1], LEAVES_SIZE / 2 - APPLE_SIZE

        add     [y1], LEAVES_SIZE / 2

        stdcall B, [x1], [y1]

        ret
endp

proc B\
     x, y

        locals
                x1      dw ?
                y1      dw ?
                x2      dw ?
                y2      dw ?
        endl

        mov     ax, [x]
        sub     ax, APPLE_SIZE / 2
        mov     [x1], ax

        mov     ax, [y]
        sub     ax, APPLE_SIZE * 7 / 2
        mov     [y1], ax

        mov     ax, [x1]
        add     ax, APPLE_SIZE
        mov     [x2], ax

        mov     ax, [y1]
        add     ax, APPLE_SIZE
        mov     [y2], ax

        mov     cx, 5
.LoopA1:
        push    cx

        add     [y1], APPLE_SIZE
        add     [y2], APPLE_SIZE

        stdcall Figures.Circle, [x1], [y1], [x2], [y2], appleColor

        pop     cx
        loop    .LoopA1

        add     [x1], APPLE_SIZE
        add     [x2], APPLE_SIZE

        mov     cx, 3
.LoopB1:
        push    cx

        stdcall Figures.Circle, [x1], [y1], [x2], [y2], appleColor

        sub     [y1], APPLE_SIZE * 2
        sub     [y2], APPLE_SIZE * 2

        pop     cx
        loop    .LoopB1

        add     [x1], APPLE_SIZE
        add     [x2], APPLE_SIZE
        add     [y1], APPLE_SIZE * 3
        add     [y2], APPLE_SIZE * 3

        mov     cx, 2
.LoopC1:
        push    cx

        stdcall Figures.Circle, [x1], [y1], [x2], [y2], appleColor

        add     [y1], APPLE_SIZE * 2
        add     [y2], APPLE_SIZE * 2

        pop     cx
        loop    .LoopC1

        ret
endp

proc Stone\
     x, y

        locals
                x1      dw ?
                y1      dw ?
                x2      dw ?
                y2      dw ?
        endl

        ; ¿Ã≈Õ‹-------------------------------------------------------------------
        mov     ax, [x]
        sub     ax, STONE_WIDTH / 2
        mov     [x1], ax

        mov     ax, [y]
        sub     ax, STONE_HEIGHT / 2
        mov     [y1], ax

        mov     ax, [x1]
        add     ax, STONE_WIDTH
        mov     [x2], ax

        mov     ax, [y1]
        add     ax, STONE_HEIGHT
        mov     [y2], ax

        stdcall Figures.Parabola, [x1], [y1], [x2], [y2], 1, stoneColor

        ;ÃŒ’----------------------------------------------------------------------
        mov     ax, [x]
        sub     ax, MOSS_WIDTH / 2
        mov     [x1], ax

        mov     ax, [x1]
        add     ax, MOSS_WIDTH
        mov     [x2], ax

        mov     ax, [y1]
        add     ax, MOSS_HEIGHT
        mov     [y2], ax

        stdcall Figures.Parabola, [x1], [y1], [x2], [y2], 1, mossColor

        ret
endp

proc DrawCloudLine uses bx,\
     x, y, direction, length

        locals
                x1      dw ?
                y1      dw ?
                x2      dw ?
                y2      dw ?
        endl

        mov     cx, [length]

        mov     ax, [x]
        mov     [x1], ax

        mov     ax, [y]
        mov     [y1], ax

        mov     ax, [x]
        add     ax, CLOUD_SIZE
        mov     [x2], ax

        mov     ax, [y]
        add     ax, CLOUD_SIZE
        mov     [y2], ax

        cmp     [direction], 0
        jl      .DeltaY

.DeltaX:
        mov     ax, CLOUD_SIZE
        xor     dx, dx
        jmp     @F

.DeltaY:
        mov     dx, CLOUD_SIZE
        xor     ax, ax
        jmp     @F

@@:

.Loop:
        push    ax dx cx
        stdcall Figures.Circle, [x1], [y1], [x2], [y2], cloudColor
        pop     cx dx ax

        add     [x1], ax
        add     [x2], ax
        add     [y1], dx
        add     [y2], dx

        loop    .Loop

        ret
endp

proc Draw2\
     x, y

        stdcall DrawCloudLine, [x], [y], 1, 2

        add     [x], CLOUD_SIZE * 2

        stdcall DrawCloudLine, [x], [y], -1, 2

        sub     [x], CLOUD_SIZE * 2
        add     [y], CLOUD_SIZE * 2

        stdcall DrawCloudLine, [x], [y], 1, 3

        stdcall DrawCloudLine, [x], [y], -1, 2

        add     [y], CLOUD_SIZE * 2

        stdcall DrawCloudLine, [x], [y], 1, 3

        ret
endp

proc Draw0\
     x, y

        stdcall DrawCloudLine, [x], [y], 1, 2

        add     [x], CLOUD_SIZE * 2

        stdcall DrawCloudLine, [x], [y], -1, 4

        sub     [x], CLOUD_SIZE * 2

        stdcall DrawCloudLine, [x], [y], -1, 4

        add     [y], CLOUD_SIZE * 4

        stdcall DrawCloudLine, [x], [y], 1, 3

        ret
endp

proc Draw4\
     x, y

        stdcall DrawCloudLine, [x], [y], -1, 2

        add     [y], CLOUD_SIZE * 2

        stdcall DrawCloudLine, [x], [y], 1, 2

        add     [x], CLOUD_SIZE * 2
        sub     [y], CLOUD_SIZE * 2

        stdcall DrawCloudLine, [x], [y], -1, 5

        ret
endp

proc Draw2024\
     x, y

        stdcall Draw2, [x], [y]

        add     [x], CLOUD_SIZE * 4

        stdcall Draw0, [x], [y]

        add     [x], CLOUD_SIZE * 4

        stdcall Draw2, [x], [y]

        add     [x], CLOUD_SIZE * 4

        stdcall Draw4, [x], [y]

        ret
endp