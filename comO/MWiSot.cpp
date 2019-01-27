#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+1;
int x[MAXN];
vector<int>from[MAXN];
int mem[MAXN][2];
void dfs(int u,int last)
{
    int i;
    mem[u][1] = x[u];
    for(i=0;i<from[u].size();i++)
    {
        int v = from[u][i];
        if(v!=last)
        {
            dfs(v,u);
            mem[u][0] += max(mem[v][0],mem[v][1]);
            mem[u][1] += mem[v][0];
        }
    }
}
main()
{
    int n,i,a,b;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&x[i]);
    for(i=0;i<n-1;i++)
    {
        scanf("%d%d",&a,&b);
        from[a].push_back(b);
        from[b].push_back(a);
    }
    dfs(0,0);
    printf("%d",max(mem[0][0],mem[0][1]));
}
