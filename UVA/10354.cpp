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
vector<node>from[101];
priority_queue<node>heap;
int mem[101];
int vis[101];
main()
{
    //freopen("out.txt","w",stdout);
    int n,m,s1,s2,e1,e2,i;
    int a,b,val;
    while(scanf("%d%d%d%d%d%d",&n,&m,&s1,&e1,&s2,&e2)!=EOF)
    {
        memset(vis,0,sizeof(vis));
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&val);
            from[a].push_back({b,val});
            from[b].push_back({a,val});
        }
        for(i=1;i<=n;i++)mem[i] = inf;
        mem[s1]=0;
        vis[s1]=1;
        heap.push({s1,0});
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
        //for(i=1;i<=n;i++)printf("%d ",mem[i]);
        //printf("\n");
        heap.push({e1,0});
        if(mem[e1]!=inf)vis[e1]=1;
        while(!heap.empty())
        {
            t = heap.top(); heap.pop();
            for(i=0;i<from[t.x].size();i++)
            {
                if(mem[from[t.x][i].x]+from[t.x][i].val==mem[t.x])
                {
                    vis[from[t.x][i].x] = 1;
                    heap.push({from[t.x][i].x,0});
                }
            }
        }
        for(i=1;i<=n;i++)mem[i] = inf;
        //for(i=1;i<=n;i++)printf("vis[%d] = %d\n",i,vis[i]);
        heap.push({s2,0});
        mem[s2]=0;
        while(!heap.empty())
        {
            t = heap.top(); heap.pop();
            for(i=0;i<from[t.x].size();i++)
            {
                if(mem[from[t.x][i].x] > t.val+from[t.x][i].val && !vis[from[t.x][i].x])
                {
                    mem[from[t.x][i].x] = t.val+from[t.x][i].val;
                    heap.push({from[t.x][i].x,mem[from[t.x][i].x]});
                }
            }
        }
        if(mem[e2]==inf || vis[e2] || vis[s2])printf("MISSION IMPOSSIBLE.\n");
        else printf("%d\n",mem[e2]);
        for(i=1;i<=n;i++)from[i].clear();
    }
}
/*

7 8 7 5 1 4
1 2 3
2 4 3
3 4 1
1 3 2
3 5 1000
4 6 1000
6 7 1000
7 5 3001

*/
