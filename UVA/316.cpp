#include<bits/stdc++.h>
#define inf 1e9
#define MAXN 501
using namespace std;
struct node
{
    int x,val,ord;
    bool operator <(node a)const
    {
        return a.val<val;
    }
};
int vis[MAXN*MAXN];
vector<node>from[MAXN];
priority_queue<node>heap;
int mem[MAXN];
main()
{
    int n,m,i,a,b,val,last,check=0,j,_max;
    node t;
    while(scanf("%d%d",&n,&m)&& (n || m))
    {
        if(check)printf("\n");
        for(i=1;i<=n;i++)from[i].clear();
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&val);
            from[a].push_back({b,val});
            from[b].push_back({a,val});
        }
        heap.push({1,0,0});
        for(i=1;i<=n;i++)mem[i] = inf;
        mem[1]=0;
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
            _max = mem[t.x];
        }
        double ans=0;
        int longest=0;
        for(i=1;i<=n;i++)
        {
            for(j=0;j<from[i].size();j++)
            {
                if(ans<from[i][j].val+mem[from[i][j].x] && mem[i]>=mem[from[i][j].x])
                {
                    ans = from[i][j].val+mem[from[i][j].x];
                    last = i;
                    longest = from[i][j].x;
                }
            }
        }

        //printf("mem[%d] = %d mem[%d] = %d\n",longest,mem[longest],last,mem[last]);
        printf("System #%d\n",++check);
        if((ans+mem[last])/2>_max)printf("The last domino falls after %.1lf seconds, between key domino %d ans %d.\n",(ans+mem[last])/2,min(last,longest),max(last,longest));
        else printf("The last domino falls after %d seconds, at key domino %d.\n",mem[last],last);
    }
}
