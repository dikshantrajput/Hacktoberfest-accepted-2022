#include<iostream>
using namespace std;

class node
{
	public:
		int data;
		node* next;	
		node *prev;
};

class dlist
{
	public:
		node* head;
		int len;
	
	dlist() //Default constructor
	{
		head==NULL;
		len=0;
	
	}

void create();
void fdisplay();
void bdisplay();
void insert(int pos,int data);
void del(int pos);
void update(int pos,int new_data);
void search(int info);
void sort();


};

void dlist :: create()
{
	node *temp,*p;
	int add;
	
	do
	{
		temp=new node;
		cout<<"Enter your data: ";
		cin>>temp->data;
		temp->next=NULL;
		temp->prev=NULL;
		len++;
		
		if(head==NULL)
		{
			head=temp;
		}
		
		else
		{
			p=head;
			while(p->next!=NULL)
			{
				p=p->next;
			    
			}
	         p->next=temp;
	         temp->prev=p;
		}
		
		cout<<"If you want to add more nodes enter 1: ";
		cin>>add;
		
	}  while(add==1);
	
}


void dlist :: fdisplay()//forward display
{
	node *p;
	p=head;
	
	cout<<"\n";
	while(p!=NULL)
	{
		cout<<p->data<<" ->";
		p=p->next;
	}
	cout<<"NULL";
}

void dlist :: bdisplay()//backward display
{
	node *p;
	p=head;
	
	cout<<"\n";
	while(p->next!=NULL)
	{
		p=p->next;
	}
	
	do
	{
		cout<<p->data<<"->";
		p=p->prev;
	}while(p!=NULL);
	
	cout<<"NULL";
}


void dlist :: insert(int pos,int data)
{
	
	if(pos==1)
	{
		
		node *temp,*p;
		temp=new node;
		temp->data=data;
		
		temp->next=head;
		head->prev=temp;
		head=temp;
		len++;
		
	}
	
	else if(pos>len)
	{
		
		node *temp,*p;
		temp=new node;
		temp->data=data;
		
		
		p=head;
		while(p->next!=NULL)
		{
			p=p->next;
			    
		}
		
	    p->next=temp;
	    temp->prev=p;
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
		p->next->prev=temp;
		p->next=temp;
		temp->prev=p;
		
		len++;
		
	}
	
}

void dlist :: del(int pos)
{
	node *p,*prev;
	
	p=head;
	
	if(pos<1 || pos>len)
    {
    	cout<<"\nSorry!!! No element present at given position";
    }
	
	else if(pos==1)
	{
		
		head=head->next;
		head->prev=NULL;
		delete p;
		len--;
		cout<<"\nData has been deleted successfully!!!\n";
	}
	
	
	else if(pos==len)
	{
		while(p->next!=NULL)
		{
			p=p->next;
			
		}
		
		p->prev->next=NULL;
		delete p;
		len--;
		cout<<"\nData has been deleted successfully!!!\n";
	} 
	
	
	else
	{
		for(int i=1;i<pos;i++)
		{
			p=p->next;
			
		}
		
		p->prev->next=p->next;
		p->next->prev=p->prev;
		delete p;
		cout<<"\nData has been deleted successfully!!!\n";
		len--;
	}

}

void dlist :: update(int pos,int new_data)
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

void dlist :: search(int info)
{
	node *p;
	p=head;
	int flag=0,count=1;
	
	while(p!=NULL)
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


void dlist :: sort()
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


int main()
{
	int pos,ch,start=1,data,info,new_data;
	node n;
	dlist dl;
	dl.create();
	dl.fdisplay();
	
	
	
	while(start==1)
    {
        
		cout<<"\n\n1)Insert\n2)Reverse list\n3)Delete\n4)Update\n5)Search\n6)Sort";
    	cout<<"\n\nEnter your choice: ";
        cin>>ch;
        
    	 switch(ch)
         {
    	
    	    case 1:
    	    	cout<<"\nEnter position where you want to insert data: ";
    	    	cin>>pos;
    	    	cout<<"Enter data: ";
    	    	cin>>data;
    		    dl.insert(pos,data);
    		    cout<<"\nData inserted successfully!!!\n";
    		    dl.fdisplay();
    		    break;
    		    
    	    
    		case 2:
    			
    			dl.bdisplay();
    			break;
    		
    		case 3:
    			cout<<"\nEnter position where you want to insert data: ";
    	    	cin>>pos;
    			dl.del(pos);
    			dl.fdisplay();
    			break;
    		
    		case 4:
    			cout<<"Enter position of data you want to update: ";
    			cin>>pos;
    			cout<<"Enter new data: ";
    			cin>>new_data;
    			dl.update(pos,new_data);
    			dl.fdisplay();
    		    break;
    		
    		case 5:
    			cout<<"Enter data to search: ";
    			cin>>info;
    			dl.search(info);
    			break;
    		case 6:
    		    dl.sort();
    		    dl.fdisplay();
    		    break;
    		    
    		default:
    		cout<<"\nSorry!!! you have entered wrong choice";
    	 }	
    	
    cout<<"\nPress 1 to contionue  or  press any key to exit: ";
    cin>>start;
    
	}
	
	
	return 0;
}
