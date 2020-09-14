	.ORIG	x3000
	LD	R0,SIXTY           ;���ѭ��,R0 <- i   
OUTER	LD	R7,DATA
	AND	R1,R1,#0
INNER	ADD	R1,R1,#1           ;�ڲ�ѭ��,R1 <- j ,from 1 to 60 
	ADD	R5,R1,R7
	LDR	R2,R5,#0           ;R2 <- data[j-1]
	LDR	R3,R5,#1           ;R3 <- data[j]
	BR	BUBBLE		   ;ð��
BUBEND	NOT	R4,R1              ;�Ƚ��Ƿ�ﵽѭ��ֹͣ������j = i
	ADD	R4,R4,#1
	ADD	R4,R4,R0
	BRp	INNER
	ADD	R0,R0,#-1
	BRp	OUTER
	BR	RESTORE            ;ð�ݽ������洢����
RESEND	BR	COUNTA
AEND	BR	COUNTB
BEND	BR	COUNTC
CEND	NOT	R0,R0
	ADD	R0,R0,#1
	LD	R1,SIXTY
	ADD	R0,R0,R1	   ;D����
	LD	R1,ADDD
	STR	R0,R1,#0	   ;�洢D����
	TRAP	x25

BUBBLE	NOT	R4,R3           ;if R2 < R3 : swap
	ADD	R4,R4,#1
	ADD	R4,R4,R2
	BRp	SKIP
	ADD	R6,R1,R7
	STR	R3,R6,#0
	STR	R2,R6,#1
SKIP	BR	BUBEND

RESTORE	LD	R0,SIXTY        ;��������ĳɼ���Ž�Ŀ���ַ
	LD	R2,STORE
LOOP	ADD	R1,R0,R2	;��˳��ת��ΪĿ���ֵַ
	ADD	R3,R0,R7	;ԭ��ֵַ
	LDR	R4,R3,#0
	STR	R4,R1,#0
	ADD	R0,R0,#-1
	BRp	LOOP
	BR	RESEND

COUNTA	AND	R1,R1,#0
	LD	R0,EIGHTY
	ADD	R1,R1,R0        ;����ѭ������ʼֵ����1,R1���Aѧ������
	LD	R2,LINEA
	ADD	R1,R1,R7	;r7Ϊ��ַ��ַ
LOOP1	ADD	R1,R1,#-1
	LDR	R3,R1,#0	;R3���ڴ�ŵ�ǰѧ���ɼ�
	NOT	R2,R2
	ADD	R2,R2,#1	;R2��-85
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
	ADD	R2,R2,R7	;��r2����ֵַ
LOOP2	ADD	R2,R2,#-1
	LDR	R4,R2,#0
	NOT	R3,R3
	ADD	R3,R3,#1	;r3��-75
	ADD	R4,R4,R3
	BRn	LOOP2
	NOT	R5,R7
	ADD	R5,R5,#1
	ADD	R2,R2,R5
	NOT	R1,R1           ;����B��ѧ����ȥ�Ѿ���A��ѧ����
	ADD	R1,R1,#1
	ADD	R0,R2,R1	;R0��Bѧ������
	LD	R1,ADDB
	STR	R0,R1,#0	;R2��AB֮��
	BR	BEND

COUNTC	LD	R0,SIXTY
	NOT	R5,R0		;R5�д��-60
	ADD	R5,R5,#1
	ADD	R6,R2,#0	;���AB����
	ADD	R1,R0,#0	;R1 = 60
LOOP3	ADD	R3,R0,R7	;R3�ǵ�������ѧ����ַ
	LDR	R4,R3,#0	;R4��Ÿ�ѧ���ɼ�
	ADD	R0,R0,#-1	;������-1����ʱR0ΪABCѧ������+1
	ADD	R4,R4,R5
	BRn	LOOP3
	ADD	R1,R1,#-1
	NOT	R6,R6
	ADD	R6,R6,#1
	ADD	R6,R0,R6	;R6 <- C��R0��ABC����
	LD	R1,ADDC
	STR	R6,R1,#0	;Ϊʲôֱ����ST���У�������
	BR	CEND
	
	SIXTY	.FILL	#60
	DATA	.FILL	x31FF           ;��ʼ��ַ-1
	STORE	.FILL	x3FFF		;Ŀ���ַ-1
	LINEA	.FILL	#85
	LINEB	.FILL	#75
	EIGHTY	.FILL	#18
	THRTY	.FILL	#30
	ADDA	.FILL	x4100
	ADDB	.FILL	x4101
	ADDC	.FILL	x4102
	ADDD	.FILL	x4103
	.END	