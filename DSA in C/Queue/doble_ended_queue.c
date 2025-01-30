#include<stdio.h>
int queue[5];
int max=5;
int front=-1;
int rear=-1;
void insert_front(int data)
{
    if(front==0)
    {
        printf("\nQueue is Full");
    }
    else
    {
        if(front==-1 && rear==-1)
        {
            front=rear=0;
        }
        else
        {
            front--;
        }
        queue[front]=data;
    }
}
void insert_rear(int data)
{
    if(rear==max-1)
    {
        printf("\nQueue if Full");
    }
    else
    {
        if(front==-1 && rear==-1)
        {
            front=rear=0;
        }
        else
        {
            rear++;
        }
        queue[rear]=data;
    }
}
void deletion_front()
{
    int data;
    if(front==-1)
    {
        printf("\nQueue is Empty");
    }
    else
    {
        data=queue[front];
        if(front==rear)
        {
            front=rear=-1;
        }
        else
        {
            front++;
        }
        printf("\nDeleted value is %d",data);
    }
}
void deletion_rear()
{
    int data;
    if(rear==-1)
    {
        printf("\nQueue is Empty");
    }
    else
    {
        data=queue[rear];
        if(front==rear)
        {
            front=rear=-1;
        }
        else
        {
            rear--;
        }
        printf("\nDeleted value is %d",data);
    }
}
void display()
{
    int i;
    if(front==-1 && rear==-1)
    {
        printf("\nQueue is Empty");
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
    int ch,value;
    do
    {
        printf("\n1.Insert_Front\t2.Delet_Front\n3.Insert_Rear\t4.Delete_Rear\n5.Display\t6.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter the value: ");
                scanf("%d",&value);
                insert_front(value);
                break;
            case 2:
                deletion_front();
                break;
            case 3:
                printf("\nEnter the value: ");
                scanf("%d",&value);
                insert_rear(value);
                break;
            case 4:
                deletion_rear();
                break;
            case 5:
                printf("\nThe Deque contents are: ");
                display();
                break;
            case 6:
                printf("\nProgram completed.....");
                break;
            default :
                printf("\nEnter the correct choice.....");
        }
    }while(ch!=6);
return 0;
}