#include<bits/stdc++.h>
using namespace std;
int vis[10001];
vector<int>from[10001];
int dfs(int x)
{
    int i,ans=0;
    vis[x] = 1;
    for(i=0;i<from[x].size();i++)if(!vis[from[x][i]])ans+=dfs(from[x][i])+1;
    return ans;
}
main()
{
    //freopen("out.txt","w",stdout);
    int time,a,b,n,m,k,i,j,ans=0;
    scanf("%d",&time);
    while(time--)
    {
        scanf("%d%d%d",&n,&m,&k);
        for(i=0;i<=n;i++)from[i].clear();
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            from[a].push_back(b);
        }
        memset(vis,0,sizeof(vis));
        ans=0;
        for(i=0;i<k;i++)
        {
            scanf("%d",&a);
            //memset(vis,0,sizeof(vis));
            if(!vis[a])ans += dfs(a)+1;
        }
        printf("%d\n",ans);
    }
}
