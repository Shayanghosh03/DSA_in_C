#include<stdio.h>
#include<malloc.h>
typedef struct dlinkedlist
{
    struct dlinkedlist *right;
    int data;
    struct dlinkedlist *left;
}node;
node *start=NULL;
node *getnode()
{
    node *newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("\nEnter the value: ");
    scanf("%d",&newnode->data);
    newnode->left=NULL;
    newnode->right=NULL;
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
            while(temp->right!=NULL)
            {
                temp=temp->right;
            }
            temp->right=newnode;
            newnode->left=temp;
        }
    }
}
void dll_insert_beg()
{
    node *newnode;
    newnode=getnode();
    if(start==NULL)
    {
        start=newnode;
    }
    else
    {
        newnode->right=start;
        start->left=newnode;
        start=newnode;
    }
}
void dll_insert_end()
{
    node *newnode,*temp;
    newnode=getnode();
    if(start==NULL)
    {
        start=newnode;
    }
    else
    {
        temp=start;
        while(temp->right!=NULL)
        {
            temp=temp->right;
        }
        temp->right=newnode;
        newnode->left=temp;
    }
}
int count_node()
{
    int count=1;
    node *temp;
    if(start==NULL)
    {
        printf("\nList is Blank");
    }
    else
    {
        temp=start;
        while(temp->right!=NULL)
        {
            count++;
            temp=temp->right;
        }
    }
    return count;
}
void dll_insert_imp()
{
    node *newnode,*temp;
    int pos,nodectr,i;
    newnode=getnode();
    printf("\nEnter the position: ");
    scanf("%d",&pos);
    nodectr=count_node();
    if(pos>(nodectr+1))
    {
        printf("\nPosition is out of range...");
    }
    else if(pos>1 && pos<=nodectr)
    {
        temp=start;
        for(i=1;i<pos-1;i++)
        {
            temp=temp->right;
        }
        newnode->right=temp->right;
        temp->right->left=newnode;
        temp->right=newnode;
        newnode->left=temp;
    }
    else
    {
        printf("\n%d is not intemediate position...",pos);
    }
}
void dll_del_beg()
{
    node *temp;
    if(start==NULL)
    {
        printf("\nList is Blank...");
    }
    else
    {
        temp=start;
        start=temp->right;
        if(start!=NULL)
        {
            start->left=NULL;
        }
        printf("\nDeleted value is %d",temp->data);
        free(temp);
    }
}
void dll_del_end()
{
    node *temp;
    if(start==NULL)
    {
        printf("\nList is Blank");
    }
    else
    {
        temp=start;
        while(temp->right!=NULL)
        {
            temp=temp->right;
        }
        temp->left->right=NULL;
        printf("\nDeleted value is %d",temp->data);
        free(temp);
    }
}
void dll_del_imp()
{
    int pos,nodectr,i;
    node *temp;
    if(start==NULL)
    {
        printf("\nList is Blank....");
    }
    else
    {
        printf("\nEnter the position of the node to delete: ");
        scanf("%d",&pos);
        nodectr=count_node();
        if(pos>nodectr)
        {
            printf("\nThis node does not exist..");
        }
        else if(pos>1 && pos<nodectr)
        {
            temp=start;
            for(i=1;i<pos;i++)
            {
                temp=temp->right;
            }
            temp->right->left=temp->left;
            temp->left->right=temp->right;
            printf("\nDeleted value is %d",temp->data);
            free(temp);
        }
        else
        {
            printf("\n%d position is not a intermediate position..",pos);
        }
    }
}
void display_lr()
{
    node *temp;
    temp=start;
    printf("\nThe contants of lists are:\n");
    if(start==NULL)
    {
        printf("\nEmpty List");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d<->",temp->data);
            temp=temp->right;
        }
    }
    printf("X");
}
void display_rl()
{
    node *temp;
    temp=start;
    printf("\nThe contents of lists are:\n");
    if(start==NULL)
    {
        printf("\nEmpty List...");
    }
    else
    {
        while(temp->right!=NULL)
        {
            temp=temp->right;
        }
        while(temp!=NULL)
        {
            printf("%d->",temp->data);
            temp=temp->left;
        }
    }
    printf("X");
}
int main()
{
    int n,ch,count;
    do
    {
        p:
        printf("\n1.Create_list\t2.Add First\t3.Add Last\n4.Del First\t5.Del Last\t6.Add_imp\n7.Del_imp\t8.Node_count\t9.Display\n10.Reverse\t11.Exit");
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
                dll_insert_beg();
                break;
            case 3:
                dll_insert_end();
                break;
            case 4:
                dll_del_beg();
                break;
            case 5:
                dll_del_end();
                break;
            case 6:
                dll_insert_imp();
                break;
            case 7:
                dll_del_imp();
                break;
            case 8:
                count=count_node();
                printf("\nTotal Node is %d",count);
                break;
            case 9:
                printf("\n");
                display_lr();
                printf("\n");
                break;
            case 10:
                printf("\n");
                display_rl();
                printf("\n");
                break;
            case 11:
                printf("\nProgram Complete!!!!\n");
                break;
            default:
                printf("\nInvalid Input\n");
                goto p;
        }
    }while(ch!=11);
    return 0;
}
