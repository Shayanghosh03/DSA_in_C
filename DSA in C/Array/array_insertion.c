#include<stdio.h>
int main()
{
    int arr[10],i,n,val,pos;
    printf("\nEnter size of the array: ");
    scanf("%d",&n);
    printf("\nEnter the numbers of the array:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nEnter the new element which you want to insert: ");
    scanf("%d",&val);
    printf("\nEnter the position where you want to insert: ");
    scanf("%d",&pos);
    for(i=n-1;i>=pos-1;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[pos-1]=val;
    printf("\nThe Resultant array is:\n");
    for(i=0;i<=n;i++)
    {
        printf("%d\t",arr[i]);
    }
    return 0;
}