include 'Units/Units.h'

        org 100h

EntryPoint:
        stdcall Screen.SetMode, $13
        push    ax

        ;------------------------------------------------------------------------------------
        mov     dx, $331
        mov     al, $FF
        out     dx, al
        mov     al, $3F
        out     dx, al
        mov     al, $C0
        out     dx, al
        mov     al, $00
        out     dx, al

        stdcall SetIntVector, $1C, cs, timer
        mov     word [oldTimer], ax
        mov     word [oldTimer + 2], dx

.AnimationLoop:
        stdcall Keyboard.ReadKey
        cmp     ax, KEY_ESCAPE
        jne     .AnimationLoop

        stdcall SetIntVector, $1C, word [oldTimer + 2], word [oldTimer]
        ;------------------------------------------------------------------------------------

        stdcall Screen.SetMode

        ret

include 'Units/Units.c'

include 'Units/Units.id'

include 'Units/Units.ud'