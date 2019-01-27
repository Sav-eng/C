#include<stdio.h>
main()
{
    int a,b,sum,c;
    scanf("%d %d",&a,&b);
    if(b==1)
    {
        c = 4;
    }
    if(b==2)
    {
        c = 0;
    }
    if(b==3)
    {
        c = 0;
    }
    if(b==4)
    {
        c = 3;

    }
    if(b==5)
    {
        c = 5;
    }
    if(b==6)
    {
        c = 1;
    }
    if(b==7)
    {
        c = 3;
    }
    if(b==8)
    {
        c = 6;
    }
    if(b==9)
    {
        c = 2;
    }
    if(b==10)
    {
        c = 4;
    }
    if(b==11)
    {
        c = 0;
    }
    if(b==12)
    {
        c = 2;
    }
    sum = a+c-1;
    sum %=7;
    if(sum==0)printf("Sunday");
    if(sum==1)printf("Monday");
    if(sum==2)printf("Tuesday");
    if(sum==3)printf("Wednesday");
    if(sum==4)printf("Thursday");
    if(sum==5)printf("Friday");
    if(sum==6)printf("Saturday");
}
