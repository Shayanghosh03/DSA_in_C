//Queue Implementation Using Linked List
#include<stdio.h>
#include<malloc.h>
typedef struct QUEUE
{
    int data;
    struct QUEUE *next;
}queue;
queue *front=NULL;
queue *rear=NULL;
void enqueu(int value)
{
    queue *temp;
    temp=(queue*)malloc(sizeof(queue));
    if(temp==NULL)
    {
        printf("\nOverflow");
    }
    else
    {
        temp->data=value;
        if(front==NULL)
        {
            front=temp;
            rear=temp;
            front->next=NULL;
            rear->next=NULL;
        }
        else
        {
            rear->next=temp;
            rear=temp;
            rear->next=NULL;
        }
    }
    
}
void dequeue()
{
    queue *temp;
    if(front==NULL)
    {
        printf("\nUnderflow");
    }
    else
    {
        temp=front;
        front=front->next;
        printf("\nDeleted value is: %d",temp->data);
        free(temp);
    }
}
void display()
{
    queue *temp;
    temp=front;
    if(front==NULL)
    {
        printf("\nEmpty Queue");
    }
    else
    {
        printf("\nQueue elements are:\n");
        while(temp!=NULL)
        {
            printf("%d->",temp->data);
            temp=temp->next;
        }
    }
    printf("X");
}
int main()
{
    int ch,value;
    do
    {
       printf("\n1.Enqueue\t2.Dequeue\n3.Display\t4.Exit");
       printf("\nPlease enter your choice: ");
       scanf("%d",&ch);
       switch(ch)
       {
            case 1:
                printf("\nEnter the value: ");
                scanf("%d",&value);
                enqueu(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nProgram Completed...");
                break;
            default :
                printf("\nPlease enter the correct choice...");
       }
    } while(ch!=4);
    return 0;
}