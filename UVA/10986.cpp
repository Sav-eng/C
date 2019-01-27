#include<bits/stdc++.h>
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
vector<node>from[20001];
int mem[20001];
main()
{
    //freopen("out.txt","w",stdout);
    int T,n,m,s,e,i,a,b,val,time=0;
    node t;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d",&n,&m,&s,&e);
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&val);
            from[a].push_back({b,val});
            from[b].push_back({a,val});
        }
        for(i=0;i<n;i++)mem[i] = inf;
        heap.push({s,0});
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
        printf("Case #%d: ",++time);
        if(mem[e]!=inf)printf("%d\n",mem[e]);
        else printf("unreachable\n");
        for(i=0;i<n;i++)from[i].clear();
    }
}
