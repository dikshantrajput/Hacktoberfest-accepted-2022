#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node*lchild;
    int data;
    struct Node*rchild;
};
struct Node*root=NULL;

void Insert(int key)
{
    struct Node*t=root;
    struct Node*r,*p;

    if(root==NULL)
    {
        p=(struct Node*)malloc(sizeof(struct Node));
        p->data=key;
        p->lchild=p->rchild=NULL;
        root=p;
        return;
    }
    while(t!=NULL)
    {
        r=t;
        if(key<t->data)
        t=t->lchild;
        else if(key>t->data)
        t=t->rchild;
        else
        return;
    }
    p=(struct Node*)malloc(sizeof(struct Node));
        p->data=key;
        p->lchild=p->rchild=NULL;

        if(p->data < r->data)
           r->lchild=p;
           else
           r->rchild=p;
        
}
void inorder(struct Node*p)
{
    if(p==NULL)
    {
        return;
    }
    inorder(p->lchild);
    printf("%d",p->data);
    inorder(p->rchild);
}
struct Node*search(int key)
{
  struct Node*t=root;
  while(t!=NULL)
  {
      if(key==t->data)
      return t;
      else if(key<t->data)
      {
          t=t->lchild;
      }
      else
      {
          t=t->rchild;
      }
  }
  return NULL;
}
struct Node* RInsert(struct Node*p,int key) //RECURIVE INSERT FUNCTION
{
    struct Node*z=NULL;
  if(p==NULL)
  {
      z=(struct Node*)malloc(sizeof(struct Node));
       z->data=key;
       z->lchild=z->rchild=NULL;
       return z;
  }
  if(key<p->data)
      p->lchild=RInsert(p->lchild,key);
      else if(key>p->data)
      p->rchild=RInsert(p->rchild,key);

      return p;
}
struct Node*Delete(struct Node*p,int key)
{
    if(p==NULL)
    {
        return NULL;
    }
    if(p->lchild==NULL && p->rchild==NULL)
    {
        
    }
   
}
int main (void)
{
    struct Node*temp;
    root=RInsert(root,10);
    RInsert(root,5);
    RInsert(root,20);
    RInsert(root,8);
    RInsert(root,30);

    printf("INORDER...");
    printf("\n");
    inorder(root);
    printf("\n");
    temp=search(20);
    if(temp!=NULL)
    {
        printf("Element found..\n");

    }
    else
    {
        printf("Element not found\n");
    }
}

