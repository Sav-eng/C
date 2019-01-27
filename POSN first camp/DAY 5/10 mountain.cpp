#include<stdio.h>
main()
{
    int i,n,j,s=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            printf(" ");
        }
        printf("/");
        for(j=0;j<s;j++)
        {
            printf(" ");
        }
        printf("\\");
        printf("\n");
        s+=2;
    }
}
