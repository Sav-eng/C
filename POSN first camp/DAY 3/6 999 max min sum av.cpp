#include<stdio.h>
main()
{
    int sum=0,max=-9999999,min=999999,av,i,x;
    while(x!=999)
    {
        scanf("%d",&x);
        if(x==999)break;
        sum+=x;
        if(max<x)max=x;
        if(min>x)min=x;
    }
    av = sum/20;
    printf("min is %d max is %d sum is %d av is %d",min,max,sum,av);
}
