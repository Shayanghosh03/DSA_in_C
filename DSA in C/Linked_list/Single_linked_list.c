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
    printf("\nEnter the Value: ");
    scanf("%d",&temp->data);
    temp->link=NULL;
    return temp;
}
void create_list(int n)
{
    int i;
    node *temp,*ptr;
    for(i=0;i<n;i++)
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
int countnode()
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
    }
    return c;
}
void insert_at_pos()
{
     node *temp, *ptr;
     int pos, nodectr, i ;
     temp = getnode();  
     printf("\n Enter the position: ");  
     scanf("%d", &pos);
     nodectr=countnode();  
     if(pos >(nodectr+1))
    {
          printf("\n Position is out of range..");  
          return;
    }
    else if(pos>1 && pos<=nodectr)
   {
        ptr=head;
        for(i=1;i<pos-1;i++)
        {
            ptr=ptr->link;
        }
        temp->link=ptr->link;
        ptr->link=temp;
   }
   else
   {
        printf("\n%d is not a intermediate position", pos);
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
void del_pos()
{
    int i, pos, nodectr;
    node *temp, *prev;  
    if(head == NULL)
    {
        printf("\n Empty List..");
        return ;
    }
    else
    {
        printf("\n Enter position of node to delete: ");  
        scanf("%d", &pos);
        nodectr = countnode();
        if(pos > nodectr)
        {
            printf("\nThis node doesnot exist");
        }
    
        else if (pos>1 && pos<=nodectr)
        {
        prev=NULL;
        temp=head;
        for(i=1;i<pos;i++)
        {
            prev=temp;
            temp = temp->link;
        }
        prev -> link = temp -> link; 
        printf("\nDeleted value is %d",temp->data);
        free(temp);
        }
        else
            printf("\n%d is not a intermediate position", pos);
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
        printf("\nThe contents of List:\n");
        ptr=head;
        while(ptr!=NULL)
        {
            printf("%d->",ptr->data);
            ptr=ptr->link;
        }
        printf("X");
    }
}
int main()
{
    int n,value,ch,count;
    do
    {
        p:
        printf("\n1.Create_list\t2.Add First\t3.Add Last\n4.Del First\t5.Del Last\t6.Addbyvalue_after\n7.Addbyvalue_afterpos\t8.Delby_value\t9.Display\n10.Count\t11.Insert_At_Pos\t12.Exit\n");
        printf("\nEnter Your Choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter the list number: ");
                scanf("%d",&n);
                create_list(n);
                break;
            case 2:
                printf("\nEnter a Number: ");
                scanf("%d",&value);
                add_first(value);
                break;
            case 3:
                printf("\nEnter a Number: ");
                scanf("%d",&value);
                add_last(value);
                break;
            case 4:
                del_first();
                break;
            case 5:
                del_last();
                break;
            case 6:
                addbyvalue_after();
                break;
            case 7:
                addbyvalue_afterpos();
                break;
            case 8:
                delby_value();
                break;
            case 9:
                display();
                break;
            case 10:
                count=countnode();
                printf("\nTotal node is %d",count);
                break;
            case 11:
                insert_at_pos();
                break;
            case 12:
                printf("\nProgram Complete!!!!\n");
                break;
            default:
                printf("\nInvalid Input\n");
                goto p;
        }
    }while(ch!=12);
    return 0;
}
