#include<stdio.h>
#include<stdlib.h>
struct node
{
  int info;
  struct node *lchild;
  struct node *rchild;
};
struct node *root=NULL;
struct node *Create_node()
{
  struct node *n;
  n=(struct node *)malloc(sizeof(struct node));
  n->rchild=NULL;
  n->lchild=NULL;
  return n;
}

void search(struct node **loc,struct node **par,int val)
{
    struct node *p,*q;
  if(root==NULL)
  {
    *par=NULL;
    *loc=NULL;
    return;
  }
  else if(root->info==val)
  {
    *par=NULL;
    *loc=root;
    return;
  }
  else
  {
  //follow L<N<R rule and Initialize
  p=root;
  if(val<root->info)
  q=root->lchild;
  else
  q=root->rchild;
  while(q!=NULL)
  {
    if(val==q->info)
    {
      *loc=q;
      *par=p;
      return;
    }
    p=q;
    if(val<q->info)
      q=q->rchild;
    else
      q=q->lchild;
   }
   *loc=NULL;
   *par=p;
   return;
}
void insert()
{
  struct node *par=NULL,*loc=NULL,*t;
  t=Create_node();
  printf("Enter Data :");
  scanf("%d",&t->info);
  search(&loc,&par,t->info);
  if(loc!=NULL)
  {
    printf("\nElement Exist\n");
    return;
  }
  else
  {
    if(par==NULL)
    root=t;
    else if(t->info<par->info)
    par->lchild=t;
    else
    par->rchild=t;
  }
}
void traverse(struct node *ptr)
{
  if(ptr==NULL)
  return;
  else
  traverse(ptr->lchild);
  printf("%d\n",ptr->info);
  traverse(ptr->rchild);
}

int main()
{
  int choice ;
  printf("1.Insert");
  printf("\n2.View");
  printf("\n3.Exit\n");
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
    }
  }
}
