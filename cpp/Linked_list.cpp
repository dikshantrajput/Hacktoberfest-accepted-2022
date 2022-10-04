// Design and develop program for insertion ,  updating , searching , sorting ,listing
// and deletion operations using singly linked list for placement information system . 

#include<iostream>
using namespace std;

class node
{
	public:
		int id;
		long long mob;
		float cgpa;
		string name,company,address,email;
		node* next;
};

class Student
{
	public:
		node* head;
		int len;
		
		Student()   // Default constructor 
		{
			head=NULL;
			len=0;
			
		}
        // Member function declaration 
		void create();
		void display();
		void insert(int pos,string name ,int id,float cgpa,string company,int mob,string address,string email);
		void search(int id);
		void del(int pos);
		void update(int old_id,int id1,string name1,int mob1,string address1,float cgpa1,string company1,string email1);
		void sort();
};

void Student::create()   // create
{
	int a;
	node *temp,*ptr;
	do
	{
	    temp= new node ;        // create new node 
		
	    cout<<"Enter student name : ";
		cin>>temp->name;
		
		cout<<"Enter id : ";
		cin>>temp->id;
		
		cout<<"Enter CGPA : ";
		cin>>temp->cgpa;
		
		cout<<"Enter email id : ";
		cin>>temp->email;
		
		cout<<"Enter mobile no : ";
		cin>>temp->mob;
		
		cout<<"Enter address : ";
		cin>>temp->address;
		
		cout<<"Enter name of company for apply  : ";
		cin>>temp->company;
		
		temp->next=NULL;
		
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
		len++;
		cout<<"Press 1 to enter more no of students details: ";
		cin>>a;
		cout<<"\n";
		
	}while(a==1);
	cout<<"\n Total no of students details are : "<<len<<endl;
	cout<<"\n";
}

// insert  by position

void Student::insert(int pos,string name ,int id,float cgpa,string company,int mob,string address,string email)  
{
	if(pos==1)       // insert at the start 
	{
		node *temp,*ptr;
		temp= new node;
		
		temp->name=name;
		temp->id=id;
		temp->cgpa=cgpa;
		temp->email=email;
		temp->mob=mob;
		temp->address=address;
		temp->company=company;
		
		temp->next=head;
		head=temp;
		len++;
	}
	else
	if(pos>len)            // insert at the end 
	{
		node *temp,*ptr;
		
		temp= new node;
		
		temp->name=name;
		temp->id=id;
		temp->cgpa=cgpa;
		temp->email=email;
		temp->mob=mob;
		temp->address=address;
		temp->company=company;
		
	
		ptr=head;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=temp;
		len++;
	
	}
	else                 // insert at the middle 
	{
		node *temp,*ptr;
		temp= new node;
		
		temp->name=name;
		temp->id=id;
		temp->cgpa=cgpa;
		temp->email=email;
		temp->mob=mob;
		temp->address=address;
		temp->company=company;
		
	    ptr=head;
		
		for(int i=1;i<(pos-1);i++)
		{
			ptr=ptr->next;
			
		}
		temp->next=ptr->next;
		ptr->next=temp;
		len++;
		
	}
}

void Student::del(int pos)       // deletion by position
{
	node *temp;
	temp = head;
	
	
	if(pos==1)            // deletion  at the start
	{
		if(head==NULL)
		{
		   	cout<<"List is empty !!!\n";
		
		}
		else
		if(temp==head)
		{
		    head=head->next;
	        delete temp;
	       
	        len--;
	       
	    }
	
	}
	else 
	if(pos==len)        // deletion at the end 
	{
	      node *temp,*prev;
	      temp=head;
	      while(temp->next!=NULL)
	      {
	      	prev=temp;
	      	temp=temp->next;
		  }
		  if(temp==head)
		  {
		    head=NULL;
	     	delete temp;
		  }
		  else
		  {
		  	prev->next=NULL;
		  	delete temp;
		  }
		  
		  len--;
		  
	}
	else                     // deletion at the middle
	{
		node *nextnode;
		temp=head;
	
		for(int i=1;i<pos-1;i++)
		{
			temp=temp->next;
		}
		nextnode=temp->next;
		temp->next=nextnode->next;
		
		delete nextnode;
		len--;
		
	}
    
}

//Update

void Student::update(int old_id,int id1,string name1,int mob1,string address1,float cgpa1,string company1,string email1)  
{
	node *temp,*ptr;
	ptr=head;
	while(ptr!=NULL)
	{
		
		if(ptr->id==old_id)     // update by info
		{
		    temp->name=name1;
		    temp->id=id1;
		    temp->cgpa=cgpa1;
		    temp->email=email1;
		    temp->mob=mob1;
		    temp->address=address1;
		    temp->company=company1;
		    
    	}
    	ptr=ptr->next;
	}
	cout<<"Updation is successful !!!\n";
	cout<<"\n";
}


void Student::display()       // display
{
	node *ptr;
	ptr=head;
	while(ptr!=NULL)
	{
		cout<<ptr->id<<"\t"<<ptr->name<<"\t "<<ptr->cgpa<<"\t  "<<ptr->company<<"\t"<<ptr->email<<"\t"<<ptr->mob<<"\t"<<ptr->address<<"\n";
		ptr=ptr->next;
	}
}

void Student::search(int id)   // search
{
	node *temp,*ptr;
	int n=0;
	ptr=head;
	while(ptr!=NULL)
	{
		if(ptr->id==id)       // search by info
		{
			cout<<" Student details are present \n ";
			n++;
			break;
		}
		else
		{
			ptr=ptr->next;
		}
	}
	if(n==0)
	{
		cout<<"Details are not found \n";
	}
}

void Student::sort()      // sorting 
{
	node *curr,*prev;
	int stu_id,stu_mob;
	float stu_cgpa;
	string stu_name,stu_company,stu_address,stu_email;
	
	for(int i=0;i<len;i++)
	{
		prev=head;
		curr=head->next;
		while(curr!=NULL)
		{
			if(curr->cgpa < prev->cgpa)  // sort by cgpa of students
			{
				stu_id=curr->id;
				curr->id=prev->id;
				prev->id=stu_id;
				
				stu_name=curr->name;
				curr->name=prev->name;
				prev->name=stu_name;
				
				stu_cgpa=curr->cgpa;
				curr->cgpa=prev->cgpa;
				prev->cgpa=stu_cgpa;
				
				stu_company=curr->company;
				curr->company=prev->company;
				prev->company=stu_company;
				
				stu_email=curr->email;
				curr->email=prev->email;
				prev->email=stu_email;
				
				stu_address=curr->address;
				curr->address=prev->address;
				prev->address=stu_address;
				
				stu_mob=curr->mob;
				curr->mob=prev->mob;
				prev->mob=stu_mob;
				
				prev=curr;
				curr=curr->next;
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
	int pos,id,id1,choice,begin=1,old_id;
	long long mob,mob1;
	float cgpa,cgpa1;
	string name,company,address,email,name1,company1,address1,email1;
	node n;
	Student s;
	
	cout<<"\n";
	cout<<"\n****************  Student Information For Placement  *********************\n";
	cout<<"\n";
	cout<<"Create ---> 1 \nInsertion ---> 2 \nUpdate ---> 3 \nDetete ---> 4 \nSearch ---> 5\nSort ---> 6\n";
	cout<<"\n";
	
    while(begin==1)
	{
		cout<<"Enter your choice of operation : ";
	    cin>>choice;
	    
		switch(choice)
		{
			
			case 1:  // create 
				{
					s.create();
				    cout<<"\nId      Name     CGPA      Company      Email        Mobile          Address\n" ;
	                cout<<"\n------------------------------------------------------------------------------\n";
	                s.display();  
	                cout<<"\n\n";
					
				}
				break;
			case 2:  // insert 
				{   
				    cout<<"At position you want to insert : ";
				    cin>>pos;
				    
				    cout<<"Enter student name  : ";
				    cin>>name;
				    
	                cout<<"Enter id  : ";
					cin>>id;
					
					cout<<"Enter CGPA : ";
					cin>>cgpa;
					
				    cout<<"Enter name of company for apply  : ";
				    cin>>company;
				    
				    cout<<"Enter email id : ";
				    cin>>email;
				    
				    cout<<"Enter mobile number : ";
				    cin>>mob;
				    
				    cout<<"Enter address : ";
				    cin>>address;
				   
	                s.insert(pos,name,id,cgpa,company,mob,address,email);
	                cout<<"\nId      Name     CGPA      Company      Email        Mobile          Address\n" ;
	                cout<<"\n------------------------------------------------------------------------------\n";
	                s.display();  
	                cout<<"\n\n";
	               
	                cout<<"\n Insersion is successfull !!! \n";
					
				}
				break;
				
			case 3:  // update
				{
					cout<<"Enter old id : ";
					cin>>old_id;
					
					cout<<"Enter student name  : ";
				    cin>>name1;
				    
	                cout<<"Enter id  : ";
					cin>>id1;
					
					cout<<"Enter CGPA : ";
					cin>>cgpa1;
					
					cout<<"Enter mail id : ";
					cin>>email1;
					
				    cout<<"Enter name of company for apply  : ";
				    cin>>company1;
				    
				    cout<<"Enter mobile number : ";
				    cin>>mob1;
				    
				    cout<<"Enter address : ";
				    cin>>address1;
				   
					
	                s.update(old_id,id1,name1,cgpa1,company1,mob1,address1,email1);
	                cout<<"\nId      Name     CGPA      Company      Email        Mobile          Address\n" ;
	                cout<<"\n------------------------------------------------------------------------------\n";
	                s.display();  
	                cout<<"\n\n";
	               
	            
				}
				break;
				
			case 4:  // delete
				{
					cout<<"Enter position : ";
	                cin>>pos;
	                s.del(pos);
	                cout<<"\nId      Name     CGPA      Company      Email        Mobile          Address\n" ;
	                cout<<"\n------------------------------------------------------------------------------\n";
	                s.display();  
	                cout<<"\n\n";
	                
					
				}
				break;
				
			case 5:  // search
				{
					cout<<"Enter student id : ";
	                cin>>id;
	
	                s.search(id);
					
				}
				break;
				
			case 6:  // sorting
				{
					s.sort();
				    cout<<"\nId      Name     CGPA      Company      Email        Mobile          Address\n" ;
	                cout<<"\n------------------------------------------------------------------------------\n";
	                s.display();  
	                cout<<"\n\n";
				}
				break;
				
			default:
				cout<<"\n You have entered wrong choice !!!\n";
			
			
		}
		cout<<"\n Press 1 to continue : ";
		cin>>begin;
		
	}	
	cout<<"\n Thank You !!!\n";
	return 0;
}
