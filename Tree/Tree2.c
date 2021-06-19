#include<stdio.h>
#include<stdlib.h>
struct node
{
  int info;
  struct node *lchild;
  struct node *rchild;
};

struct node *root = NULL;
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
  struct node *ptr,*ptr_prev;
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
  ptr_prev=root;
  if(val<root->info)
  ptr=root->lchild;
  else
  ptr=root->rchild;
  while(ptr!=NULL)
  {
    if(ptr->info==val)
    {
      *loc=ptr;
      *par=ptr_prev;
      return;
    }
    ptr_prev=ptr;
    if(val<ptr->info)
    ptr=ptr->lchild;
    else
    ptr=ptr->rchild;
  }
  *loc=NULL;
  *par=ptr_prev;
}

void insert()
{
  struct node *loc=NULL,*par=NULL,*t;
  t=Create_node();
  printf("\nENter Data :");
  scanf("%d",&t->info);
  search(&loc,&par,t->info);
  if(loc!=NULL)
  {
    printf("\nElement Already Exists\n");
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

void traverse(struct node *root)
{
  if(root==NULL)
  return;
  else
  {
    traverse(root->lchild);
    printf("%d\n",root->info);
    traverse(root->rchild);
  }
}

void delete_leaf(struct node *loc,struct node *par)
{
  if(par==NULL)
  root==NULL;
  else if(par->rchild==loc)
  par->rchild=NULL;
  else
  par->lchild=NULL;
}
void delete_one_tree(struct node *loc,struct node *par)
{
  if(loc->lchild!=NULL&&loc->rchild==NULL)
  {
    if(par==NULL)
      root=loc->lchild;
    else if(par->lchild==loc)
      par->lchild=loc->lchild;
    else
      par->rchild=loc->lchild;
  }
  else
  {
    if(par==NULL)
      root=loc->rchild;
    else if(par->rchild==loc)
      par->rchild==loc->rchild;
    else
      par->lchild=loc->rchild;
  }
  free(loc);
}

void delete_two_subtree(struct node *loc,struct node *par)
{
  struct node *new_loc,*new_par;
  new_loc=loc->lchild;
  while(new_loc->rchild!=NULL)
  {
    new_par=new_loc;
    new_loc=new_loc->rchild;
  }
  loc->info=new_loc->info;
  if(new_loc->lchild==NULL&&new_loc->rchild==NULL)
  {
    delete_leaf(new_loc,new_par);
  }
  else
  {
    delete_one_tree(new_loc,new_par);
  }
}

void delete(int val)
{
  struct node *loc=NULL,*par=NULL;
  search(&loc,&par,val);
  if(root==NULL)
  {
    printf("\nTree is Empty\n");
    return;
  }
  else if(loc==NULL)
  {
    printf("\nItem Not Found\n");
    return;
  }
  else if(loc->lchild==NULL&&loc->rchild==NULL)
  {
    delete_leaf(loc,par);
  }
  else if((loc->lchild!=NULL&&loc->rchild==NULL)&&(loc->lchild!=NULL&&loc->lchild==NULL))
  {
    delete_one_tree(loc,par);
  }
  else if(loc->rchild!=NULL&&loc->lchild!=NULL)
  delete_two_subtree(loc,par);

}

int main()
{
  int choice,data,val;
  printf("1.Insert");
  printf("\n2.View List");
  printf("\n3.Delete");
  printf("\n4.Exit\n");
  while(1)
  {
    printf("\nEnter your choice : ");
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
      printf("\nEnter Value  :");
      scanf("%d",&val);
      delete(val);
      break;
      case 4:
      exit(0);
    }
  }
}
