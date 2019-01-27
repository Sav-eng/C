#include<bits/stdc++.h>
#define inf 2*1e9
using namespace std;
struct node
{
    int x,val,cnt;
    bool operator <(node a)const
    {
        return a.val<val;
    }
};
priority_queue<node>heap;
vector<node>from[5001];
int mem[5001][5001];
int trac[5001][5001];
int n;
void Trac(int x)
{
    int p[5001];
    int t=n;
    int N = x;
    int i;
    for(i=N;i>0;i--)
    {
        p[i] = t;
        t = trac[t][i];
        //printf("trac[%d][%d] = %d\n",t,i,trac[t][i]);
    }
    //p[1]=1;
    for(i=1;i<=N;i++)printf("%d ",p[i]);
}
main()
{
    int m,i,k,j,a,b,val;
    node t;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&a,&b,&val);
        from[a].push_back({b,val,0});
        //from[b].push_back({a,val,0});
    }
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)mem[i][j] = inf;
    heap.push({1,0,1});
    int u,v,oldcost,cost,Cnt;
    while(!heap.empty())
    {
        t = heap.top(); heap.pop();
        u = t.x;
        oldcost = t.val;
        Cnt = t.cnt;
        for(i=0;i<from[u].size();i++)
        {
            v = from[u][i].x;
            cost = from[u][i].val;
            if(mem[v][Cnt+1]>oldcost+cost && oldcost+cost <=k)
            {
                mem[v][Cnt+1] = oldcost + cost;
                trac[v][Cnt+1] = u;
                heap.push({v,mem[v][Cnt+1],Cnt+1});
            }
        }
    }
    for(i=n;i>=1;i--)
    {
        if(mem[n][i]!= inf)
        {
            printf("%d\n",i);
            Trac(i);
            return 0;
        }
    }
}
