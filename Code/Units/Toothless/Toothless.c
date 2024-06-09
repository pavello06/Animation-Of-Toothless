include 'Arms\Arms.c'
include 'Legs\Legs.c'
include 'Body\Body.c'
include 'Head\Head.c'
include 'Tail\Tail.c'

proc Toothless\
     x, y, direction, color, eyesColor, colorShadow

     ;–” »-----------------------------------------------------------------
     stdcall Toothless.Arms, [x], [y], [direction], [color], [colorShadow]

     ;ÕŒ√»-----------------------------------------------------------------
     mov     ax, [y]
     mov     dx, BODY_HEIGHT
     shr     dx, 1
     add     ax, dx
     sub     ax, LEGS_OFFSET

     stdcall Toothless.Legs, [x], ax, [direction], [color], [colorShadow]

     ;“≈ÀŒ-----------------------------------------------------------------
     stdcall Toothless.Body, [x], [y], [direction], [color], [colorShadow]

     ;√ŒÀŒ¬¿---------------------------------------------------------------
     mov     ax, [y]
     mov     dx, BODY_HEIGHT
     shr     dx, 1
     sub     ax, dx

     stdcall Toothless.Head, [x], ax, [direction], [color], [eyesColor]

     ;’¬Œ—“----------------------------------------------------------------
     mov     ax, [y]
     mov     dx, BODY_HEIGHT
     shr     dx, 1
     add     ax, dx
     sub     ax, TAIL_OFFSET

     stdcall Toothless.Tail, [x], ax, [direction], [color]

     ret
endp