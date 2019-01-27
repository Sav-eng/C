#include<stdio.h>
main()
{
    char a[30][30]={{}};
    int n,i,check=0,j;
    scanf("%d",&n);
    for(i=0;i<2*n;i++)
    {
        if(i<n)
        {
            a[n-i-1][i]='/';
        }
        else
        {
            check++;
            a[n-i+check-1][i]='\\';
            check++;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n*2;j++)
        {
            printf("%c",a[i][j]);
        }
        printf("\n");
    }
}
