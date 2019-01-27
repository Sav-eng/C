#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e3+2;
const int inf = 1e9+1;
struct node
{
    int x,val,fuel;
    bool operator <(node a)const
    {
        return a.val<val;
    }
};
vector<node>from[MAXN];
int mem[MAXN][101];
priority_queue<node>heap;
int F[MAXN];
main()
{
    //freopen("out.txt","w",stdout);
    int n,m,i,a,b,val,T,fuel,s,e,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%d",&F[i]);
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&a,&b,&val);
        from[a].push_back({b,val,0});
        from[b].push_back({a,val,0});
    }
    scanf("%d",&T);
    while(T--)
    {
        while(!heap.empty())heap.pop();
        scanf("%d%d%d",&fuel,&s,&e);
        heap.push({s,0,0});
        for(i=0;i<n;i++)for(j=0;j<=fuel;j++)mem[i][j] = inf;
        mem[s][0] = 0;
        node t;
        while(!heap.empty())
        {
            t = heap.top(); heap.pop();
            if(t.x==e)
            {
                printf("%d\n",mem[t.x][t.fuel]);
                break;
            }
            if(t.fuel+1 <=fuel &&mem[t.x][t.fuel+1] > mem[t.x][t.fuel]+F[t.x])
            {
                mem[t.x][t.fuel+1] = mem[t.x][t.fuel]+F[t.x];
                heap.push({t.x,mem[t.x][t.fuel+1],t.fuel+1});
            }
            for(i=0;i<from[t.x].size();i++)
            {
                if(t.fuel >= from[t.x][i].val && mem[from[t.x][i].x][t.fuel-from[t.x][i].val] > t.val)
                {
                    mem[from[t.x][i].x][t.fuel-from[t.x][i].val] = t.val;
                    heap.push({from[t.x][i].x,mem[from[t.x][i].x][t.fuel-from[t.x][i].val],t.fuel-from[t.x][i].val});
                }
            }
            //printf("mem[%d][%d] = %d\n",t.x,t.fuel,mem[t.x][t.fuel]);
        }
        if(t.x!=e)printf("impossible\n");
    }
}
