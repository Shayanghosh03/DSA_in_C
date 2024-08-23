#include<stdio.h>
void TOH(int n, int a, int b, int c)
{
    if(n>0)
    {
        TOH(n-1,a,c,b);
        printf("\n%d to %d",a,c);
        TOH(n-1,b,a,c);
    }
}
int main()
{
    int n,a=1,b=2,c=3;
    printf("\nEnter the Disc numbers: ");
    scanf("%d",&n);
    TOH(n,a,b,c);
    return 0;
}