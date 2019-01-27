#include<stdio.h>
main()
{
    int i,n,j,n1;
    scanf("%d",&n);
    n1 = 2*n-1;
    for(i=1;i<=n1;i++)
    {
        for(j=1;j<=n1;j++)
        {
            if(i==j || i+j==n1+1)
            {
                if(i>(n1/2)+1)printf("%d",n1-i+1);
                else printf("%d",i);
            }
            else printf(" ");
        }
        printf("\n");
    }
}

