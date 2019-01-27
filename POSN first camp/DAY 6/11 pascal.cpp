#include<stdio.h>
main()
{
    int n,i,j,a[100][100],m;
    for(i=0;i<100;i++)
    {
        for(j=0;j<100;j++)
        {
            a[i][j] = 0;
        }
    }
    a[0][0]={1};
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=0;j<n-i+1;j++)
        {
            printf("      ");
        }
        for(j=1;j<=i;j++)
        {
            if(j==1||j==2*i-1)a[i][j]=1;
            a[i][j] = a[i-1][j-1]+a[i-1][j];
            printf("%12d",a[i][j]);
        }
        printf("\n");
    }
}
