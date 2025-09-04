	.global sim_print

#define PRINT_PORT 0xC0037FFC

sim_print:
	ldr     x1, =PRINT_PORT
	mov	w3, #0
1:
	ldrb    w2, [x0], #0x1
	str     w2, [x1]
	cmp	w3, w2
	//b.eq  0f
	//mov	w1, #'\n'
	//cmp	w1, w2
	//b.ne    sim_print
	//b.eq    0f
	b.ne    1b //sim_print
0:
	ret 
