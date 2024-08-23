#include<stdio.h>
#define size 5
void insert(int x[])
{
    int i;
    for(i=0;i<size;i++)
    {
        scanf("%d",&x[i]);
    }
}
void display(int x[])
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("%d\t",x[i]);
    }
}
void b_sort(int x[])
{
    int i,j,temp;
    for(i=0;i<size-1;i++)
    {
        for(j=0;j<size-1;j++)
        {
            if(x[j]>x[j+1])
            {
                temp=x[j];
                x[j]=x[j+1];
                x[j+1]=temp;
            }
        }
    }
    printf("\nAfter Sorting:\n");
    display(x);
}
int main()
{
    int a[size];
    printf("Entter the Array Elements:\n");
    insert(a);
    printf("Array Elements are:\n");
    display(a);
    b_sort(a);
    return 0;
}