#include<stdio.h>
int fact(int n)
{
    if(n==0)
    {
        return 1;
    }
    else
    {
        return n*fact(n-1);
    }
}
int main()
{
    int n,result;
    printf("\nEnter a number: ");
    scanf("%d",&n);
    result=fact(n);
    printf("Factorial of %d is %d",n,result);
    return 0;
}