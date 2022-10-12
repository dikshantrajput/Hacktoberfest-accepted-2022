#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<stdlib.h>

struct node
{
  int info;
  struct node* llink,*rlink;
};
struct node *root=NULL;

void insfront()
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node ));
	printf("\n enter the item");
	scanf("%d",&temp->info);
	temp->llink=NULL;
	temp->rlink=NULL;
	if(root==NULL)
		root=temp;
	else
	{
	temp->rlink=root;
	root->llink=temp;
	root=temp;
	}
}

void del()
{
	int x;
	struct node *temp;
	if(root==NULL)
	{
	printf("\n list is empty\n");
	return;
	}
	printf("\n enter item to be deleted:");
	scanf("%d",&x);
	temp=root;
	while(temp != NULL && temp->info != x) 
	 temp = temp->rlink;
	if (temp == NULL) 
	{        
	printf("Key is not found in the list");
	return;
	}
	if (temp->llink == NULL) 
	{
        // this is the first item
       root=temp->rlink;
       free(temp);
	}
	else if (temp->rlink == NULL) 
	{
        // this is the last item
        temp->llink->rlink=NULL;
        temp->llink=NULL;
        free(temp);
	}
	else 
	{
        // anywhere in between first and last
        temp->llink->rlink=temp->rlink;
        temp->rlink->llink=temp->llink ;
        temp->llink=temp->rlink=NULL;
        free(temp);
		}
 }
void display()
{
	struct node *temp;
	if(root==NULL)
	{
	printf("\n list is empty");
	return;
	}
	temp=root;
	printf("\n.... list status...\n");
	while(temp!=NULL)
	{
	printf("%d  ",temp->info);
	temp=temp->rlink;
	}
}

int main()
{
int ch;

while(1)
{
   
              printf("..... double link list....... ");
              printf("\n1.insert front \t 2.delete based on key \t 3.dispaly \n");
             printf("enter your choice\n");
              scanf("%d",&ch);
              switch(ch)
				{
					case 1: insfront(); break;
					case 2: del(); break;
					case 3: display(); break;
					default: exit(0);
				}
  
}
return 0;
}