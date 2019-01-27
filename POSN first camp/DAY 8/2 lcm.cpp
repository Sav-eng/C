#include<stdio.h>
main()
{
    int a,b,max,i;
    scanf("%d %d",&a,&b);
    if(a>b)max=a;
    else max = b;
    for(i=max;i<=a*b;i++)
    {
        if(i%a==0&&i%b==0)break;
    }
    printf("%d",i);
}
