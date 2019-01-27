#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
struct node
{
    int x,val;
    bool check;
    bool operator <(node a)const
    {
        return a.val<val;
    }
};
vector<node>from[502];
priority_queue<node>heap;
int mem[502][2];
main()
{
    //freopen("out.txt","w",stdout);
    int n,m,a,b,val,i,time=0;
    while(scanf("%d%d",&n,&m)!= EOF)
    {
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&val);
            from[a].push_back({b,val});
            from[b].push_back({a,val});
        }
        for(i=0;i<n;i++)mem[i][0] = mem[i][1] = inf;
        mem[0][0]=0;
        heap.push({0,0,0});
        node t;
        while(!heap.empty())
        {
            t = heap.top(); heap.pop();
            for(i=0;i<from[t.x].size();i++)
            {
                if(mem[from[t.x][i].x][!t.check]>t.val+from[t.x][i].val)
                {
                    mem[from[t.x][i].x][!t.check] = t.val+from[t.x][i].val;
                    heap.push({from[t.x][i].x,mem[from[t.x][i].x][!t.check],!t.check});
                }
            }
        }
        printf("Set #%d\n",++time);
        if(mem[n-1][0]==inf)printf("?\n");
        else printf("%d\n",mem[n-1][0]);
        for(i=0;i<n;i++)from[i].clear();
    }
}
