include 'FrontHead\FrontHead.c'
include 'SideHead\SideHead.c'

proc Toothless.Head\
     x, y, direction, color, eyesColor

        cmp     [direction], 0
        jnz     .SideHead

.FrontHead:
        add     [y], FRONT_HEAD_OFFSET
        stdcall Toothless.FrontHead, [x], [y], [color], [eyesColor]
        jmp     .Exit
.SideHead:
        add     [y], SIDE_HEAD_OFFSET
        stdcall Toothless.SideHead, [x], [y], [direction], [color], [eyesColor]
        jmp     .Exit

.Exit:
        ret
endp