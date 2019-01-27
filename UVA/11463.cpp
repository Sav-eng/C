#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
int mem[101][101];
main()
{
    int T,a,b,i,j,k,n,m,time=0,ans,s,e;
    scanf("%d",&T);
    while(T--)
    {
        ans = 0;
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)for(j=0;j<n;j++)mem[i][j] = (i==j)?0:inf;
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            mem[a][b] = 1;
            mem[b][a] = 1;
        }
        scanf("%d%d",&s,&e);
        for(k=0;k<n;k++)for(i=0;i<n;i++)for(j=0;j<n;j++)mem[i][j] = min(mem[i][j],mem[i][k]+mem[k][j]);
        for(i=0;i<n;i++)ans = max(ans,mem[s][i]+mem[i][e]);
        printf("Case %d: %d\n",++time,ans);
    }
}
