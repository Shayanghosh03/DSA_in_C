#include<stdio.h>
#define n 5
int queue[n];
int front=-1;
int rear=-1;
void enqueue(int data)
{
    if(rear==n-1)
    {
        printf("\nQueue is FULL");
    }
    else
    {
        rear++;
        queue[rear]=data;
        if(front==-1)
        {
            front=0;
        }
    }
}
void dequeue()
{
    int data;
    if(front==-1)
    {
        printf("\nQueue is EMPTY");
    }
    else if(front==rear)
    {
        data=queue[front];
        front=rear=-1;
    }
    else
    {
        data=queue[front];
        front++;
    }
    printf("\nDeleted value is %d",data);
}
void display()
{
    int i;
    if(front==-1)
    {
        printf("\nQueue is EMPTY");
    }
    else
    {
        for(i=front;i<=rear;i++)
        {
            printf("%d\t",queue[i]);
        }
    }
}
int main()
{
    int ch,data;
    do
    {
       printf("\n1.Insert\t2.Delete\t3.Display\t4.Exit\n");
       printf("\nEnter Your Choce: ");
       scanf("%d",&ch);
       switch(ch)
       {
        case 1:
            printf("Enter a Value: ");
            scanf("%d",&data);
            enqueue(data);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\nProgramming Completed!!!!!");
            break;
        default :
            printf("\nInvalid Input\n");
       }
    } while (ch!=4);
    return 0;
}