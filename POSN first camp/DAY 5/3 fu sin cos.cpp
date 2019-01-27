#include<stdio.h>
#include<math.h>
main()
{
    int i;
    double rad= M_PI/180;
    for(i=0;i<=90;i+=5) printf("x=%d sin = %.4lf cos = %.4lf\n",i,sin(rad*i),cos(rad*i));
}
