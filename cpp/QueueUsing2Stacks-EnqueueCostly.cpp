#include <iostream>
using namespace std;


class stack1
{
  public:
    int *arr;
    int topChar;
    int top;
    stack1()
    {
        
    }
    stack1(int n)
    {
        top = -1;
        arr = new int[n];
    }
    void push(char ele)
    {
        top++;
        arr[top] = ele;
    }
    int pop()
    {
        if(top == -1)
            return '0';
        else
        {
            topChar = arr[top];
            top--;
            //cout<<topChar;
            return topChar;
        }
    }
    int peek()
    {
        return arr[top];
    }
    bool isEmpty()
    {
        if(top == -1)
            return true;
        return false;
    }
};

int main()
{
    stack1 obj1(10);
    stack1 obj2(10);
    
    int ch = 0,num;

    while(ch != 3)
    {
        cout<<"1.Enqueue\n";
        cout<<"2.Dequeue\n";
        cout<<"3.exit\n";
        
        cout<<"\nEnter your choice : ";
        cin>>ch;
        
        if(ch == 1)
        {
            cout<<"\nEnter the element : ";
            cin>>num;
            if(obj1.isEmpty())
                obj1.push(num);
            else
            {
                while(!obj1.isEmpty())
                {
                    //cout<<"Peek element : "<<obj1.peek()<<endl;
                    obj2.push(obj1.pop());
                }
                obj1.push(num);
                while(!obj2.isEmpty())
                    obj1.push(obj2.pop());
            }
            
        }
        else if(ch == 2)
        {
            int res = obj1.pop();
            if(res != '0')
                cout<<"Dequeue : "<<obj1.pop()<<endl;
            else
              cout<<"Queue is empty\n";
            
        }
        else if(ch == 3)
            break;
    }
    
    
    

    return 0;
}
