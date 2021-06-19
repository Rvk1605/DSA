#include<stdio.h>
#include<stdlib.h>
struct node
{
  struct node *lchild;
  struct node *rchild;
  int info;
};
struct node *root=NULL;
struct node *Create_node()
{
  struct node *n;
  n=(struct node*)malloc(sizeof(struct node));
  n->lchild=NULL;
  n->rchild=NULL;
  return n;
}

void search(struct node **loc,struct node **par,int val)
{
struct node *ptr,*ptr_prev;
if(root==NULL)
{
  *loc=NULL;
  *par=NULL;
  return;
}
else if(root->info==val)
{
  *par==NULL;
  *loc=NULL;
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
    *par=ptr_prev;
    *loc=ptr;
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

void insert(int val)
{
  struct node *loc=NULL,*par=NULL,*t;
  search(&loc,&par,val);

  if(loc!=NULL)
  {
    printf("\nElement Exists\n");
    return;
  }
  else
  {
  t=Create_node();
  t->info=val;
  if(par==NULL)
  root=t;
  else if(val<par->info)
  par->lchild=t;
  else
  par->rchild=t;
  }
}

void preorder(struct node *root)
{
  if(root==NULL)
  return;
  else
  {
    printf("%d\n",root->info);
    preorder(root->lchild);
    preorder(root->rchild);
  }
}

void postorder(struct node *root)
{
  if(root==NULL)
  return;
  else
  {
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d\n",root->info);
  }
}

void inorder(struct node *root)
{
  if(root==NULL)
  return;
  else
  {
    inorder(root->lchild);
    printf("%d\n",root->info);
    inorder(root->rchild);
  }
}

void delete_leaf(struct node *loc,struct node *par)
{
  if(par==NULL)
  root=NULL;
  else if(loc==par->lchild)
  par->lchild==NULL
  else
  par->rchild==NULL;
  free(loc);
}

void delete_one_tree(struct node *loc,struct node *par)
{
  if(par->lchild!=NULL&&par->rchild==NULL)
  {
    if(par==NULL)
    root=loc->lchild;
    else if(par->lchild==loc)
    par->lchild=loc->lchild;
    else
    par->rchild=loc->lchild;
  }
  else if(par->lchild==NULL&&par->rchild!=NULL
  {
      if(par==NULL)
      root=loc->rchild;
      else if(par->lchild==loc)
      par->lchild=loc->rchild;
      else
      par->rchild=loc->rchild;
  }
  free(loc);
}

void delete_two_subtree()
{

}

void delete(int val)
{
  struct node *loc=NULL,*par=NULL;
  search(&loc,&par,val)
  if(root==NULL)
  {
    printf("\nTree not exist\n");
    return;
  }
  else if(loc==NULL)
  {
    printf("\nElement Not Exists\n");
    return;
  }
  else if(loc->lchild==NULL&&loc->rchild==NULL)
  {
    delete_leaf_node(loc,par);
  }
  else if((loc->lchild!=NULL&&loc->rchild==NULL)||(loc->lchild==NULL&&loc->rchild!=NULL))
  {
    delete_one_subtree(loc,par);
  }
  else if(loc->rchild!=NULL&&loc->lchild!=NULL)
  {
    delete_two_subtree(loc,par);
  }
}

int main()
{
  int choice,data,val;


}
