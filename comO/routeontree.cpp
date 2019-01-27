#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+2;
const int inf = 1e9;
struct node
{
    int x,val,use;
    bool operator <(node a)const
    {
        return a.val < val;
    }
};
vector<node>from[MAXN];
int mem[MAXN][7];
priority_queue<node>heap;
main()
{
    int n,m,k,a,b,val,i,j;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&a,&b,&val);
        from[a].push_back({b,val,0});
    }
    for(i=1;i<=n;i++)for(j=0;j<=k;j++)mem[i][j]=inf;
    heap.push({1,0,0});
    while(!heap.empty())
    {
        node t = heap.top();
        heap.pop();
        int u = t.x;
        int use = t.use;
        if(u==n)
        {
            printf("%d\n",mem[u][use]);
            return 0;
        }
        for(i=0;i<from[u].size();i++)
        {
            int val = from[u][i].val;
            int v = from[u][i].x;
            if(val<-100)
            {
                if(mem[v][use+1] > t.val && use+1 <=k)
                {
                    mem[v][use+1]=t.val;
                    heap.push({v,mem[v][use+1],use+1});
                }
            }
            else if(val <0)
            {
                if(mem[v][use] > t.val)
                {
                    mem[v][use]=t.val;
                    heap.push({v,mem[v][use],use});
                }
            }
            else
            {
                if(mem[v][use] > t.val+val)
                {
                    mem[v][use]=t.val+val;
                    heap.push({v,mem[v][use],use});
                }
            }
        }
    }
}
