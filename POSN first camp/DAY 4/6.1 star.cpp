#include<stdio.h>
main()
{
    int n,i,j,check = 1;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n+n-check;j++)
        {
            printf("*");
        }
        printf("\n");
        check+=2;
        for(j=0;j<check/2;j++)printf(" ");
    }
}
