//Stack implement using linkedlist
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h> 
typedef struct STACK
{
    int data;
    struct STACK *next;
} stack;
stack *head = NULL;
void push(int value)
{
    stack *temp;
    temp = (stack*)malloc(sizeof(stack)); 
    if(temp == NULL)
    {
        printf("\nNot able to push the element");
    }
    else
    {
        temp->data = value;
        temp->next = head;
        head = temp;
    }
}
void pop()
{
    int value;
    stack *temp;
    if(head == NULL)
    {
        printf("\nUnderflow");
    }
    else
    {
        temp = head;
        value = head->data;
        temp = temp->next; 
        free(temp);
        printf("\nDeleted value is %d", value); 
    }
}
void display()
{
    stack *ptr;
    ptr = head;
    if(ptr == NULL)
    {
        printf("\nStack is EMPTY");
    }
    else
    {
        printf("\nStack elements are:\n");
        while(ptr != NULL)
        {
            printf("%d\n", ptr->data);
            ptr = ptr->next;
        }
    }
}
int main()
{
    int ch, value;
    do
    {
        p:
        printf("\n1.PUSH\t2.POP\t3.DISPLAY\t4.EXIT:");
        printf("\nEnter the choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter the value: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nProgram Completed!!!!");
                break;
            default:
                printf("\nEnter the correct choice.....");
                goto p;
        }
    } while(ch != 4);
    return 0;
}
