#include<stdio.h>
int stack[20];
int top = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char exp[20];
    char *e;
    int m1,m2,m3,num;
    printf("Enter the expression :: ");
    scanf("%s",exp);
    e = exp;
    while(*e != '\0')
    {
        if(isdigit(*e))
        {
            num = *e - 48;
            push(num);
        }
        else
        {
            m1 = pop();
            m2 = pop();
            switch(*e)
            {
            case '+':
            {
                m3 = m1 + m2;
                break;
            }
            case '-':
            {
                m3 = m2 - m1;
                break;
            }
            case '*':
            {
                m3 = m1 *m2;
                break;
            }
            case '/':
            {
                m3 = m2 / m1;
                break;
            }
            }
            push(m3);
        }
        e++;
    }
    printf("\nThe result of expression %s  =  %d\n\n",exp,pop());
    return 0;
}
