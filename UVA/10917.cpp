#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
struct node
{
    int x,val;
    bool operator <(node a)const
    {
        return val<a.val;
    }
};
vector<node>from[1001];
vector<int>from2[1001];
priority_queue<node>heap;
queue<node>q;
int mem[1001];
int mem2[1001];
int vis[1001];
int ans;
int dfs(int x)
{
    if(x==2)return 1;
    else if(!mem2[x])
    {
        int i;
        vis[x] = 1;
        for(i=0;i<from[x].size();i++)if(!vis[from[x][i].x] && mem[from[x][i].x] < mem[x])mem2[x]+=dfs(from[x][i].x);
        vis[x] = 0;
    }
    //printf("mem2[%d] = %d\n",x,mem2[x]);
    return mem2[x];
}
main()
{
    int i,n,m,a,b,val;
    while(scanf("%d",&n)&&n)
    {
        for(i=0;i<1001;i++)from[i].clear();
        memset(mem2,0,sizeof(mem));
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&val);
            from[b].push_back({a,val});
            from[a].push_back({b,val});
        }
        heap.push({2,0});
        for(i=1;i<=n;i++)mem[i] = inf;
        mem[2]=0;
        node t;
        while(!heap.empty())
        {
            t = heap.top(); heap.pop();
            for(i=0;i<from[t.x].size();i++)
            {
                if(mem[from[t.x][i].x] > t.val+from[t.x][i].val)
                {
                    mem[from[t.x][i].x] = t.val+from[t.x][i].val;
                    heap.push({from[t.x][i].x,mem[from[t.x][i].x]});
                }
            }
        }
        printf("%d\n",dfs(1));
    }
}
