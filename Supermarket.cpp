#include<stdio.h>
#include<limits.h>
main()
{
    int n,m,x,j,ans,i,jj;
    int a[10000];
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        ans = INT_MAX;
        scanf("%d",&x);
        for(j=0;j<m;j++)
        {
            if(a[j]<ans)
            {
                ans = a[j];
                jj= j;
            }
        }
        printf("%d",jj+1);
        a[jj]+=x;
    }
}
