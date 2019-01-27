#include<bits/stdc++.h>
#define inf 1e9
#define MAXN 502
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
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m,i,a,b,val,last,check=0,j,_max;
    node t;
    while(scanf("%d",&n)&& n)
    {
        scanf("%d",&m);

        //if(check)printf("\n");
        for(i=1;i<=MAXN;i++)from[i].clear();
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&val);
            from[a].push_back({b,val});
            from[b].push_back({a,val});
        }
        heap.push({1,0,0});
        for(i=1;i<=MAXN;i++)mem[i] = inf;
        mem[1]=0;
        _max = 0;
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
            //printf("mem[%d] = %d\n",t.x,mem[t.x]);
            if(mem[_max]<mem[t.x])_max = t.x;
        }
        double ans=0;
        int longest=0;
        int ans2=0,last2=0,longest2=0;
        for(i=1;i<=n;i++)
        {
            for(j=0;j<from[i].size();j++)
            {
                if(ans<(double)(from[i][j].val+mem[from[i][j].x]+mem[i])/2 && mem[i]>=mem[from[i][j].x])
                {
                    ans = (double)(from[i][j].val+mem[from[i][j].x]+mem[i])/2;
                    last = i;
                    longest = from[i][j].x;
                }
                /*if(ans<(double)from[i][j].val+mem[from[i][j].x] && mem[i]>=mem[from[i][j].x])
                {
                    ans2 = (double)from[i][j].val+mem[from[i][j].x];
                    last2 = i;
                    longest2 = from[i][j].x;
                }*/
            }

        }
        //printf("mem[%d] = %d mem[%d] = %d\n",longest,mem[longest],last,mem[last]);
        printf("System #%d\n",++check);
        if(n==1 && m==0)
        {
            printf("The last domino falls after 0.0 seconds, at key domino 1.\n\n");
            continue;
        }
        if(ans>mem[_max])printf("The last domino falls after %.1lf seconds, between key dominoes %d and %d.\n\n",ans,min(last,longest),max(last,longest));
        else printf("The last domino falls after %d.0 seconds, at key domino %d.\n\n",mem[_max],_max);
    }
}
