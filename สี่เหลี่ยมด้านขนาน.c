#include<stdio.h>
main()
{
    int i,n,j,b;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            printf(" ");
        }
        printf("%d",i+1);
        if(i!=0)
        {
            for(j=0;j<2*i-1;j++)
            {
                printf(" ");
            }
            printf("%d",i+1);
        }
        printf("\n");
    }
    b = ((n-3)*2)+1;
    for(i=2;i<n+1;i++)
    {
        if(i!=n)
        {
            for(j=0;j<i-1;j++)
            {
                printf(" ");
            }
            printf("%d",n-i+1);
            for(j=0;j<b;j++)
            {
                printf(" ");
            }
            printf("%d",n-i+1);
        }
        if(i==n)
        {
            for(j=0;j<n-1;j++)
            {
                printf(" ");
            }
            printf("%d",n-i+1);
        }
        printf("\n");
        b = b-2;

    }
}
