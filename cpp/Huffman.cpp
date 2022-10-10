// huffman code in C++

#include<bits/stdc++.h>
using namespace std;

struct btnode{
struct btnode * lc;
char c;
int data;
int i;
struct btnode * rc;
};

typedef struct btnode * btptr;

struct Queues{
int size;
int front;
int rear;
btptr elements[50];
};
typedef struct Queues * qptr;

void enqueue(struct Queues *q,btptr x)
{
    if((q->rear+1)%(q->size)==q->front)
    {
        cout<<"queue is full"<<endl;
    }
    else{
        if(q->front==-1)
        {
            q->front=0;q->rear=0;
            q->elements[q->rear]=x;
        }
        else{
            q->rear=(q->rear+1)%q->size;
            q->elements[q->rear]=x;
        }
    }
}

btptr dequeue(struct Queues *q)
{
    if(q->front==-1)
    {
        cout<<"queue is empty"<<endl;
    }
    else{ btptr t;
        if(q->front==q->rear)
        {
            t=q->elements[q->front];
            q->front=-1;q->rear=-1;
        }
        else{
            t=q->elements[q->front];
            q->front=(q->front+1)%q->size;
        }
        return t;
    }
}

void lvlorder2(btptr T)
{
    if (T==NULL)
        return;
    qptr q=new(Queues);
    q->size=100;
    q->front=-1;
    q->rear=-1;
    enqueue(q,T);
    int s=0;
    int j=1;
    while (q->front!=-1)
    {
        s=0;
        while(j--)
        {
        btptr t=dequeue(q);
        cout<<t->c<<t->data<<" ";
        if (t->lc!= NULL)
            {enqueue(q,t->lc);s++;}
        if (t->rc!= NULL)
           {enqueue(q,t->rc);s++;}
        }
        j=s;
        cout<<endl;
    }
}
void bubbleSort(btptr t[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)
   {
    for (j = 0; j < n-i-1; j++)
        {if (t[j]->data > t[j+1]->data)
            {
            btptr temp=t[j];
            t[j]=t[j+1];
            t[j+1]=temp;
            }
        }
   }
}
void print(btptr t[],int n)
{
    int i=0;
    while(i<n)
    {
        cout<<t[i]->c<<t[i]->data<<" ";
        i++;
    }
    cout<<endl;
}

bool ancestor(btptr t,int k,qptr q,btptr h)
{

    if(t==NULL){return 0;}

    if(t->data==k){
            //cout<<t->i;
         enqueue(q,t);
         return 1;
    }
if(ancestor(t->lc,k,q,h) || ancestor(t->rc,k,q,h))
        {
         if(t!=h){ enqueue(q,t);}
           return 1;
        }
        return 0;

}

int main()
{
   int n;
   cin>>n;
   btptr t[n];
   int i=0;
   char a;
   int b;
   int c[n];
   int ch[n];
   int d=n;
   while(i<n)
   {
        cin>>a>>b;
        ch[i]=b;
        t[i]=new(btnode);
        t[i]->c=a;
        t[i]->data=b;
        c[i]=b;
        t[i]->lc=NULL;
        t[i]->rc=NULL;
        t[i]->i=3;
        i++;
        cout<<t[i-1]->c<<t[i-1]->data<<endl;
   }
    bubbleSort(t,n);
    print(t,n);
   while(n!=1)
   {
        int l=t[1]->data;
        int r=t[0]->data;

        btptr temp=new(btnode);
        temp->c='#';
        temp->data=l+r;
        temp->lc=t[1];
        t[1]->i=0;
        temp->rc=t[0];
        t[0]->i=1;

        n=n-2;
        for (int j=0; j<n; j++)
        t[j] = t[j+2];
        int j;
        for ( j = n - 1; (j >= 0 && t[j]->data >= temp->data); j--)
        t[j + 1] = t[j];

    t[j + 1] = temp;
    n+=1;
   
   }

   lvlorder2(t[0]);
   string s[d]={""};
   qptr q=new(Queues);
   q->front=-1;
   q->rear=-1;
   q->size=100;
   
  
  for(int i=0;i<d;i++)
   {
       ancestor(t[0],ch[i],q,t[0]);
       while(q->front!=-1)
       {
       char c=dequeue(q)->i+'0';
       s[i]=c+s[i];
       }
       cout<<s[i]<<endl;
   }

}


