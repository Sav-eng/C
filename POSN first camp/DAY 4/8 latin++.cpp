#include<stdio.h>
main()
{
    int x,i,y,j,z;
    scanf("%d %d %d",&x,&y,&z);
    for(i=1;i<=x;i++)
    {
        for(j=0;j<x;j++)
        {
            if(i+j>x)printf("%d",i+j-x);
            else printf("%d",i+j);
        }
        printf("\n");
    }
    sum =
}
