#include<bits/stdc++.h>
using namespace std;
const long long inf = 1e16;
const int MAXN = 2e5+1;
long long mem[MAXN];
long long mem2[MAXN];
long long ans;
int a[MAXN];
vector<int>from[MAXN];
void dfs(int u,int last)
{
    mem[u] = a[u];
    int i;
    vector<int>tmp;
    for(i=0;i<from[u].size();i++)
    {
        int v = from[u][i];
        if(last==v)continue;
        dfs(v,u);
        mem[u] += mem[v];
        mem2[u] = max(mem2[v],mem2[u]);
        tmp.push_back(mem2[v]);

    }
    mem2[u] = max(mem2[u],mem[u]);
    //tmp.push_back(mem[u]);
    sort(tmp.begin(),tmp.end());
    if(tmp.size()<2)return;
    long long sum = tmp[tmp.size()-1]+tmp[tmp.size()-2];
    ans = max(sum,ans);
    //printf("mem2[%d] = %I64d mem[%d] = %d\n",u,mem2[u],u,mem[u]);
}
main()
{
    int i,n,x,y;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&a[i]),mem2[i] =  -inf;
    ans = -inf;
    for(i=0;i<n-1;i++)
    {
        scanf("%d%d",&x,&y);
        from[x].push_back(y);
        from[y].push_back(x);
    }
    dfs(1,0);
    if(ans!=-inf)printf("%I64d",ans);
    else printf("IMPOSSIBLE");
}
