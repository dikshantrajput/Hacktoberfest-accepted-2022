#include<iostream>
using namespace std;

class node
{
	public:
		int data;
		node* next;	
};

class clist
{
	public:
		node* head;
		int len;
	
	clist() //Default constructor
	{
		head=NULL;
		len=0;
	
	}

void create();
void display();
void insert(int pos, int data);
void search(int info);
void del(int pos);
void update(int pos,int new_data);
void sort();	
};

void clist :: create()
{
	node *temp,*ptr;
	int add;
	
	do
	{
		temp=new node;
		cout<<"Enter your data: ";
		cin>>temp->data;
		temp->next=temp;
		len++;
		
		if(head==NULL)
		{
			head=temp;
		}
		
		else
		{
			ptr=head;
			while(ptr->next!=head)
			{
				ptr=ptr->next;
			    
			}
	         ptr->next=temp;
	         temp->next=head;
		}
		
		cout<<"If you want to add more nodes enter 1: ";
		cin>>add;
		
	}  while(add==1);
	
}


void clist :: display()
{
	node* ptr;
	ptr=head;
	
	cout<<"\n";
	do
	{
		cout<<ptr->data<<" -> ";
		ptr=ptr->next;
		
	} while(ptr!=head);
	
	cout<<"head";
	
}


void clist :: insert(int pos,int data)
{
	
	if(pos==1)
	{
		
		node *temp,*p=head;
		temp=new node;
		temp->data=data;
		
		temp->next=head;
		
		while(p->next!=head)
		{
			p=p->next;
		}
		
		p->next=temp;
		head=temp;
		
		len++;
		
	}
	
	else if(pos>len)
	{
		
		node *temp,*p;
		temp=new node;
		temp->data=data;
		
		
		p=head;
		while(p->next!=head)
		{
			p=p->next;
			    
		}
		
	    p->next=temp;
	    temp->next=head;
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

void clist :: search(int info)
{
	node *p;
	p=head;
	int flag=0,count=1;
	
	while(p!=head)
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


void clist :: del(int pos)
{
	
	
	if(pos<1 || pos>len)
    {
    	cout<<"\nSorry!!! No element present at given position";
    }
	
	else if(pos==1)
	{
		
		node *p=head;
		
		while(p->next!=head)
		{
			p=p->next;
		}
		
		p->next=head->next;
		p=head;
		head=head->next;
		delete p;
		
		len--;
		cout<<"\nData has been deleted successfully!!!\n";
	}
	
	
	else if(pos==len)
	{
	    node *curr,*prev;
	    curr=head;
	    
		while(curr->next!=head)
		{
			prev=curr;
			curr=curr->next;
			
		}
		
		prev->next=head;
		delete curr;
		len--;
		cout<<"\nData has been deleted successfully!!!\n";
	}
	
	
	else
	{
	    node *curr,*prev;
	    curr=head;
	    
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


void clist :: update(int pos,int new_data)
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
		while(p->next!=head)
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

void clist :: sort()
{
	node *prev,*curr;
	int val;
	
	for(int i=1;i<len;i++)
	{
		prev=head;
		curr=head->next;
		while(curr!=head)
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

int main()
{
	int pos,data,new_data,ch,start=1,info;
	
	node n;
	clist cl;
	
	cl.create();
	cl.display();

	
	while(start==1)
    {
    	cout<<"\n\n1)Insert\n2)Search\n3)Delete\n4)Update\n5)Sort";
    	cout<<"\n\nEnter your choice: ";
        cin>>ch;
        
    	switch(ch)
        {
    	
    	    case 1:
    	    	cout<<"\nEnter position where you want to insert data: ";
    	    	cin>>pos;
    	    	cout<<"Enter data: ";
    	    	cin>>data;
    		    cl.insert(pos,data);
    		    cout<<"\nData inserted successfully!!!\n";
    		    cl.display();
    		    break;
    		    
            case 2:
    			cout<<"Enter data you want to search: ";
    			cin>>info;
    			cl.search(info);
    			break;
    		
			case 3:
			    cout<<"Enter pos of data that you want to delete: ";
    			cin>>pos;
    			cl.del(pos);
				cl.display();
    			break;	
    		
			case 4:
			    cout<<"Enter position of data you want to update: ";
    			cin>>pos;
    			cout<<"Enter new data: ";
    			cin>>new_data;
    			cl.update(pos,new_data);
    			cl.display();
    			break;	
    			
    		case 5:
			    cl.sort();
				cl.display();
				break;
				
			default:
    		cout<<"\nSorry!!! you have entered wrong choice";	
        }
    cout<<"\nPress 1 to contionue  or  press any key to exit: ";
    cin>>start;
   }
   
	return 0;
}
