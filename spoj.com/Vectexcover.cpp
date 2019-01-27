#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
int vis[100002][2];
vector<int>from[100002];
int mem[100002][2];
// 1 Choose
// 2 NotChoose
int dfs(int u,int check,int last)
{
    if(mem[u][check])return mem[u][check];
    int i,v;
    if(check==1)mem[u][check]++;
    for(i=0;i<from[u].size();i++)
    {
        v = from[u][i];
        if(v==last)continue;
        if(check==0) mem[u][check] += dfs(v,1,u);
        else mem[u][check] += min(dfs(v,1,u),dfs(v,0,u));
    }
    //printf("mem[%d][%d] = %d\n",u,check,mem[u][check]);
    return mem[u][check];
}
main()
{
    int n,i,a,b;
    scanf("%d",&n);
    //for(i=1;i<=n;i++)mem[i][0] = mem[i][1] = inf;
    for(i=0;i<n-1;i++)
    {
        scanf("%d%d",&a,&b);
        from[a].push_back(b);
        from[b].push_back(a);
    }
    printf("%d",min(dfs(1,0,0),dfs(1,1,0)));
}
