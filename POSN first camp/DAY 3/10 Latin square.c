#include<stdio.h>
main()
{
    int x,i,j;
    scanf("%d",&x);
    for(i=1;i<=x;i++)
    {
        for(j=0;j<x;j++)
        {
            if(i+j>x)printf("%d",i+j-x);
            else printf("%d",i+j);
        }
        printf("\n");
    }
}
