#include<stdio.h>
main()
{
    int i=0;
    float n;
    scanf("%f",&n);
    while(n<30000)
    {
        n = n*103/100;
        printf("%f \n",n);
        i++;
    }
    printf("%d",i);
}
