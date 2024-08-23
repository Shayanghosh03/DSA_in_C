//Program to implement Queue using Stack in C
#include<stdio.h>
#define size 5
int stack1[5],stack2[5];
int top1=-1,top2=-1;
int count=0;
void push1(int data)
{
    if(top1==size-1)
    {
        printf("\nStack is Full");
    }
    else
    {
        top1++;
        stack1[top1]=data;
    }

}
int pop1()
{
    if(top1==-1)
    {
        printf("\nStack is Blank");
    }
    else
    {
        int a=stack1[top1];
        top1--;
        return a;
    }

}
void push2(int x)
{
    if(top2==size-1)
    {
        printf("\nStack is Full");
    }
    else
    {
        top2++;
        stack2[top2]=x;
    }
}
int pop2()
{
    int element=stack2[top2];
    top2--;
    return element;
}
void enqueue(int x)
{
    push1(x);
    count++;
}
void dequeue()
{
    if(top1==-1 && top2==-1)
    {
        printf("\nQueue is empty");
    }
    else
    {
        for(int i=0;i<count;i++)
        {
            int element=pop1();
            push2(element);
        }
        int b=pop2();
        printf("\nThe dequeue element is %d",b);
        printf("\n");
        count--;
        for(int i=0;i<count;i++)
        {
            int a=pop2();
            push1(a);
        }
    }
}
void display()
{
    for(int i=0;i<=top1;i++)
    {
        printf("%d\n",stack1[i]);
    }
}
int main()
{
    int value,ch;
    do
    {
        p:
        printf("\n1.Enqueue\t2.Dequeue\t3.Display\t4.Exit");
        printf("\nEnter your Choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter a Value: ");
                scanf("%d",&value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Program Completed!!!!!");
                break;
            default :
                printf("\nWront input!!!!\nPlease enter a valid choice:");
                goto p;
        }
    } while (ch!=4);
    return 0;
}
