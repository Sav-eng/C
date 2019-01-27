#include<stdio.h>
main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(j<n-i)printf(" ");
            else printf("*");
        }
        printf("\n");
    }
}
