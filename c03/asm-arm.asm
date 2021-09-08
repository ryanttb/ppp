
asm-arm:     file format elf32-littlearm


Disassembly of section .init:

0001029c <_init>:
   1029c:	e92d4008 	push	{r3, lr}
   102a0:	eb00001d 	bl	1031c <call_weak_fn>
   102a4:	e8bd8008 	pop	{r3, pc}

Disassembly of section .plt:

000102a8 <.plt>:
   102a8:	e52de004 	push	{lr}		; (str lr, [sp, #-4]!)
   102ac:	e59fe004 	ldr	lr, [pc, #4]	; 102b8 <.plt+0x10>
   102b0:	e08fe00e 	add	lr, pc, lr
   102b4:	e5bef008 	ldr	pc, [lr, #8]!
   102b8:	00010d48 	.word	0x00010d48

000102bc <__libc_start_main@plt>:
   102bc:	e28fc600 	add	ip, pc, #0, 12
   102c0:	e28cca10 	add	ip, ip, #16, 20	; 0x10000
   102c4:	e5bcfd48 	ldr	pc, [ip, #3400]!	; 0xd48

000102c8 <__gmon_start__@plt>:
   102c8:	e28fc600 	add	ip, pc, #0, 12
   102cc:	e28cca10 	add	ip, ip, #16, 20	; 0x10000
   102d0:	e5bcfd40 	ldr	pc, [ip, #3392]!	; 0xd40

000102d4 <abort@plt>:
   102d4:	e28fc600 	add	ip, pc, #0, 12
   102d8:	e28cca10 	add	ip, ip, #16, 20	; 0x10000
   102dc:	e5bcfd38 	ldr	pc, [ip, #3384]!	; 0xd38

Disassembly of section .text:

000102e0 <_start>:
   102e0:	e3a0b000 	mov	fp, #0
   102e4:	e3a0e000 	mov	lr, #0
   102e8:	e49d1004 	pop	{r1}		; (ldr r1, [sp], #4)
   102ec:	e1a0200d 	mov	r2, sp
   102f0:	e52d2004 	push	{r2}		; (str r2, [sp, #-4]!)
   102f4:	e52d0004 	push	{r0}		; (str r0, [sp, #-4]!)
   102f8:	e59fc010 	ldr	ip, [pc, #16]	; 10310 <_start+0x30>
   102fc:	e52dc004 	push	{ip}		; (str ip, [sp, #-4]!)
   10300:	e59f000c 	ldr	r0, [pc, #12]	; 10314 <_start+0x34>
   10304:	e59f300c 	ldr	r3, [pc, #12]	; 10318 <_start+0x38>
   10308:	ebffffeb 	bl	102bc <__libc_start_main@plt>
   1030c:	ebfffff0 	bl	102d4 <abort@plt>
   10310:	00010450 	.word	0x00010450
   10314:	000103d0 	.word	0x000103d0
   10318:	000103ec 	.word	0x000103ec

0001031c <call_weak_fn>:
   1031c:	e59f3014 	ldr	r3, [pc, #20]	; 10338 <call_weak_fn+0x1c>
   10320:	e59f2014 	ldr	r2, [pc, #20]	; 1033c <call_weak_fn+0x20>
   10324:	e08f3003 	add	r3, pc, r3
   10328:	e7932002 	ldr	r2, [r3, r2]
   1032c:	e3520000 	cmp	r2, #0
   10330:	012fff1e 	bxeq	lr
   10334:	eaffffe3 	b	102c8 <__gmon_start__@plt>
   10338:	00010cd4 	.word	0x00010cd4
   1033c:	00000018 	.word	0x00000018

00010340 <deregister_tm_clones>:
   10340:	e59f0018 	ldr	r0, [pc, #24]	; 10360 <deregister_tm_clones+0x20>
   10344:	e59f3018 	ldr	r3, [pc, #24]	; 10364 <deregister_tm_clones+0x24>
   10348:	e1530000 	cmp	r3, r0
   1034c:	012fff1e 	bxeq	lr
   10350:	e59f3010 	ldr	r3, [pc, #16]	; 10368 <deregister_tm_clones+0x28>
   10354:	e3530000 	cmp	r3, #0
   10358:	012fff1e 	bxeq	lr
   1035c:	e12fff13 	bx	r3
   10360:	00021024 	.word	0x00021024
   10364:	00021024 	.word	0x00021024
   10368:	00000000 	.word	0x00000000

0001036c <register_tm_clones>:
   1036c:	e59f0024 	ldr	r0, [pc, #36]	; 10398 <register_tm_clones+0x2c>
   10370:	e59f1024 	ldr	r1, [pc, #36]	; 1039c <register_tm_clones+0x30>
   10374:	e0413000 	sub	r3, r1, r0
   10378:	e1a01fa3 	lsr	r1, r3, #31
   1037c:	e0811143 	add	r1, r1, r3, asr #2
   10380:	e1b010c1 	asrs	r1, r1, #1
   10384:	012fff1e 	bxeq	lr
   10388:	e59f3010 	ldr	r3, [pc, #16]	; 103a0 <register_tm_clones+0x34>
   1038c:	e3530000 	cmp	r3, #0
   10390:	012fff1e 	bxeq	lr
   10394:	e12fff13 	bx	r3
   10398:	00021024 	.word	0x00021024
   1039c:	00021024 	.word	0x00021024
   103a0:	00000000 	.word	0x00000000

000103a4 <__do_global_dtors_aux>:
   103a4:	e92d4010 	push	{r4, lr}
   103a8:	e59f4018 	ldr	r4, [pc, #24]	; 103c8 <__do_global_dtors_aux+0x24>
   103ac:	e5d43000 	ldrb	r3, [r4]
   103b0:	e3530000 	cmp	r3, #0
   103b4:	18bd8010 	popne	{r4, pc}
   103b8:	ebffffe0 	bl	10340 <deregister_tm_clones>
   103bc:	e3a03001 	mov	r3, #1
   103c0:	e5c43000 	strb	r3, [r4]
   103c4:	e8bd8010 	pop	{r4, pc}
   103c8:	00021024 	.word	0x00021024

000103cc <frame_dummy>:
   103cc:	eaffffe6 	b	1036c <register_tm_clones>

000103d0 <main>:
   103d0:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
   103d4:	e28db000 	add	fp, sp, #0
   103d8:	e3a03000 	mov	r3, #0
   103dc:	e1a00003 	mov	r0, r3
   103e0:	e28bd000 	add	sp, fp, #0
   103e4:	e49db004 	pop	{fp}		; (ldr fp, [sp], #4)
   103e8:	e12fff1e 	bx	lr

000103ec <__libc_csu_init>:
   103ec:	e92d47f0 	push	{r4, r5, r6, r7, r8, r9, sl, lr}
   103f0:	e1a07000 	mov	r7, r0
   103f4:	e59f604c 	ldr	r6, [pc, #76]	; 10448 <__libc_csu_init+0x5c>
   103f8:	e59f504c 	ldr	r5, [pc, #76]	; 1044c <__libc_csu_init+0x60>
   103fc:	e1a08001 	mov	r8, r1
   10400:	e08f6006 	add	r6, pc, r6
   10404:	e1a09002 	mov	r9, r2
   10408:	e08f5005 	add	r5, pc, r5
   1040c:	ebffffa2 	bl	1029c <_init>
   10410:	e0466005 	sub	r6, r6, r5
   10414:	e1b06146 	asrs	r6, r6, #2
   10418:	08bd87f0 	popeq	{r4, r5, r6, r7, r8, r9, sl, pc}
   1041c:	e2455004 	sub	r5, r5, #4
   10420:	e3a04000 	mov	r4, #0
   10424:	e5b53004 	ldr	r3, [r5, #4]!
   10428:	e1a02009 	mov	r2, r9
   1042c:	e1a01008 	mov	r1, r8
   10430:	e1a00007 	mov	r0, r7
   10434:	e2844001 	add	r4, r4, #1
   10438:	e12fff33 	blx	r3
   1043c:	e1560004 	cmp	r6, r4
   10440:	1afffff7 	bne	10424 <__libc_csu_init+0x38>
   10444:	e8bd87f0 	pop	{r4, r5, r6, r7, r8, r9, sl, pc}
   10448:	00010b04 	.word	0x00010b04
   1044c:	00010af8 	.word	0x00010af8

00010450 <__libc_csu_fini>:
   10450:	e12fff1e 	bx	lr

Disassembly of section .fini:

00010454 <_fini>:
   10454:	e92d4008 	push	{r3, lr}
   10458:	e8bd8008 	pop	{r3, pc}
