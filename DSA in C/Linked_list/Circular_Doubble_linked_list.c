#include<stdio.h>
#include<malloc.h>
typedef struct cdlinkedlist
{
    int data;
    struct cdlinkedlist *left;
    struct cdlinkedlist *right;
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
}
void create_list(int n)
{
    int i;
    node *newnode;
    for(i=0;i<n;i++)
    {
        newnode=getnode();
        if(start==NULL)
        {
            start=newnode;
            newnode->right=start;
            newnode->left=start;
        }
        else
        {
            newnode->left=start->left;
            newnode->right=start;
            newnode->left->right=newnode;
            start->left=newnode;
        }
    }
}
void cdll_insert_beg()
{
    node *newnode;
    newnode=getnode();
    if(start==NULL)
    {
        start=newnode;
        newnode->left=start;
        newnode->right=start;
    }
    else
    {
        newnode->left=start->left;
        newnode->right=start;
        start->left->right=newnode;
        start->left=newnode;
        start=newnode;
    }
}
void cdll_insert_end()
{
    node *newnode;
    newnode=getnode();
    if(start==NULL)
    {
        start=newnode;
        newnode->left=start;
        newnode->right=start;
    }
    else
    {
        newnode->left=start->left;
        start->left->right=newnode;
        newnode->right=start;
        start->left=newnode;
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
        temp=temp->right;
    } while (temp->right!=start);
    return count;
}
void cdll_insert_imp()
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
        newnode->left=temp;
        temp->right=newnode;
    }
    else
    {
        printf("\n%d position is not intermediate position..",pos);
    }
}
void cdll_del_beg()
{
    node *temp;
    if(start==NULL)
    {
        printf("\nList is Blank");
    }
    else
    {
        temp=start;
        start=start->right;
        temp->left->right=start;
        start->left=temp->left;
        printf("\nDeleted value is %d",temp->data);
        free(temp);
    }
}
void cdll_del_end()
{
    node *temp;
    if(start==NULL)
    {
        printf("\nList is Blank");
    }
    else
    {
        temp=start->left;
        temp->left->right=start;
        start->left=temp->left;
        printf("\nDeleted value is %d",temp->data);
        free(temp);
    }
}
void cdll_del_imp()
{
    int pos,nodectr;
    node *temp;
    if(start==NULL) 
    {
        printf("\nList is Blank");
    }
    else
    {
        printf("\nEnter the position: ");
        scanf("%d",&pos);
        nodectr=count_node();
        if(pos>nodectr)
        {
            printf("\nThis node does't exist..");
        }
        else if(pos>1 && pos<=nodectr)
        {
            int i=1;
            temp=start;
            while(i<pos)
            {
                temp=temp->right;
                i++;
            }
            temp->right->left=temp->left;
            temp->left->right=temp->right;
            printf("\nDeleted value is %d",temp->data);
            free(temp);
        }
        else
        {
            printf("%d position is not a intermediate position..");
        }
    }
}
void display_lr()
{
    node *temp;
    if(start==NULL)
    {
        printf("\nList is Blank");
    }
    else
    {
        temp=start;
        do
        {
            printf("%d<->",temp->data);
            temp=temp->right;
        } while (temp!=start);
    }
    printf("X");
}
void display_rl()
{
    node *temp;
    if(start==NULL)
    {
        printf("\nList is Blank");
    }
    else
    {
        temp=start->left;
        while(temp!=start)
        {
            printf("%d<->",temp->data);
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
                cdll_insert_beg();
                break;
            case 3:
                cdll_insert_end();
                break;
            case 4:
                cdll_del_beg();
                break;
            case 5:
                cdll_del_end();
                break;
            case 6:
                cdll_insert_imp();
                break;
            case 7:
                cdll_del_imp();
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