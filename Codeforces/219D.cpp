#include<bits/stdc++.h>
using namespace std;
int mem[200001];
vector<int>from[200001];
vector<int>from2[200001];
int cost[200001];
void dfs(int u,int last)
{
    int i,v;
    cost[u] = cost[last]+1;

    for(i=0;i<from[u].size();i++)
    {
        v = from[u][i];
        if(v==last)continue;
        dfs(v,u);
    }
    for(i=0;i<from2[u].size();i++)
    {
        v = from2[u][i];
        if(v==last)continue;
        dfs(v,u);
    }

}
int dfs2(int u)
{
    int v,i;
    for(i=0;i<from[u].size();i++)
    {
        v = from[u][i];
        if(cost[v]<cost[u])continue;
        mem[u] += dfs2(v);
    }
    for(i=0;i<from2[u].size();i++)
    {
        v = from2[u][i];
        if(cost[v]<cost[u])continue;
        mem[u] += 1+dfs2(v);
    }
    return mem[u];
}
void dfs3(int u)
{
    int i,v;
    for(i=0;i<from[u].size();i++)
    {
        v = from[u][i];
        if(cost[v]<cost[u])continue;
        mem[v] = mem[u]+1;
        dfs3(v);
    }
    for(i=0;i<from2[u].size();i++)
    {
        v = from2[u][i];
        if(cost[v]<cost[u])continue;
        mem[v] = mem[u]-1;
        dfs3(v);
    }
}
vector<int>Ans[200001];
main()
{
    int n,i,a,b,ans;
    scanf("%d",&n);
    for(i=0;i<n-1;i++)
    {
        scanf("%d%d",&a,&b);
        from[a].push_back(b);
        from2[b].push_back(a);
    }
    dfs(1,0);
    dfs2(1);
    //for(i=1;i<=n;i++)printf("%d ",mem[i]);
    dfs3(1);
    ans = n;
    for(i=1;i<=n;i++)
    {
        ans = min(ans,mem[i]);
        Ans[mem[i]].push_back(i);
    }
    printf("%d\n",ans);
    for(i=0;i<Ans[ans].size();i++)
    {
        printf("%d ",Ans[ans][i]);
    }
}
