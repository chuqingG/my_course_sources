#include<stdio.h>
#include<stdlib.h>
struct List
{
    int num;
    int score;
    struct List *next;
};
typedef struct List NODE;

NODE *Create_List()
{
    NODE *head,*tail,*pnew;
    int num;
    int score;
    int i;
    head=(NODE *)malloc(sizeof(NODE));
    if(head==NULL)
    {
        printf("no enough memory\n");
        return(NULL);
    }
    head->next=NULL;
    tail=head;
    for(i=1;;i++)
    {
        printf("student%d's num:",i);
        scanf("%d",&num);
        if(num<0)
            break;
        printf("student%d's score:",i);
        scanf("%d",&score);
        pnew=(NODE *)malloc(sizeof(NODE));
        if(pnew==NULL)
        {
            printf("no enough memory\n");
            return(NULL);
        }
        pnew->num=num;
        pnew->score=score;
        pnew->next=NULL;
        tail->next=pnew;
        tail=pnew;
    }
    return(head);
}

void Insert_List(NODE *head,NODE *pnew,int t)
{
    NODE *p;
    int j;
    p=head;
    for(j=0;j<t&&p!=NULL;j++)
        p=p->next;
    if(p==NULL)
    {
        printf("the %d node not found\n");
        return;
    }
    pnew->next=p->next;
    p->next=pnew;
}

void Free_List(NODE *head)
{
    NODE *p,*q;
    p=head;
    while(p->next!=NULL)
    {
        q=p->next;
        p->next=q->next;
        free(q);
    }
    free(head);
}

void Display_List(NODE *head)
{
    NODE *p;
    p=head;
    printf("num\tscore\n");
    while(p->next!=NULL)
    {
        p=p->next;
        printf("%d\t%d\n",p->num,p->score);
    }
}

void Combine_List(NODE *head_a,NODE *head_b)
{
    NODE *p;
    p=head_a;
    while(p->next!=NULL)
        p=p->next;
    p->next=head_b->next;
    free(head_b);
}

void Sort_List(NODE *head)
{
    NODE *p,*q;
    int i=1,num,score;
    p=head;
    while(i)
    {
        p=p->next;
        if(p->next==NULL)
            break;
        q=p;
        while(i)
        {
            q=q->next;
            if(q==NULL)
                break;
            else if((q->num)<(p->num))
            {
                num=p->num;
                p->num=q->num;
                q->num=num;
                score=p->score;
                p->score=q->score;
                q->score=score;
            }
        }
    }
}

void main()
{
    NODE *head_a,*head_b;
    printf("List_a:\n");
    head_a=Create_List();
    if(head_a==NULL)
    {
        printf("no enough memory\n");
        return;
    }
    printf("List_b:\n");
    head_b=Create_List();
    if(head_b==NULL)
    {
        printf("no enough memory\n");
        return;
    }
    printf("List_a:\n");
    Display_List(head_a);
    printf("List_b:\n");
    Display_List(head_b);
    Combine_List(head_a,head_b);
    printf("After Combine:\n");
    Display_List(head_a);
    Sort_List(head_a);
    printf("After Sort:\n");
    Display_List(head_a);
    Free_List(head_a);
}
