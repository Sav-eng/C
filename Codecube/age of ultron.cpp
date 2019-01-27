#include<stdio.h>
int a[1005][1005];
main()
{
    int n,m,i,j,k;
    scanf("%d %d",&n,&m);
    scanf("%d",&k);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=n-1;i>=0;i--)
    {
        for(j=0;j<m;j++)
        {
            if(a[i][j]==0)k--;
            if(k<=0)break;
        }
        if(k<=0)break;
    }
    printf("%d",i+1);
}
