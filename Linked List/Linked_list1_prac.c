#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start;
struct node* Create_node()
{
 struct node *n;
 n=(struct node*)malloc(sizeof(struct node));
 n->next=NULL;
 return n;
}
void insert_node()
{
    struct node *t,*p;
    t=Create_node();
    printf("\nEnter Data : ");
    scanf("%d",&t->data);
    if(start==NULL)
    {
        start=t;
    }
    else
    {
        p=start;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=t;
    }
}
void delete_node()
{
    struct node *p,*temp;
    if(start==NULL)
    {
        printf("\nList Is Empty\n");
        return;
    }
    else
    {
        p=start;
        while(p->next!=NULL)
        {
            temp=p;
            p=p->next;
        }
        temp->next=p->next;
        free(p);

    }
}
void reverse()
{
  struct node *p,*q,*r;
  r=NULL;
  q=NULL;
  p=start;
  while(p!=NULL)
  {
    r=q;
    q=p;
    p=p->next;
    q->next=r;
  }
  start=q;
}

void display()
{
    struct node *t;
    if(start==NULL)
    {
        printf("\nList Is Empty\n");
        return ;
    }
    else
    {
        t=start;
        while(t!=NULL)
        {
            printf("%d\n",t->data);
            t=t->next;
        }
    }
}

int main()
{
    int choice;
    printf("1.insert Data");
    printf("\n2.Delete Data");
    printf("\n3.View_list");
    printf("\n4.Reverse");
    printf("\n5.Exit\n");
    while(1)
    {
        printf("\nEnter Your Choice :");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            insert_node();
            break;
        case 2:
            delete_node();
            break;
        case 3:
            display();
            break;
        case 4:
        reverse();
        break;
        case 5:
            exit(0);
        }
    }
}
