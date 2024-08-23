#include<stdio.h>
#include<malloc.h>
typedef struct NODE
{
    int data;
    struct NODE *link;
}node;
node *head=NULL;
node *getnode()
{
    node *temp;
    temp=(node*)malloc(sizeof(node));
    printf("\nEnter the data: ");
    scanf("%d",&temp->data);
    temp->link=NULL;
    return temp;
}
void create_list(int n)
{
    node *temp,*ptr;
    for(int i=0;i<n;i++)
    {
        temp=getnode();
        if(head==NULL)
        {
            head=temp;
        }
        else
        {
            ptr=head;
            while(ptr->link!=NULL)
            {
                ptr=ptr->link;
            }
            ptr->link=temp;
        }
    }
}
void add_first(int value)
{
    node *temp=(node*)malloc(sizeof(node));
    temp->data=value;
    temp->link=head;
    head=temp;
}
void add_last(int value)
{
    node *ptr;
    node *temp=(node*)malloc(sizeof(node));
    temp->data=value;
    temp->link=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        ptr=head;
        while(ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        ptr->link=temp;
    }
}
void del_first()
{
    node *ptr;
    ptr=head;
    if(ptr==NULL)
    {
        printf("\nLinst is Blank");
    }
    else
    {
        printf("\nDeleted Value is %d",ptr->data);
        head=ptr->link;
        free(ptr);
    }
}
void del_last()
{
    node *ptr;
    node *ptr1;
    ptr=head;
    if(ptr==NULL)
    {
        printf("\nList is Blank");
    }
    else
    {
        if(ptr->link==NULL)
        {
            printf("Deleted Value is %d",ptr->data);
            head=ptr->link;
            free(ptr);
        }
        while(ptr->link->link!=NULL)
        {
            ptr=ptr->link;
        }
        ptr1=ptr->link;
        printf("\nDeleted Value is %d",ptr1->data);
        ptr->link=NULL;
        free(ptr1);
    }
}
void addbyvalue_after()
{
    int num,k;
    node *ptr,*temp;
    temp=(node*)malloc(sizeof(node));
    printf("\nEnter the value: ");
    scanf("%d",&num);
    temp->data=num;
    printf("\nEnter the value after which you want to add a node: ");
    scanf("%d",&k);
    if(head==NULL)
    {
        printf("\n List is Empty");
    }
    else
    {
        ptr=head;
        while(ptr->data!=k && ptr->link!=NULL)
        {
        ptr=ptr->link;
        }
        temp->link=ptr->link;
        ptr->link=temp;
    }
}
void addbyvalue_afterpos()
{
    int num,pos,c=1;
    node *ptr,*temp;
    temp=(node*)malloc(sizeof(node));
    printf("\nEnter the value: ");
    scanf("%d",&num);
    temp->data=num;
    printf("Enter position after which you want to add a node: ");
    scanf("%d",&pos);
    if(head==NULL)
    {
        printf("\nList is Empty");
    }
    else
    {
        ptr=head;
        while(c!=pos)
        {
            ptr=ptr->link;
            c++;
        }
        temp->link=ptr->link;
        ptr->link=temp;
    }
}
void delby_value()
{
    int k;
    node *ptr,*ptr1;
    ptr=head;
    if(head==NULL)
    {
        printf("\nList is Blank");
    }
    else
    {
        printf("\nEnter the value You want to delete: ");
        scanf("%d",&k);
        while(ptr->link->data!=k || ptr->link==NULL)
        {
            ptr=ptr->link;
        }
        ptr1=ptr->link;
        printf("\nDeleted Value is %d",ptr1->data);
        ptr->link=ptr1->link;
        free(ptr1);
    }
}
void count()
{
    node *ptr;
    int c=0;
    if(head==NULL)
    {
        printf("\nList is Blank");
    }
    else
    {
        ptr=head;
        while(ptr!=NULL)
        {
            ptr=ptr->link;
            c++;
        }
        printf("\nTotal Node is %d",c);
    }
}
void display()
{
    node *ptr;
    if(head==NULL)
    {
        printf("\nList is Blank");
    }
    else
    {
        ptr=head;
        while(ptr!=NULL)
        {
            printf("%d->",ptr->data);
            ptr=ptr->link;
        }
    }
}
int main()
{
    int n,value,ch;
    do
    {
        printf("\n0.Create_list\t1.Add First\t2.Add Last\t3.Del First\t4.Del Last\t5.Addbyvalue_after\t6.Addbyvalue_afterpos\t7.Delby_value\t8.Display\t9.Count\t10.Exit\n");
        printf("\nEnter Your Choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0:
                printf("Enter the list number: ");
                scanf("%d",&n);
                create_list(n);
                break;
            case 1:
                printf("\nEnter a Number: ");
                scanf("%d",&value);
                add_first(value);
                break;
            case 2:
                printf("\nEnter a Number: ");
                scanf("%d",&value);
                add_last(value);
                break;
            case 3:
                del_first();
                break;
            case 4:
                del_last();
                break;
            case 5:
                addbyvalue_after();
                break;
            case 6:
                addbyvalue_afterpos();
                break;
            case 7:
                delby_value();
                break;
            case 8:
                printf("\n");
                display();
                printf("\n");
                break;
            case 9:
                count();
                break;
            case 10:
                printf("\nProgram Complete!!!!\n");
                break;
            default:
                printf("\nInvalid Input\n");
        }
    }while(ch!=9);
    return 0;
}
