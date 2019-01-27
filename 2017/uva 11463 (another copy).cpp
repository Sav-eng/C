#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
int mem[101][101];
main()
{
    int timeall,n,m,i,time,j,a,b,s,e,k;
    int ans;
    scanf("%d",&time);
    timeall = time;
    while(time--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)for(j=0;j<n;j++)mem[i][j] = inf;
        for(i=0;i<n;i++)mem[i][i] = 0;
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            mem[a][b] = 1;
            mem[b][a] = 1;
        }
        scanf("%d%d",&s,&e);
        for(k=0;k<n;k++)
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    mem[i][j] = min(mem[i][j],mem[i][k]+mem[k][j]);
                    printf("mem[%d][%d] = %d\n",i,j,mem[i][j]);
                }
            }
        }
        ans = 0;
        for(i=0;i<n;i++)ans = max(ans,mem[s][i]+mem[i][e]);
        printf("Case %d: %d\n",timeall-time,ans);
    }
}

