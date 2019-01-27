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
int mem[101];
vector<node>from[101];
main()
{
    //freopen("out.txt","w",stdout);
    int time,n,s,k,m,i,a,b,c,ans=0;
    bool check=0;
    scanf("%d",&time);
    while(time--)
    {
        if(check)printf("\n");
        check=1;
        scanf("%d%d%d%d",&n,&s,&k,&m);
        for(i=1;i<=n;i++)from[i].clear();
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            from[b].push_back({a,c});
        }
        heap.push({s,0});
        node t;
        for(i=1;i<=n;i++)mem[i]=inf;
        mem[s] = 0;
        while(!heap.empty())
        {
            t = heap.top(); heap.pop();
            for(i=0;i<from[t.x].size();i++)
            {
                if(mem[from[t.x][i].x]>t.val+from[t.x][i].val)
                {
                    //printf("%d---->%d\n",t.x,from[t.x][i].x);
                    mem[from[t.x][i].x] = t.val+from[t.x][i].val;
                    heap.push({from[t.x][i].x,mem[from[t.x][i].x]});
                }
            }
            //printf("mem[%d] = %d\n",t.x,mem[t.x]);
        }
        ans=0;
        for(i=1;i<=n;i++)if(mem[i]<=k)ans++;
        printf("%d\n",ans);
    }
}

