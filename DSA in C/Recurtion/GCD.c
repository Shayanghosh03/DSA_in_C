#include<stdio.h>
int gcd(int a,int b)
{
    if(b!=0)
    {
        return gcd(b,a%b);
    }
    else
    {
        return a;
    }
}
int main()
{
    int a,b,result;
    printf("\nEnter two numbwes:\n");
    scanf("%d %d",&a,&b);
    result=gcd(a,b);
    printf("\nGCD of %d & %d is %d",a,b,result);
    return 0;
}