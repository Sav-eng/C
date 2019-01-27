#include<bits/stdc++.h>
#define MAXN 10001
#define MAXM 100001
#define inf 1e9
using namespace std;
struct node
{
    int x,val,h;
};
struct node2
{
    int x,y,val,ind;
    bool operator <(node2 a)const
    {
        return a.val<val;
    }
};
struct node3
{
    int val,valw;
};
struct node4
{
    int x,val,valw;
    bool operator <(node4 a)const
    {
        if(valw==a.valw)return a.val<val;
        return a.valw<a.valw;
    }
};
struct node5
{
    int x,ind;
};
int head[MAXN];
int findhead(int x)
{
    if(x==head[x])return x;
    return head[x] = findhead(head[x]);
}
int vis[MAXN];
vector<node5>from2[MAXM];
int track[MAXN];
void dfs(int x)
{
    int i;
    vis[x] = 1;
    for(i=0;i<from2[x].size();i++)
    {
        if(!vis[from2[x][i].x])
        {
            //printf("%d--->%d\n",x,from2[x][i].x);
            track[x] = from2[x][i].ind;
            dfs(from2[x][i].x);
        }
    }
}
priority_queue<node2>heap;
int n;
void Mst()
{
    node2 t;
    int i;
    for(i=0;i<n;i++)head[i] = i;
    while(!heap.empty())
    {
        t = heap.top(); heap.pop();
        if(findhead(t.x)!=findhead(t.y))
        {
            //printf("%d--%d\n",t.x,t.y);
            head[findhead(t.x)]=findhead(head[t.y]);
            from2[t.x].push_back({t.y,t.ind});
            from2[t.y].push_back({t.x,t.ind});
            //for(i=0;i<n;i++)printf("%d ",head[i]);
        }
        //printf("\n");
    }

}
int s,e;
int a[MAXM];
int b[MAXM];
int val[MAXM];
int h[MAXM];
int Track()
{
    int t=s;
    int t2 =track[t];
    int ans = 0;
    while(t!=e)
    {
        t2  = track[t];
        printf("%d ",t2);
        ans = max(ans,h[t2]);
        t = b[t2];
    }
    printf("\n");
    return ans;
}
node3 mem[MAXN];
vector<node>from[MAXN];
int Lower;
int Dijkstra()
{
    priority_queue<node4>heap2;
    node4 t;
    int i;
    heap2.push({s,0,0});
    for(i=0;i<n;i++)mem[i].val = mem[i].valw = inf;
    while(!heap2.empty())
    {
        t = heap2.top();heap2.pop();
        if(t.x==e)return mem[from[t.x][i].x].valw;
        for(i=0;i<from[t.x].size();i++)
        {
            if(from[t.x][i].h<=Lower)
            {
                if(mem[from[t.x][i].x].valw > (from[t.x][i].h==0)?t.valw:t.valw+from[t.x][i].val)
                {
                    printf("A %d-->%d\n",t.x,from[t.x][i].x);
                    mem[from[t.x][i].x].valw = t.valw+((from[t.x][i].h==0)?0:0+from[t.x][i].val);
                    mem[from[t.x][i].x].val = t.val+from[t.x][i].val;
                    heap2.push({from[t.x][i].x,mem[from[t.x][i].x].val,mem[from[t.x][i].x].valw});
                }
                else if(mem[from[t.x][i].x].valw == (from[t.x][i].h==0)?t.valw:t.valw+from[t.x][i].val)
                {
                    if(mem[from[t.x][i].x].val > t.val+from[t.x][i].val)
                    {
                        printf("B %d-->%d %d > %d\n",t.x,from[t.x][i].x,mem[from[t.x][i].x],t.val+from[t.x][i].val);
                        mem[from[t.x][i].x].valw = t.valw+(from[t.x][i].h==0)?0:0+from[t.x][i].val;
                        mem[from[t.x][i].x].val = t.val+from[t.x][i].val;
                        heap2.push({from[t.x][i].x,mem[from[t.x][i].x].val,mem[from[t.x][i].x].valw});
                    }
                }
            }
        }
        printf("mem[%d] = %d\n",t.x,mem[t.x].valw);
    }
    return 0;
}
main()
{
    int m,i;
    scanf("%d%d%d%d",&n,&m,&s,&e);
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d%d",&a[i],&b[i],&val[i],&h[i]);
        from[a[i]].push_back({b[i],val[i],h[i]});
        from[b[i]].push_back({a[i],val[i],h[i]});
        heap.push({a[i],b[i],h[i],i});
    }
    Mst();
    dfs(s);
    Lower = Track();
    //printf("%d",Lower);
    printf("%d",Dijkstra());
}
