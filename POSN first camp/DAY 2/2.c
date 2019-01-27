#include<stdio.h>
main()
{
    float i=2000,check=0;
    while(i<=4000)
    {
        i = i*105/100;
        check++;
        printf("%.0f Year You get %f\n",check,i);
    }
    printf("%.0f",check);
}
