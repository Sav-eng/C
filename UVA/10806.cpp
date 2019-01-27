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
vector<node>from[101];
int mem[101];
int cant[101][101];
int trac[101];
main()
{
    node t;
    int n,m,i,j,a,b,val;
    while(scanf("%d",&n)&&n)
    {
        memset(trac,0,sizeof(trac));
        memset(cant,0,sizeof(cant));
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&val);
            from[a].push_back({b,val});
            from[b].push_back({a,val});
        }
        for(i=1;i<=n;i++)mem[i]=inf;
        heap.push({1,0});
        while(!heap.empty())
        {
            t = heap.top(); heap.pop();
            for(i=0;i<from[t.x].size();i++)
            {
                if(mem[from[t.x][i].x] > t.val+from[t.x][i].val)
                {
                    mem[from[t.x][i].x] = t.val+from[t.x][i].val;
                    trac[from[t.x][i].x] = t.x;
                    heap.push({from[t.x][i].x,mem[from[t.x][i].x]});
                }
            }
        }
        int last;
        last = n;
        if(mem[n]==inf)printf("Back to jail\n");
        else
        {
            int ans = mem[n];
            //printf("ans1 = %d\n",ans);
            for(i=1;i<=n;i++)mem[i]=inf;
            while(last!=1)
            {
                //printf("%d--%d\n",trac[last],last);
                cant[trac[last]][last] = 1;
                for(i=0;i<from[last].size();i++)
                {
                    if(from[last][i].x==trac[last])from[last][i].val*=-1;
                }
                last = trac[last];
            }
            heap.push({1,0});
            while(!heap.empty())
            {
                t = heap.top(); heap.pop();
                for(i=0;i<from[t.x].size();i++)
                {
                    if(!cant[t.x][from[t.x][i].x]&&mem[from[t.x][i].x] > t.val+from[t.x][i].val)
                    {
                        mem[from[t.x][i].x] = t.val+from[t.x][i].val;
                        heap.push({from[t.x][i].x,mem[from[t.x][i].x]});
                    }
                }
            }
            if(mem[n]==inf)printf("Back to jail\n");
            else printf("%d\n",ans+mem[n]);
        }
        for(i=1;i<=n;i++)from[i].clear();
    }
}
