#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct List
{
    char name[10];
    long long num;
    struct List *next;
};
typedef struct List NODE;

int close=1;

NODE *Create()
{
    NODE *head,*tail,*pnew;
    char name[10];
    long long num;
    head=(NODE *)malloc(sizeof(NODE));
    if(head==NULL)
    {
        printf("No enough memory.\n");
        return(NULL);
    }
    tail=head;
    tail->next=NULL;

    while(1)
    {
        printf("Name: ");
        scanf("%s",name);
        if(strcmp(name,"0")==0)
            break;
        printf("Num: ");
        scanf("%lld",&num);
        pnew=(NODE *)malloc(sizeof(NODE));
        if(pnew==NULL)
        {
            printf("No enough memory.\n");
            return(NULL);
        }
        strcpy(pnew->name,name);
        pnew->num=num;
        tail->next=pnew;
        tail=pnew;
        tail->next=NULL;
    }
    return(head);
}

void Add(NODE *head)
{
    NODE *pnew,*p;
    char name[10];
    long long num;
    pnew=(NODE *)malloc(sizeof(NODE));
    if(pnew==NULL)
    {
        printf("No enough memory.\n");
        return;
    }
    printf("Name: ");
    scanf("%s",name);
    printf("Num: ");
    scanf("%lld",&num);
    p=head;
    while(p->next!=NULL)
    {
        p=p->next;
        if(strcmp(p->name,name)==0||p->num==num)
        {
            printf("Repeated add.\n");
            free(pnew);
            return;
        }
    }
    strcpy(pnew->name,name);
    pnew->num=num;
    pnew->next=head->next;
    head->next=pnew;
}

void Delete(NODE *head)
{
    NODE *p=head,*q;
    int i,j;
    printf("Delete No.");
    scanf("%d",&i);
    if(i<=0)
    {
        printf("Invalid input.\n");
        return;
    }
    for(j=0;j<i-1&&p->next!=NULL;j++)
        p=p->next;
    if(p->next==NULL)
        printf("Not found.\n");
    else
    {
        q=p->next;
        p->next=q->next;
        free(q);
    }
}

void Mod(NODE *head)
{
    NODE *p=head;
    char name[10];
    long long num;
    int i,j;
    printf("Mod No.");
    scanf("%d",&i);
    if(i<=0)
    {
        printf("Invalid input.\n");
        return;
    }
    for(j=0;j<i&&p!=NULL;j++)
        p=p->next;
    if(p==NULL)
        printf("Not found.\n");
    else
    {
        printf("Name: ");
        scanf("%s",name);
        printf("Num: ");
        scanf("%lld",&num);
        strcpy(p->name,name);
        p->num=num;
    }
}

void Sort(NODE *head)
{
    NODE *p=head,*q;
    long long num;
    char name[10];
    while(p->next!=NULL)
    {
        p=p->next;
        q=p;
        while(q->next!=NULL)
        {
            q=q->next;
            if(strcmp(p->name,q->name)>0)
            {
                strcpy(name,p->name);
                strcpy(p->name,q->name);
                strcpy(q->name,name);
                num=p->num;
                p->num=q->num;
                q->num=num;
            }
        }
    }
}

void Search(NODE *head)
{
    NODE *p=head;
    long long num=0;
    int i,j=0;
    char name[10];
    printf("Search: 1.Name 2.Num\nYour choice: ");
    scanf("%d",&i);
    switch(i)
    {
        case 1:
            printf("Name: ");
            scanf("%s",name);
            while(p->next!=NULL)
            {
                p=p->next;
                if(strcmp(p->name,name)==0)
                {
                    printf("Num: %lld\n",p->num);
                    j=1;
                    break;
                }
            }
            break;
        case 2:
            printf("Num: ");
            scanf("%lld",&num);
            while(p->next!=NULL)
            {
                p=p->next;
                if(num==p->num)
                {
                    printf("Name: %s\n",p->name);
                    j=1;
                    break;
                }
            }
            break;
        default:
            printf("Invalid input.\n");
            break;
    }
    if(j==0)
        printf("Not found.\n");
}

void Display(NODE *head)
{
    NODE *p=head;
    int i=0;
    printf("No\tName\tNum\n");
    while(p->next!=NULL)
    {
        p=p->next;
        i++;
        printf("%d\t%s\t%lld\n",i,p->name,p->num);
    }
}

void Free(NODE *head)
{
    NODE *p;
    while(head->next!=NULL)
    {
        p=head->next;
        head->next=p->next;
        free(p);
    }
    free(head);
}

void Choose(NODE *head)
{
    int i=0;
    printf("\nContacts:\n--------------------------\n");
    Display(head);
    printf("--------------------------\nChoices:\n1.Add\n2.Delete\n3.Mod\n4.Sort\n5.Search\n6.Close\nYou choose: ");
    scanf("%d",&i);
    switch(i)
    {
        case 1:
            Add(head);
            break;
        case 2:
            Delete(head);
            break;
        case 3:
            Mod(head);
            break;
        case 4:
            Sort(head);
            break;
        case 5:
            Search(head);
            break;
        case 6:
            close=0;
            break;
        default:
            printf("Invalid input.\n");
            break;
    }
}

int main()
{
    NODE *head;
    FILE *fp;
    printf("Functions:\n");
    printf("Warning of Malloc: No enough memory.\n");
    printf("Warning of Add: Repeated add.\n");
    printf("Warning of Search and Delete and Choose and Mod: Invalid input.\n");
    printf("Warning of Search and Mod and Delete: No found.\n\n");


    printf("Create:\n");
    head=Create();
    while(close)
        Choose(head);

    Free(head);
    return 0;
}
