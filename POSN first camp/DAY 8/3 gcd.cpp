#include<stdio.h>
main()
{
    int a,b,min,i;
    scanf("%d %d",&a,&b);
    if(a>b)min = b;
    else min = a;
    for(i=min;i>0;i--)
    {
        if(a%i==0 && b%i==0)break;
    }
    printf("%d",i);
}

