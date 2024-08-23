#include<stdio.h>
#define n 5
int stack[n];
int top=-1;
void push(int data)
{
    if(top==n-1)
    {
        printf("\nStack is FULL");
    }
    else
    {
        top++;
        stack[top]=data;
    }
}
void pop()
{
    int data;
    if(top==-1)
    {
        printf("\nStack is EMPTY");
    }
    else
    {
        data=stack[top];
        top--;
        printf("\nDeleted value is %d",data);
    }
}
void display()
{
    int i;
    if(top==-1)
    {
        printf("\nStack is EMPTY");
    }
    else
    {
        for(i=top;i>=0;i--)
        {
            printf("\n%d",stack[i]);
        }
    }
}
int main()
{
    int ch,value;
    do
    {
        p:
        printf("\n1.PUSH\t2.POP\t3.DISPLAY\t4.EXIT");
        printf("\nEnter the choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter the value: ");
                scanf("%d",&value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nProgram COmplete....");
                break;
            default:
                printf("\nPlease enter the correct choice...");
                goto p;
        }
    } while(ch!=4);
}