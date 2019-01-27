#include<bits/stdc++.h>
using namespace std;
int vis[200002];
int mem[200002];
int Color[200002];
int n;
int _max;
vector<int>from[200002];
void dfs(int u,int last,int lastC,int nowC)
{
    vis[u] = 1;
    Color[u] = nowC;
    _max = max(_max,nowC);
    int i,j,v;
    j=1;
    for(i=0;i<from[u].size();i++)
    {
        v = from[u][i];
        if(vis[v])continue;
        while(j==lastC || j==nowC)j++;
        dfs(v,u,nowC,j++);
    }
}
main()
{
    int i,a,b;
    scanf("%d",&n);
    for(i=0;i<n-1;i++)
    {
        scanf("%d%d",&a,&b);
        from[a].push_back(b);
        from[b].push_back(a);
    }
    Color[1]=1;
    dfs(1,0,0,1);
    printf("%d\n",_max);
    for(i=1;i<=n;i++)printf("%d ",Color[i]);
}
/*
5
1 5
2 5
3 5
4 5


*/
