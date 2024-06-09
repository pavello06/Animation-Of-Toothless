proc Keyboard.ReadKey

     	xor        dx, dx
     	mov        ax, $0C08
     	int        21h
     	add        dl, al
     	jnz        @F
     	mov        ah, $08
     	int        21h
     	mov        dh, al
@@:
     	xchg       ax, dx

     	ret
endp