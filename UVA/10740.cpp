#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
struct node
{
    int x,val;
    bool operator < (node a)const
    {
        return a.val<val;
    }
};
priority_queue<node>heap;
vector<node>from[101];
int mem[11][101];
int vis[101];
main()
{
    int n,m,s,e,k,a,b,val,i,j;
    while(scanf("%d%d",&n,&m)&&n)
    {
        scanf("%d%d%d",&s,&e,&k);
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&val);
            from[a].push_back({b,val});
        }
        heap.push({s,0});
        for(i=1;i<=n;i++)for(j=0;j<k;j++)mem[j][i] = inf;
        memset(vis,0,sizeof(vis));
        node t;
        while(!heap.empty())
        {
            t = heap.top(); heap.pop();
            if(vis[t.x]>k)continue;
            mem[vis[t.x]++][t.x] = t.val;
            for(i=0;i<from[t.x].size();i++)
            {
                heap.push({from[t.x][i].x,t.val+from[t.x][i].val});
            }
        }
        if(mem[k-1][e]==inf)printf("-1\n");
        else printf("%d\n",mem[k-1][e]);
        for(i=1;i<=n;i++)from[i].clear();
    }
}
