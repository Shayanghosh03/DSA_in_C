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
    printf("\nEnter the position where you want to delete: ");
    scanf("%d",&pos);
    for(i=pos-1;i<n;i++)
    {
        arr[i]=arr[i+1];
    }
    printf("\nThe Resultant array is:\n");
    for(i=0;i<n-1;i++)
    {
        printf("%d\t",arr[i]);
    }
    return 0;
}