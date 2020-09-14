	.ORIG	x3000
	LD	R0,SIXTY           ;外层循环,R0 <- i   
OUTER	LD	R7,DATA
	AND	R1,R1,#0
INNER	ADD	R1,R1,#1           ;内层循环,R1 <- j ,from 1 to 60 
	ADD	R5,R1,R7
	LDR	R2,R5,#0           ;R2 <- data[j-1]
	LDR	R3,R5,#1           ;R3 <- data[j]
	BR	BUBBLE		   ;冒泡
BUBEND	NOT	R4,R1              ;比较是否达到循环停止条件：j = i
	ADD	R4,R4,#1
	ADD	R4,R4,R0
	BRp	INNER
	ADD	R0,R0,#-1
	BRp	OUTER
	BR	RESTORE            ;冒泡结束，存储数据
RESEND	BR	COUNTA
AEND	BR	COUNTB
BEND	BR	COUNTC
CEND	NOT	R0,R0
	ADD	R0,R0,#1
	LD	R1,SIXTY
	ADD	R0,R0,R1	   ;D数量
	LD	R1,ADDD
	STR	R0,R1,#0	   ;存储D数量
	TRAP	x25

BUBBLE	NOT	R4,R3           ;if R2 < R3 : swap
	ADD	R4,R4,#1
	ADD	R4,R4,R2
	BRp	SKIP
	ADD	R6,R1,R7
	STR	R3,R6,#0
	STR	R2,R6,#1
SKIP	BR	BUBEND

RESTORE	LD	R0,SIXTY        ;将排序完的成绩存放进目标地址
	LD	R2,STORE
LOOP	ADD	R1,R0,R2	;从顺序转换为目标地址值
	ADD	R3,R0,R7	;原地址值
	LDR	R4,R3,#0
	STR	R4,R1,#0
	ADD	R0,R0,#-1
	BRp	LOOP
	BR	RESEND

COUNTA	AND	R1,R1,#0
	LD	R0,EIGHTY
	ADD	R1,R1,R0        ;便于循环，初始值多设1,R1存放A学生数量
	LD	R2,LINEA
	ADD	R1,R1,R7	;r7为地址基址
LOOP1	ADD	R1,R1,#-1
	LDR	R3,R1,#0	;R3用于存放当前学生成绩
	NOT	R2,R2
	ADD	R2,R2,#1	;R2是-85
	ADD	R3,R3,R2
	BRn	LOOP1	
	NOT	R3,R7
	ADD	R3,R3,#1
	ADD	R1,R1,R3
	LD	R3,ADDA
	STR	R1,R3,#0
	BR	AEND

COUNTB	AND	R2,R2,#0
	LD	R0,THRTY
	ADD	R2,R2,R0
	LD	R3,LINEB
	ADD	R2,R2,R7	;对r2赋地址值
LOOP2	ADD	R2,R2,#-1
	LDR	R4,R2,#0
	NOT	R3,R3
	ADD	R3,R3,#1	;r3存-75
	ADD	R4,R4,R3
	BRn	LOOP2
	NOT	R5,R7
	ADD	R5,R5,#1
	ADD	R2,R2,R5
	NOT	R1,R1           ;满足B的学生减去已经是A的学生数
	ADD	R1,R1,#1
	ADD	R0,R2,R1	;R0是B学生数量
	LD	R1,ADDB
	STR	R0,R1,#0	;R2是AB之和
	BR	BEND

COUNTC	LD	R0,SIXTY
	NOT	R5,R0		;R5中存放-60
	ADD	R5,R5,#1
	ADD	R6,R2,#0	;存放AB总数
	ADD	R1,R0,#0	;R1 = 60
LOOP3	ADD	R3,R0,R7	;R3是倒着数该学生地址
	LDR	R4,R3,#0	;R4存放该学生成绩
	ADD	R0,R0,#-1	;计数器-1，此时R0为ABC学生数量+1
	ADD	R4,R4,R5
	BRn	LOOP3
	ADD	R1,R1,#-1
	NOT	R6,R6
	ADD	R6,R6,#1
	ADD	R6,R0,R6	;R6 <- C，R0是ABC总数
	LD	R1,ADDC
	STR	R6,R1,#0	;为什么直接用ST不行？？？？
	BR	CEND
	
	SIXTY	.FILL	#60
	DATA	.FILL	x31FF           ;起始地址-1
	STORE	.FILL	x3FFF		;目标地址-1
	LINEA	.FILL	#85
	LINEB	.FILL	#75
	EIGHTY	.FILL	#18
	THRTY	.FILL	#30
	ADDA	.FILL	x4100
	ADDB	.FILL	x4101
	ADDC	.FILL	x4102
	ADDD	.FILL	x4103
	.END	