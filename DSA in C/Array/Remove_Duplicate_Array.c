#include<stdio.h>
#define size 100
int main()
{
    int i,j,k,key,n;
    int arr[size];
    int count=0;
    printf("\nEnter the size of the array: ");
    scanf("%d",&n);
    printf("\nEnter the array elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nArray elements are:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    i=0;
    while(i<n)
    {
        key=arr[i];
        for(j=i+1;j<n;j++)
        {
            if(key==arr[j])
            {
                count++;
                 
                for(k=j;k<n-1;k++)
                {
                    arr[k]=arr[k+1];
                }
               n--;
               j--;
            }
        }
        i++;
    }
    printf("\nDuplicate numbers are = %d",count);
    printf("\nFinal Array is: ");
    for (i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}