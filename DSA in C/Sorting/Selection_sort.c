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
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void selection_sort(int x[])
{
    int i,j,min;
    for(i=0;i<size-1;i++)
    {
        min=i;
        for(j=i+1;j<size;j++)
        {
            if(x[j]<x[min])
            {
                min=j;
            }
        }
        if(min!=i)
        {
            swap(&x[i],&x[min]);
        }
    }
    printf("\nAfter sorted:\n");
    display(x);
}
int main()
{
    int a[size];
    printf("\nEnter the array elements:\n");
    insert(a);
    printf("\nBefore sorted array elements are:\n");
    display(a);
    selection_sort(a);
    return 0;
}