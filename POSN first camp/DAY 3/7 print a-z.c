#include<stdio.h>
main()
{
    int x,i;
    scanf("%d",&x);
    for(i=0;i<x+1;i++)
    {
        printf("%c",i+'A');
    }
}
