.org    0x0
start_test:
	mov  sacc0,0 
	mov  confalu,(0 /* unsigned*/ | (1 << 1) /* saturate*/ | (4<<4) /* shr =4*/ ) 
	mov  r17,0x4000
	done jumpback-1,i
	done jumpback,ix
jumpback:				
	mov  loopcnt,5   # Loop
loop:
	add  r16,r16,r17
	sub  r70,r16,r17
	mov  r64,r16     # out
	ldon loop,ixo
	bal  jumpback
end_test:
 	halt
