#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
struct node
{
    int x,y;
    double temp,val;
    bool operator <(node a)const
    {
        if(a.temp==temp)return a.val<val;
        return a.temp<temp;
    }
};
struct node2
{
    int x;
    double val;
    bool operator <(node2 a)const
    {
        return a.val<val;
    }
};
int head[10001];
int findhead(int x)
{
    if(x==head[x])return x;
    return head[x] = findhead(head[x]);
}
double mem[10001];
vector<node2>from[10001];
int vis[10001];
int trac[10001];
void dfs(int x)
{
    int i;
    vis[x] = 1;
    for(i=0;i<from[x].size();i++)if(!vis[from[x][i].x])trac[from[x][i].x] = x,dfs(from[x][i].x);
    vis[x] = 0;
}
priority_queue<node2>heap2;
priority_queue<node>heap;
double mp[101][101];
int a[10001],b[10001];
double c[10001],d[10001];
int path[10001];
main()
{
    //freopen("out.txt","w",stdout);
    int n,m,i,j,k,s,e;
    double ans1,ans2;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        scanf("%d%d",&s,&e);
        for(i=0;i<m;i++)
        {
            scanf("%d%d%lf%lf",&a[i],&b[i],&c[i],&d[i]);
            //printf("%d %d %lf %lf\n",a[i],b[i],c[i],d[i]);
            heap.push({a[i],b[i],c[i],d[i]});
        }
        node t;
        for(i=1;i<=n;i++)head[i] = i,from[i].clear(),trac[i]=0;
        int check=0;
        while(!heap.empty())
        {
            t = heap.top(); heap.pop();
            //printf("t.x = %d t.y = %d",t.x,t.y);
            if(findhead(head[t.x])!=findhead(head[t.y]))
            {
                head[findhead(t.x)]=findhead(head[t.y]);
                from[t.x].push_back({t.y,t.val});
                from[t.y].push_back({t.x,t.val});
                mp[t.x][t.y] = t.temp;
                mp[t.y][t.x] = t.temp;
            }
        }
        dfs(s);
        int t2=e;
        ans2=0;
        double maxtemp =0;
        while(t2!=s)
        {
            //printf("%d-->%d\n",t2,trac[t2]);
            //path[check++] = trac[t2];
            maxtemp = max(maxtemp,mp[trac[t2]][t2]);
            t2 = trac[t2];
        }
        //printf("maxtemp = %lf",maxtemp);
        for(i=1;i<=n;i++)from[i].clear();
        for(i=0;i<m;i++)
        {
            if(c[i]<=maxtemp)
            {
                from[a[i]].push_back({b[i],d[i]});
                from[b[i]].push_back({a[i],d[i]});
            }
        }
        heap2.push({s,0});
        node2 t3;
        for(i=1;i<=n;i++)mem[i] = inf,trac[i]=0;
        mem[s] = 0;
        while(!heap2.empty())
        {
            t3 = heap2.top(); heap2.pop();
            //printf("t3.val = %lf\n",t3.val);
            for(i=0;i<from[t3.x].size();i++)
            {
                if(mem[from[t3.x][i].x] > t3.val+from[t3.x][i].val)
                {
                    mem[from[t3.x][i].x] = t3.val+from[t3.x][i].val;
                    trac[from[t3.x][i].x] = t3.x;
                    heap2.push({from[t3.x][i].x,mem[from[t3.x][i].x]});
                }
            }
            //printf("mem[%d] = %.1lf\n",t3.x,mem[t3.x]);
        }
        t2 = e;
        check = 0;
        while(t2!=s)
        {
            path[check++]=trac[t2];
            t2 = trac[t2];
        }
        for(i=check-1;i>=0;i--)printf("%d ",path[i]);
        printf("%d",e);
        printf("\n");
        printf("%.1lf %.1lf\n",mem[e],maxtemp);
    }
}
