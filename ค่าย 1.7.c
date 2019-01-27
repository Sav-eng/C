#include<stdio.h>
main()
{
    long long i,a=0,b=0,c=0;
    for(i=0;i<=5000;i++)
    {
        if(i%18==0)a=a+i;
    }
    for(i=0;i<=5000;i++)
    {
        if(i%2==0)b=b+i;
    }
    for(i=0;i<=5000;i++)
    {
        if(i%9==0)c=c+i;
    }
    printf("%lld",c+b-a);

}

