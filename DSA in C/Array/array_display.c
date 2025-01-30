#include<stdio.h>
int main()
{
    int arr[10],i,n,pos;
    printf("\nEnter size of the array: ");
    scanf("%d",&n);
    printf("\nEnter the numbers of the array:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nArray elemnts are:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    return 0;
}