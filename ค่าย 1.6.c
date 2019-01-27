#include<stdio.h>
main()
{
    int i,a;
    for(i=0;i<=100000;i++)
    {
        if(i%18==0)a=a+i;
    }
    printf("%d",a);
}
