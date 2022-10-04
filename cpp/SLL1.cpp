#include<iostream>
using namespace std;

class node
{
	public:
		int data;
		node* next;	
};

class list
{
	public:
		node* head;
		int len;
	
	list() //Default constructor
	{
		head==NULL;
		len=0;
	
	}

void create();
void display();
void insert(int pos,int data);
void search(int info);
void del(int pos);
void update(int pos,int new_data);
void sort();
void reverse();	
	
};

void list :: create()
{
	node *temp,*ptr;
	int add;
	
	do
	{
		temp=new node;
		cout<<"Enter your data: ";
		cin>>temp->data;
		temp->next=NULL;
		len++;
		
		if(head==NULL)
		{
			head=temp;
		}
		
		else
		{
			ptr=head;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			    
			}
	         ptr->next=temp;
		}
		
		cout<<"If you want to add more nodes enter 1: ";
		cin>>add;
		
	}  while(add==1);
	
}


void list :: display()
{
	node *ptr;
	ptr=head;
	
	cout<<"\n";
	while(ptr!=NULL)
	{
		
		cout<<ptr->data<<" ->";
		ptr=ptr->next;
	}
	cout<<"NULL";
	
}


void list :: insert(int pos,int data)
{
	
	if(pos==1)
	{
		
		node *temp,*ptr;
		temp=new node;
		temp->data=data;
		
		temp->next=head;
		head=temp;
		len++;
		
	}
	
	else if(pos>len)
	{
		
		node *temp,*ptr;
		temp=new node;
		temp->data=data;
		
		
		ptr=head;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
			    
		}
		
	    ptr->next=temp;
	    len++;
	}
	
	else
	{
		node *temp,*p;
		temp=new node;
		temp->data=data;
		
		
		p=head;
		
		for(int i=1;i<(pos-1);i++)
		{
			p=p->next;
			
		}
		
		temp->next=p->next;
		p->next=temp;
		
		len++;
		
	}
	
}

void list :: search(int info)
{
	node *p;
	p=head;
	int flag=0,count=1;
	
	while(p!=0)
	{
		if(p->data==info)
		{
			flag=1;
			break;
		}
		
		else
		{
			p=p->next;
		}
		count++;
		
	}
	
	if(flag==1)
	{
		cout<<"Your data has been found at pos: "<<count;
	}
		
	else
	{
		cout<<"Data not found";
	}
	
}

void list :: del(int pos)
{
	node *curr, *prev;
	
	curr=head;
	prev=NULL;
	
	if(pos<1 || pos>len)
    {
    	cout<<"\nSorry!!! No element present at given position";
    }
	
	else if(pos==1)
	{
		
		head=head->next;
		delete curr;
		len--;
		cout<<"\nData has been deleted successfully!!!\n";
	}
	
	
	else if(pos==len)
	{
		while(curr->next!=NULL)
		{
			prev=curr;
			curr=curr->next;
			
		}
		
		prev->next=NULL;
		delete curr;
		len--;
		cout<<"\nData has been deleted successfully!!!\n";
	}
	
	
	else
	{
		for(int i=1;i<pos;i++)
		{
			prev=curr;
			curr=curr->next;
			
		}
		
		prev->next=curr->next;
		delete curr;
		cout<<"\nData has been deleted successfully!!!\n";
		len--;
	}


}


void list :: update(int pos,int new_data)
{
	node *p;
	p=head;
	
	if(pos>len)
	{
		cout<<"\nSorry!!! data not available at given position";
	}
	
	else if(pos==1)
	{
		p->data=new_data;
		cout<<"\nData updated successfully!!!\n";
	}
	
	else if(pos==len)
	{
		while(p->next!=NULL)
		{
			p=p->next;
			
		}
		p->data=new_data;
		cout<<"\nData updated successfully!!!\n";
	}
	
	
	else
	{
		for(int i=1;i<pos;i++)
		{
			p=p->next;
			
		}
		p->data=new_data;
		cout<<"\nData updated successfully!!!\n";
	}
	
}

void list :: sort()
{
	node *prev,*curr;
	int val;
	
	for(int i=1;i<len;i++)
	{
		prev=head;
		curr=head->next;
		while(curr!=NULL)
		{
			if(curr->data<prev->data)
			{
				val=curr->data;
				curr->data=prev->data;
				prev->data=val;
			
			}
			else
			{
			    prev=curr;
			    curr=curr->next;
			}
		}
	}
	
}


void list :: reverse()
{
	
	node *r,*s,*q;
	
	r=NULL;
	q=head;
	
	while(q!=NULL)
	{
		s=r;
		r=q;
		q=q->next;
		r->next=s;
		
	} head=r;
	
	
}


int main()
{
	int pos,ch,start=1,data,info,new_data;
	node n;
	list l;
	l.create();
	l.display();
	
	cout<<"\n\n1)Insert\n2)Search\n3)Delete\n4)Update\n5)Sorting List\n6)Reverse\n7)Exit";
	
	while(start==1)
    {
    	cout<<"\n\nEnter your choice: ";
        cin>>ch;
        
    	 switch(ch)
         {
    	
    	    case 1:
    	    	cout<<"\nEnter position where you want to insert data: ";
    	    	cin>>pos;
    	    	cout<<"Enter data: ";
    	    	cin>>data;
    		    l.insert(pos,data);
    		    cout<<"\nData inserted successfully!!!\n";
    		    l.display();
    		    break;
    		    
    	    
    		case 2:
    			cout<<"Enter data to search: ";
    			cin>>info;
    			l.search(info);
    			break;
    		
    		case 3:
    			cout<<"Enter position of data you want to delete: ";
    			cin>>pos;
    			
				l.del(pos);
				l.display();
    			break;
    			
    		case 4:
    			cout<<"Enter position of data you want to update: ";
    			cin>>pos;
    			cout<<"Enter new data: ";
    			cin>>new_data;
    			l.update(pos,new_data);
    			l.display();
    			break;
    		case 5:
    			l.sort();
    			l.display();
    			break;
    		
    		case 6:
    			l.reverse();
    			l.display();
    			
    			break;
    		case 7:
    			cout<<"\nThankyou!!!";
    			break;
    			
    		default:
    		cout<<"\nSorry!!! you have entered wrong choice";
    	 }	
    	
    cout<<"\nPress 1 to contionue  or  press any key to exit: ";
    cin>>start;
    
	}

	
	return 0;
}
