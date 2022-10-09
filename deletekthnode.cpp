#include<iostream>
using namespace std;
struct node
{
	public:
		int data;
		struct node* next;
}*first=NULL,*last=NULL;
void create(int a[],int n)
{
	first=new node();
	first->data=a[0];
	first->next=NULL;
	last=first;
	for(int i=1;i<n;i++)
	{
		node* t=new node();
		t->data=a[i];
		t->next=NULL;
		last->next=t;
		last=t;
	}
	
}void display(struct node* p)
{
	if(p!=NULL)
	{
		cout<<p->data<<"-->";
		display(p->next);
	}
}node* delete_end(struct node* p,int pos)
{
	int i=0;
	node* dummy=new node();
	dummy->next=p;
	struct node* f;struct node* s;
	f=s=dummy;
	while(i!=pos)
	{
		f=f->next;
		i++;
	}while(f->next!=NULL)
	{
		f=f->next;
		s=s->next;
	}
	s->next=s->next->next;
	return dummy->next;
	
}
int main()
{
	int a[6]={3,2,5,4,1,7};
	create(a,6);
	display(first);
  int n;
  cout<<"Enter the nth node you want to delete ";
  cin>>n;
	cout<<endl;
	struct node* k=delete_end(first,n);
	display(k);
}
