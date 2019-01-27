#include<bits/stdc++.h>
using namespace std;
int mem[101];
vector<int>from[101];
int check;
int vis[101];
void dfs(int x)
{
    int i;
    vis[x] = 1;
    for(i=0;i<from[x].size();i++)if(!vis[from[x][i]])dfs(from[x][i]);
    mem[check--]=x;
}
main()
{
    //freopen("out.txt","w",stdout);
    int n,m,i,a,b;
    while(scanf("%d%d",&n,&m)&&n&&m)
    {
        memset(mem,0,sizeof(mem));
        memset(vis,0,sizeof(vis));
        for(i=1;i<=n;i++)from[i].clear();
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            from[a].push_back(b);
        }
        check = n-1;
        for(i=1;i<=n;i++)if(!vis[i])dfs(i);
        printf("%d",mem[0]);
        for(i=1;i<n;i++)printf(" %d",mem[i]);
        printf("\n");
    }
}
