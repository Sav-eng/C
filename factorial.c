#include<stdio.h>
int factorial(int n)
{
    int sum=1,i;
    for(i=n;i>0;i--)
    {
        sum =sum*i;
    }
    return sum;
}
main()
{
    int n=0;
    scanf("%d",&n);
    printf("%d",factorial(n));
}
