#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>

char aftertran[100];
struct Node;
typedef struct Node *pNode;
typedef pNode Stack;
struct Node {
	char c;
	pNode next;
};

int Isempty(Stack S) {
	return S->next == NULL;
}

Stack CreateStack(void) {
	Stack S;
	S = (pNode)malloc(sizeof(struct Node));
	if (S == NULL)
		printf("fail to create!");
	S->next = NULL;
	return S;
}

void Push(char c, Stack pnow) {
	pNode p;
	p = (pNode)malloc(sizeof(struct Node));        //ͷ����ǿյ�
	if (p == NULL)
		printf("no space");
	else {
		p->c = c;
		p->next = pnow->next;
		pnow->next = p;
	}

}

char Pop(Stack S) {              //Pop������ջ��Ԫ��
	pNode top;
	char c;
	if (Isempty(S))
		printf("stack is empty");
	else {
		c = S->next->c;
		top = S->next;
		S->next = S->next->next;
		free(top);
	}
	return c;
}

int main() {
	char ori[30];
	char head,temp;
	char str[8] = { 't','s','a','e','d','s','a','e' };
	int i, j, curlen = 0;
	Stack pStack;
	printf("������ħ�����ԣ�\n");
	scanf("%s", ori);
	for (i = 0; ori[i]; i++) {              //��ȡħ�����Բ�ת��
		if (ori[i] == 'B') {
			strcat(aftertran, "tsaedsae");
			curlen += 8;
			continue;
		}
		if (ori[i] == 'A') {
			strcat(aftertran, "sae");
			curlen += 3;
			continue;
		}
		if(ori[i] == '('){
			i++;                            //����������
			head = ori[i++];                //��¼��һ���ַ�
			pStack = CreateStack();
			while (ori[i] != ')') {         //����һ���ַ������ѹ��ջ��
				Push(ori[i], pStack);
				i++;
			}
			while (pStack->next != NULL) {
				temp = Pop(pStack);
				aftertran[curlen++] = head;
				if (temp == 'A') {
					for (j = 1; j < 4; j++) 
						aftertran[curlen++] = str[j];
					continue;
				}
				if (temp == 'B') {
					for (j = 0; j < 8; j++)
						aftertran[curlen++] = str[j];
					continue;
				}
				aftertran[curlen++] = temp;         //���Ǻ����ɶ�pop�˻�p = p->next
			}
			aftertran[curlen] = head;
			free(pStack);                   //�ͷŽڵ�
			continue;
		}
		aftertran[curlen++] = ori[i];
	}
	printf("%s", aftertran);
	return 0;
}