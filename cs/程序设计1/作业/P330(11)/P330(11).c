#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct List
{
    int num;
    char name[10];
    struct List *next;
};
typedef struct List NODE;

NODE *Create_List()
{
    NODE *head,*tail,*pnew;
    int num,i;
    char name[10];
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
        printf("student%d's name:",i);
        scanf("%s",name);
        pnew=(NODE *)malloc(sizeof(NODE));
        if(pnew==NULL)
        {
            printf("no enough memory\n");
            return(NULL);
        }
        pnew->num=num;
        strcpy(pnew->name,name);
        pnew->next=NULL;
        tail->next=pnew;
        tail=pnew;
    }
    return(head);
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
    printf("num\tname\n");
    while(p->next!=NULL)
    {
        p=p->next;
        printf("%d\t%s\n",p->num,p->name);
    }
}

void Clear_List(NODE *head_a,NODE *head_b)
{
    NODE *p,*q,*p_;
    q=head_b;
    while(q->next!=NULL)
    {
        q=q->next;
        p=head_a;
        p_=head_a;
        while(p->next!=NULL)
        {
            p=p->next;
            if((p->num)==(q->num))
            {
                p_->next=p->next;
                free(p);
                break;
            }
            p_=p_->next;
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
    Clear_List(head_a,head_b);
    printf("After Clear:\n");
    Display_List(head_a);

    Free_List(head_a);
    Free_List(head_b);
}
