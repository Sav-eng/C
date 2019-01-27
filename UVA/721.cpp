#include<bits/stdc++.h>
#define MAXN 1000002
#define inf 1e9
using namespace std;
struct node
{
    int x,val;
    bool operator <(node a)const
    {
        return a.val<val;
    }
};
priority_queue<node>heap;
vector<node>from[MAXN],from2[MAXN];
int mem[MAXN];
main()
{
    int T,n,m,i,ans,a,b,val;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<=n;i++)from[i].clear(),from2[i].clear();
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&val);
            from[a].push_back({b,val});
            from2[b].push_back({a,val});
        }
        for(i=2;i<=n;i++)mem[i]=inf;
        mem[1]=0;
        heap.push({1,0});
        node t;
        while(!heap.empty())
        {
            t = heap.top(); heap.pop();
            for(i=0;i<from[t.x].size();i++)
            {
                if(mem[from[t.x][i].x]>t.val+from[t.x][i].val)
                {
                    mem[from[t.x][i].x] = t.val+from[t.x][i].val;
                    heap.push({from[t.x][i].x,mem[from[t.x][i].x]});
                }
            }
        }
        ans = 0;
        for(i=2;i<=n;i++)ans+=mem[i];
        for(i=2;i<=n;i++)mem[i] = inf;
        mem[1] = 0;
        heap.push({1,0});
        while(!heap.empty())
        {
            t = heap.top(); heap.pop();
            for(i=0;i<from2[t.x].size();i++)
            {
                if(mem[from2[t.x][i].x] > t.val + from2[t.x][i].val)
                {
                    mem[from2[t.x][i].x] = t.val + from2[t.x][i].val;
                    heap.push({from2[t.x][i].x,mem[from2[t.x][i].x]});
                }
            }
        }
        for(i=2;i<=n;i++)ans+=mem[i];
        printf("%d\n",ans);
    }
}
