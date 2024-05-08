@	.thumb
	.syntax unified
	.section .text
	@df04
	str r0, [r4, # 8]
	str r3, [r4, # 8]

	
	@df84
aa:
	b aa
	mov r0, r0

	
	@e6b0
bb:
	b bb
	mov r0, r0

	
	@dffa
	str r4, [r7, # 0x818]
	str r2, [r7, # 0x818]
	
	@de86
	str r0, [r3]
	str r2, [r3]
	
	@ddac
	str r0, [r4]
	ldr r3, [r3]
	
	@ddae
	ldr r3, [r3]
	str r3, [r4]

	@dec6
	str r0, [r3, # 4]
	str r2, [r3, # 4]

	@de16
	ldr r0, [r3, # 8]
	str r2, [r3, # 8]
	
	@de18
	cmp r0, r2
	cmp r2, r2

	
