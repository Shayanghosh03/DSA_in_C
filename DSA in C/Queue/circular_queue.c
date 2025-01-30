#include<stdio.h>
#define N 5
int queue[N];
int front=-1;
int rear=-1;
void enqueue(int x)
{
    if(front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear]=x;
    }
    else if((rear+1)%N==front)
    {
        printf("\nQueue is Full!!!!");
    }
    else
    {
        rear=(rear+1)%N;
        queue[rear]=x;
    }
}
void delqueue()
{
    int data;
    if(front==-1)
    {
        printf("\nQueue is Empty");
    }
    else if(front==rear)
    {
        data=queue[front];
        front=rear=-1;
    }
    else
    {
        data=queue[front];
        front=(front+1)%N;
    }
    printf("\nDeleted value is %d",data);
}
void display()
{
    int i;
    if(front==-1)
    {
        printf("\nQueue is Empty");
    }
    else
    {
        for(i=front;i!=rear;i=(i+1)%N)
        {
            printf("%d\t",queue[i]);
        }
        printf("%d\t",queue[i]);
    }
}
int main()
{
    int ch,value;
    do
    {
        p:
        printf("\n1.Enqueue\t2.Dequeue\t3.Display\t4.Exit");
        printf("\nPlease enter the choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter the value: ");
                scanf("%d",&value);
                enqueue(value);
                break;
            case 2:
                delqueue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nProgram completed!!!!");
                break;
            default:
                printf("\nPlease enter the valid input:");
                goto p;
        }
    } while (ch!=4);
    return 0;
}