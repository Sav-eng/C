#include<stdio.h>
main()
{
    int a,b,c,sum;
    scanf("%d %d %d",&a,&b,&c);
    if(b-a>c-b)printf("%d",b-a-1);
    else
        printf("%d",c-b-1);
}
