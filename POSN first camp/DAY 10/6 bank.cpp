#include<stdio.h>
main()
{
    double i,n,j;
    scanf("%lf",&n);
    i=n;
    for(j=1;j<=14;j++)
    {
        if(j<=5)
        {
            i = i *1.02;
            i = i+n;
        }
        else if(j==6 || j==8|| j==10|| j==12)
        {
            i = i*1.02;
            i = i-n*0.1;
        }
        else
        {
            i = i*1.02;
        }
        printf("%lf\n",i);

    }
    printf("%lf",i);
}
