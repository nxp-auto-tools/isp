.org    0x40
start_test:
	//mov  sacc0,0 
	mov  sacc0,0x2800 
	mov  confalu,130 //((1<<1 /* sat*/2) | (4<<4 /*shr*/))
	mov  r17,0x4000
        mov  gpr1,0xffff
        mset 0x1ff
	done jumpback-1,i
	dout sacc0,jumpback,ixo
jumpback:				
	mov  r1,255   # Loop
loop:
        lsr  w,ina,8    # Matrix operation
	add  acc0,w0,w1
//        add  out0,w0,w1
//        sub  out0,out0,loopcnt
//        done next,ixo
//next:
	sub  gpr0,acc0,loopcnt
	and  out0,gpr0,gpr1
	ldon loop,ixo
	//bal  jumpback
end_test:
	halt
