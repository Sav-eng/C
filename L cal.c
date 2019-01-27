#include<stdio.h>
#include<math.h>
main()
{
    float x,sum=0,y;
    int a,b;
    scanf("%d %d",&a ,&b);
    x = a;
    while(x>=a && x<b)
    {
        y = -pow(x,3)+pow(x,2)+1;
        if(y<0)y = -y;
        sum = sum + y*0.000001;
        x = x+0.000001;
    }
    printf("%lf",sum);
}
