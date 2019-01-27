#include<stdio.h>
int fibo(int n)
{
    int a[100000],i=0,last;
    a[0]=1;
    a[1]=1;
    for(i=2;i<=n;i++)
    {
        a[i] = a[i-1]+a[i-2];
    }

    return a[i-1];
}
main()
{
    int n;
    scanf("%d",&n);
    printf("%d",fibo(n));
}
