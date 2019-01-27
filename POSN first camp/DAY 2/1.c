#include<stdio.h>
main()
{
    int a,b,c,sum;
    scanf("%d %d %d",&a,&b,&c);
    sum = a*40/100+b*20/100+c*40/100;
    if(sum>=50)printf("PASS");
    else
        printf("FAIL");
}
