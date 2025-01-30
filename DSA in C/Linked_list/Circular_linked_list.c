#include<stdio.h>
#include<malloc.h>
typedef struct clinkedlist
{
    int data;
    struct clinkedlist *next;
}node;
node *start=NULL;
node *getnode()
{
    node *newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("\nEnter the value: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    return newnode;
}
void create_list(int n)
{
    int i;
    node *newnode,*temp;
    for(i=0;i<n;i++)
    {
        newnode=getnode();
        if(start==NULL)
        {
            start=newnode;
        }
        else
        {
            temp=start;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
        }
    }
    newnode->next=start;
}
void cll_inser_beg()
{
    node *newnode,*last;
    newnode=getnode();
    if(start==NULL)
    {
        start=newnode;
        newnode->next=start;
    }
    else
    {
        last=start;
        while(last->next!=start)
        {
            last=last->next;
        }
        newnode->next=start;
        start=newnode;
        last->next=newnode;
    }
}
void cll_insert_end()
{
    node *newnode,*temp;
    newnode=getnode();
    if(start==NULL)
    {
        start=newnode;
        newnode->next=start;
    }
    else
    {
        temp=start;
        while(temp->next!=start)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=start;
    }
}
int count_node()
{
    int count=1;
    node *temp;
    temp=start;
    do
    {
        count++;
        temp=temp->next;
    } while (temp->next!=start);
    return count;
}
void cll_insert_imp()
{
    node *newnode,*temp;
    int i,pos,nodectr;
    newnode=getnode();
    nodectr=count_node();
    printf("\nEnter the position: ");
    scanf("%d",&pos);
    if(pos>(nodectr+1))
    {
        printf("\nPosition is out of range....");
    }
    else if(pos>1 && pos<=nodectr)
    {
        temp=start;
        for(i=1;i<pos-1;i++)
        {
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
    else
    {
        printf("\n%d position is not a intermediate position...",pos);
    }
}
void cll_del_beg()
{
    node *temp,*first;
    if(start==NULL)
    {
        printf("\nList is Blank....");
    }
    else
    {
        first=temp=start;
        while(temp->next!=start)
        {
            temp=temp->next;
        }
        start=first->next;
        temp->next=start;
        printf("\nDeleted value is %d",first->data);
        free(first);
    }
}
void cll_del_end()
{
    node *temp,*last;
    if(start==NULL)
    {
        printf("\nList is Blank....");
    }
    else
    {
        last=temp=start;
        while(temp->next!=start)
        {
            last=temp;
            temp=temp->next;
        }
        last->next=start;
        printf("\nDeleted value is %d",temp->data);
        free(temp);
    }
}
void cll_del_imp()
{
    int i,pos,nodectr;
    node *temp,*prev;
    if(start==NULL)
    {
        printf("\nEmty list...");
    }
    else
    {
        printf("\nEnter position of node to delete: ");
        scanf("%d",&pos);
        nodectr=count_node();
        if(pos>nodectr)
        {
            printf("\nThis node doesnot exist...");
        }
        else if(pos>1 && pos<=nodectr)
        {
            prev=temp=start;
            for(i=1;i<pos;i++)
            {
                prev=temp;
                temp=temp->next;
            }
            prev->next=temp->next;
            printf("\nDeleted value is %d",temp->data);
            free(temp);
        }
    }
}
void display()
{
    node *temp;
    temp=start;
    printf("\nThe contents of the list(left to right):\n");
    if(start==NULL)
    {
        printf("\nList is Blank");
    }
    else
    {
        do
        {
            printf("%d->",temp->data);
            temp=temp->next;
        } while (temp!=start);
    }
    printf("x");
}
int main()
{
    int n,ch,count;
    do
    {
        printf("\n1.Create_list\t2.Add First\t3.Add Last\n4.Del First\t5.Del Last\t6.Add_imp\n7.Del_imp\t8.Node_count\t9.Display\n10.Exit\n");
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
                cll_inser_beg();
                break;
            case 3:
                cll_insert_end();
                break;
            case 4:
                cll_del_beg();
                break;
            case 5:
                cll_del_end();
                break;
            case 6:
                cll_insert_imp();
                break;
            case 7:
                cll_del_imp();
                break;
            case 8:
                count=count_node();
                printf("\nTotal Node is %d",count);
                break;
            case 9:
                printf("\n");
                display();
                printf("\n");
                break;
            case 10:
                printf("\nProgram Complete!!!!\n");
                break;
            default:
                printf("\nInvalid Input\n");
        }
    }while(ch!=10);
    return 0;
}
