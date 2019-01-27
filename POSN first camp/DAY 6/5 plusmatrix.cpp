#include<stdio.h>
main()
{
    int i,j,n=3,a[3][3],b[3][3],c[3][3];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            c[i][j] = a[i][j]+b[i][j];
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
}
