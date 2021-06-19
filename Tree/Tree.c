#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
struct node
{
  int data;
  struct node *lchild;
  struct node *rchild;
};
int f=-1;
int r=-1;
struct node *Queue[SIZE];
struct node *root=NULL;
struct node *Create_node()
{
  struct node *n;
  n=(struct node *)malloc(sizeof(struct node));
  n->lchild=NULL;
  n->rchild=NULL;
  return n;
}

void search(struct node **loc,struct node **par,int val)
{

  struct node *ptr_prev,*ptr;
  if(root==NULL)
  {
    *loc=NULL;
    *par=NULL;
    return;
  }
  if(root->data==val)
  {
    *loc=root;
    *par=NULL;
    return;
  }
  ptr_prev=root;
  if(val<root->data)
  ptr=root->lchild;
  else
  ptr=root->rchild;
  while(ptr!=NULL)
  {
    if(val==ptr->data)
    {
      *loc=ptr;
      *par=ptr_prev;
      return;
    }
    ptr_prev=ptr;
    if(val<ptr->data)
    ptr=ptr->lchild;
    else
    ptr=ptr->rchild;
  }
  *loc=NULL;
  *par=ptr_prev;
  return;
}

void insert()
{
  int data;
  struct node *loc=NULL,*par=NULL,*t;
  printf("\nEnter Data :");
  scanf("%d",&data);
  search(&loc,&par,data);
  if(loc!=NULL)
  {
    printf("\nElement Exists\n");
    return;
  }
  else
  {
    t=Create_node();
    t->data=data;
    if(par==NULL)
    root=t;
    else if(data<par->data)
    par->lchild=t;
    else
    par->rchild=t;
  }
}

//Level Order Traversal//
void traverse(struct node *ptr)
{
  if(root==NULL)
  {
    printf("\nTree Is Empty\n");
    return;
  }
  Queue[++r]=ptr;
  f++;
  while(f<r)
  {
    ptr=Queue[f++];
    printf("%d\n",ptr->data);
    if(ptr->lchild!=NULL)
      Queue[++r]=ptr->lchild;
    if(ptr->rchild!=NULL)
    Queue[++r]=ptr->rchild;
  }
}

int main()
{
  int choice;
  printf("1.Insert in Tree");
  printf("\n2.View_Tree");
  printf("\n3.EXIT\n");
  while(1)
  {
    printf("\nEnter Your Choice :");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
        insert();
        break;
      case 2:
        traverse(root);
        break;
      case 3:
        exit(0);
      default:
        printf("\nInvalid Input\n");
    }
  }
}
