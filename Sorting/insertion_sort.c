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
void insertion(int x[])
{
    int i,j,temp;
    for(i=1;i<size;i++)
    {
        temp=x[i];
        j=i-1;
        while(j>=0 && x[j]>temp)
        {
            x[j+1]=x[j];
            j--;
        }
        x[j+1]=temp;
    }
    printf("\nAfter Sorting:\n");
    display(x);
}
int main()
{
    int a[size];
    printf("Enter the Array Elements:\n");
    insert(a);
    printf("\nArray Elements are:\n");
    display(a);
    insertion(a);
    return 0;
}