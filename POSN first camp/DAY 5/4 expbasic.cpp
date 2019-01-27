#include<stdio.h>
#include<math.h>
main()
{
    double i;
    for(i=0;i<=10;i+=0.5)
    {
        printf("e^%lf = %lf \n",i,exp(i));
    }
}
