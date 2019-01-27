#include<stdio.h>
main()
{
    int n,i;
    int fib1,fib0,fib2;
    scanf("%d",&n);
    fib0 = 0;
    fib1 = 1;
    for(i=1;i<n;i++)
    {
        fib2 = fib0+fib1;
        fib0=fib1;
        fib1=fib2;
    }
    printf("%d",fib2);
}
