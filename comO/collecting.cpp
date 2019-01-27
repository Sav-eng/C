#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e4+2;
const int inf = 1e9;
struct node
{
    int x,val,order;
    bool operator <(node a)const
    {
        return a.val<val;
    }
};
int x[MAXN];
int mem[MAXN][35];
vector<node>from[MAXN];
priority_queue<node>heap;
main()
{
    int n,m,k,s,e,i,j,a,b,val;
    scanf("%d%d%d%d%d",&n,&m,&k,&s,&e);
    for(i=1;i<=n;i++)scanf("%d",&x[i]);
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&a,&b,&val);
        from[a].push_back({b,val});
    }
    heap.push({s,0});
    for(i=1;i<=n;i++)for(j=0;j<=k;j++)mem[i][j] = inf;
    while(!heap.empty())
    {
        node t = heap.top(); heap.pop();
        int u = t.x;
        int VAL = t.val;
        int ORDER = t.order;
        if(u==e && ORDER == k)
        {
            printf("%d",mem[u][ORDER]);
            return 0;
        }
        for(i=0;i<from[u].size();i++)
        {
            int v= from[u][i].x;
            int val = from[u][i].val;
            int order = x[from[u][i].x];
            //printf("%d--->%d\n",u,v);
            if(order == ORDER+1)
            {
                //printf("%d--->%d\n",u,v);
                if(mem[v][order] > val+VAL)
                {
                    mem[v][order] = val+VAL;
                    heap.push({v,mem[v][order],order});
                }
            }
            else
            {
                if(mem[v][ORDER] > val+VAL)
                {
                    mem[v][ORDER] = val+VAL;
                    heap.push({v,mem[v][ORDER],ORDER});
                }
            }
        }
        //printf("mem[%d][%d] = %d\n",u,ORDER,VAL);
    }
}
