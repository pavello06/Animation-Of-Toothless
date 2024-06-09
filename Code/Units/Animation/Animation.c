proc Animation

        stdcall Background
        stdcall Toothless, [positionX], [positionY], [absoluteDirection], gray, orange, darkGray
        stdcall Bird, 3, [birdPositionY], bird1
        stdcall Bird, 300, [birdPositionY], bird2
        stdcall Screen.Copy

        cmp     [positionX], MIN_POSITION_X
        je      .Right
        cmp     [positionX], MAX_POSITION_X
        je      .Left

        mov     [centerCounter], MAX_CENTER_COUNTER
        jmp     @F

.Left:
        mov     [absoluteDirection], 0
        dec     [centerCounter]
        cmp     [centerCounter], MIN_CENTER_COUNTER
        jg      @F

        mov     [absoluteDirection], -1
        jmp     @F

.Right:
        mov     [absoluteDirection], 0
        dec     [centerCounter]
        cmp     [centerCounter], MIN_CENTER_COUNTER
        jg      @F

        mov     [absoluteDirection], 1
        jmp     @F

@@:
        ;------------------------------------------------------------------------------------
        mov     ax, [deltaPositionX]
        imul    ax, [absoluteDirection]
        add     [positionX], ax

        mov     ax, [deltaPositionY]
        add     [positionY], ax
        stdcall ChangeDelta, [positionY], deltaPositionY, MIN_POSITION_Y, MAX_POSITION_Y

        mov     ax, [deltaArmsHeight]
        add     [armsHeight], ax
        stdcall ChangeDelta, [armsHeight], deltaArmsHeight, MIN_ARMS_HEIGHT, MAX_ARMS_HEIGHT

        mov     ax, [deltaLegsHeight]
        add     [legsHeight], ax
        stdcall ChangeDelta, [legsHeight], deltaLegsHeight, MIN_LEGS_HEIGHT, MAX_LEGS_HEIGHT

        mov     ax, [deltaEarHeight]
        add     [earHeight], ax
        stdcall ChangeDelta, [earHeight], deltaEarHeight, MIN_EAR_HEIGHT, MAX_EAR_HEIGHT

        mov     ax, [deltaTopTailHeight]
        add     [topTailHeight], ax
        stdcall ChangeDelta, [topTailHeight], deltaTopTailHeight, MIN_TOP_TAIL_HEIGHT, MAX_TOP_TAIL_HEIGHT
        ;------------------------------------------------------------------------------------

        mov     ax, [deltaBirdPositionY]
        add     [birdPositionY], ax
        imul    ax, -1
        mov     [deltaBirdPositionY], ax

        ret
endp

proc ChangeDelta\
     param, delta, min, max

        mov     ax, [param]
        sub     ax, [min]
        mov     dx, [param]
        sub     dx, [max]
        imul    ax, dx
        cmp     ax, 0
        jl      .Exit

        mov     bx, [delta]
        neg     word [bx]

.Exit:
        ret
endp