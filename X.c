#include<stdio.h>
main()
{
    int n,i,j,b,c;
    scanf("%d",&n);
    b = 2;
    for(i=0;i<n/2;i++)
    {
        for(j=0;j<i;j++)
        {
            printf(" ");
        }
        printf("%d",i+1);
        for(j=0;j<n-b;j++)
        {
            printf(" ");
        }
        printf("%d",i+1);
        printf("\n");
        b = b+2;
    }
    for(i=0;i<n/2;i++)
    {
        printf(" ");
    }
    printf("%d",(n/2)+1);
    printf("\n");
    b = n-1;
    c = n/2;
    for(i=n;i>(n+1)/2;i--)
    {
        for(j=0;j<i-c-2;j++)
        {
            printf(" ");
        }
        printf("%d",i-c-1);
        b = b-2;
        for(j=0;j<n-b-2;j++)
        {
            printf(" ");
        }
        printf("%d",i-c-1);
        printf("\n");
    }
}
