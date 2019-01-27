#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,val;
};
bool vis[100002];
int key[100002];
int tab[100002];
int r;
vector<node>from[100002];
void bfs(int x,int l)
{
    int i;
    vis[x] = 1;
    key[x] = l;
    for(i=0;i<from[x].size();i++)
    {
        if(!vis[from[x][i].x])bfs(from[x][i].x,l+1);
    }
}
long long dfs(int x)
{
    vis[x] = 1;
    int i;
    if(x==r)return 0;
    for(i=0;i<from[x].size();i++)
    {
        if(key[from[x][i].x]<key[x])return from[x][i].val + dfs(from[x][i].x);
    }
}
long long dfs2(int x)
{
    vis[x] = 1;
    int i;
    long long t=0;
    for(i=0;i<from[x].size();i++)
    {
        if(key[from[x][i].x] > key[x] && !vis[from[x][i].x]) t += max((long long)0,tab[from[x][i].x]-from[x][i].val*2+dfs2(from[x][i].x));
    }
    return t;
}
main()
{
    int n,i,a,b,c,s,e;
    long long ans=0;
    scanf("%d",&n);
    for(i=0;i<n-1;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        from[a].push_back({b,c});
        from[b].push_back({a,c});
    }
    for(i=1;i<=n;i++)scanf("%d",&tab[i]);
    scanf("%d%d%d",&s,&e,&r);
    bfs(r,0);
    memset(vis,0,sizeof(vis));
    ans -= dfs(s)+dfs(e);
    //printf("%lld ",ans);
    for(i=1;i<=n;i++)
    {
        if(vis[i])ans += tab[i];
    }
    //printf("%lld ",ans);
    for(i=1;i<=n;i++)
    {
        if(vis[i])ans += dfs2(i);
    }
    printf("%lld",ans);

}
/*
8
1 2 1
2 3 1
3 4 1
3 5 1
3 6 1
2 7 1
6 8 1
1 1 1 3 3 3 1 3
1 7 3
ans = 4
*/
/*
4
1 2 4
1 3 5
2 4 2
7 5 6 4
3 4 2
ans = 11
*/
/*
4
1 2 2
2 3 7
2 4 1
10 7 4 5
1 4 3
ans = 9
*/
/*
10
1 2 1
2 3 1
3 4 1
3 5 1
3 6 1
2 7 1
6 8 1
8 9 10
9 10 0
1 1 1 3 3 3 1 3 0 10000
1 7 3
ans = 9984
*/
