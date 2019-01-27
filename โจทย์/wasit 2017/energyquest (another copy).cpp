#include<bits.stdc++.h>
using namespace std;
void bfs(int x,int l)
{
    vis[x] = 1;
    key[x] = l;
    for(i=0;i<from[x].size();i++)
    {
        if(!vis[from[x][i].x])bfs({from[x][i].x,l+1});
    }
}
int dfs(int x)
{

}
main()
{
    scanf("%d",&n);
    for(i=0;i<n-1;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        from[a].pushback({b,c});
        from[b].push_back({a,c});
    }
    scanf("%d%d%d",&s,&e,&r);
    bfs({r,0});
    memset(vis,0,sizeof vis);
    ans -= dfs(s)+dfs(e);
}
