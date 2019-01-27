#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,ord;
};
vector<node>from[26];
int last;
int _max=0;
int vis[26];
void dfs(int x,int y)
{
    int i;
    for(i=0;i<from[x].size();i++)
    {
        if(!vis[from[x][i].ord])
        {
            vis[from[x][i].ord]=1;
            dfs(from[x][i].x,y+1);
            vis[from[x][i].ord]=0;
        }
        else last = max(last,x),_max = max(_max,y);
    }
}
main()
{
    int n,m,i,a,b;
    while(scanf("%d%d",&n,&m)&&n&&m)
    {
        memset(vis,0,sizeof(vis));
        for(i=0;i<=25;i++)from[i].clear();
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            from[a].push_back({b,i});
            from[b].push_back({a,i});
        }
        last = 0; _max = 0;
        for(i=0;i<n;i++)dfs(i,0);
        //dfs(last,0);
        printf("%d\n",_max);
    }
}
