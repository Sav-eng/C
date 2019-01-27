#include<stdio.h>
main()
{
    double i=0,x1=0,x2=0,y1=0,y2=0,sum=0,area=0;
    while(i<10)
    {
        x1 = 0+i;
        x2 = 0.000001+i;
        y1 = x1*x1;
        y2 = x2*x2;
        i+=0.000001;
        area = ((y1+y2)/2)*0.000001;
        sum += area;
    }
    printf("%llf",sum);
}
