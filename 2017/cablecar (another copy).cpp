#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
struct node
{
    int x,y,val;
    bool operator <(node a)const
    {
        return a.val>val;
    }
};
struct node2
{
    int x,val;
};
int head[2501];
int findhead(int x)
{
    if(x==head[x])return x;
    else return head[x] = findhead(head[x]);
}
priority_queue<node>heap;
queue<node2>q;
vector<node2>from[2501];
int mem[2501];
node t;
node2 t2;
main()
{
    //freopen("1.in","w",stdout);
    int n,m,i,j,k,s,e,a,b,c;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        heap.push({a,b,c});
    }
    scanf("%d%d%d",&s,&e,&k);
    for(i=1;i<=n;i++)head[i]=i;
    while(!heap.empty())
    {
        t = heap.top(); heap.pop();
        if(findhead(head[t.x])!=findhead(head[t.y]))
        {
            //printf("%d\n",t.val);
            head[findhead(t.x)]=findhead(head[t.y]);
            from[t.x].push_back({t.y,t.val-1});
            from[t.y].push_back({t.x,t.val-1});
        }
    }
    q.push({s,inf});
    mem[s] = inf;
    int ans;
    //printf("k = %d\n",k);
    while(!q.empty())
    {
        t2 = q.front(); q.pop();
        if(t2.x==e)
        {
            ans = k/t2.val;
            if(k%t2.val==0)printf("%d",ans);
            else printf("%d",ans+1);
        }
        for(i=0;i<from[t2.x].size();i++)
        {
            if(!mem[from[t2.x][i].x])
            {
                //printf("mem[%d] = min(%d,%d)\n",from[t2.x][i].x,t2.val,from[t2.x][i].val);
                mem[from[t2.x][i].x] = min(t2.val,from[t2.x][i].val);
                q.push({from[t2.x][i].x,mem[from[t2.x][i].x]});
            }
        }
        //printf("mem[%d] = %d\n",t2.x,mem[t2.x]);
    }
}

