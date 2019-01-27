#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e4+2;
const int inf = 1e9;
struct node
{
    int x,val;
    bool operator <(node a)const
    {
        return a.val<val;
    }
};
int mem[MAXN][2];
vector<node>from[MAXN];
priority_queue<node>heap;
main()
{
    int n,m,s,e,a,b,val,i;
    scanf("%d%d%d%d",&n,&m,&s,&e);
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&a,&b,&val);
        from[a].push_back({b,val});
        from[b].push_back({a,val});
    }
    int u,v;
    heap.push({s,0});
    node t;
    for(i=1;i<=n;i++)mem[i][0] = mem[i][1] = inf;
    while(!heap.empty())
    {
        t = heap.top(); heap.pop();
        //if(u==e)continue;
        u = t.x;
        for(i=0;i<from[t.x].size();i++)
        {
            v = from[t.x][i].x;
            val = from[t.x][i].val;
            //printf("%d--->%d(%d)\n",u,v,t.val+val);
            if(mem[v][0] > t.val+val)
            {
                mem[v][1] = min(mem[v][0],mem[v][1]);
                mem[v][0] = t.val+val;
                heap.push({from[t.x][i].x,mem[v][0]});
            }
            else if(mem[v][1] > t.val+val)
            {
                //printf("%d-->%d(%d)\n",u,v,t.val+val);
                mem[v][1] = t.val+val;
                heap.push({from[t.x][i].x,mem[v][1]});
            }
        }
    }
    printf("%d",mem[e][1]);
}
/*
3 3
1 3
1 2 1
1 2 4
2 3 1

*/
