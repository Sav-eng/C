#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define inf (long long)1e16
struct node
{
    int x;
    long long val;
    node(int _x = 0,long long _val = 0)
    {
        x = _x; val = _val;
    }
    bool operator < (node a) const
    {
        return a.val<val;
    }
};
int n,m,L,Q;
int num[80005];
bool ok[15];
long long mem[80005];
long long len[15][15];
long long dp[80005][15];
vector<node> from[80005];
priority_queue<node> heap;
void sp(int x)
{
    int i,now;
    node t;
    now = num[x];
    for(i=1;i<=n;i++) mem[i] = inf;
    mem[x] = 0;
    heap.push(node(x,0));
    while(!heap.empty())
    {
        t = heap.top(); heap.pop();
        for(i=0;i<from[t.x].size();i++)
        {
            if(mem[from[t.x][i].x] > mem[t.x] + from[t.x][i].val)
            {
                mem[from[t.x][i].x] = mem[t.x] + from[t.x][i].val;
                heap.push(node(from[t.x][i].x,mem[from[t.x][i].x]));
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        if(num[i]!=-1) len[now][num[i]] = mem[i];
    }
}
long long f(int x,int now)
{
    int i;
    if(x==1) return 0;
    if(dp[x][now]==-1)
    {
        dp[x][now] = inf;
        for(i=0;i<m;i++)
        {
            if(x==i) continue;
            if(now<Q && ok[x])
            {
                dp[x][now] = min(dp[x][now],f(i,now+1)+((len[x][i])/(1<<(now+1))));
                //printf("\tdp %d %d => %d %d + (%lld)/(%lld)\n",x,now,i,now+1,len[x][i],(long long)1<<(now+1));
            }
            dp[x][now] = min(dp[x][now],f(i,now)+((len[x][i])/(1<<(now))));
            //printf("\tdp %d %d => %d %d + (%lld)/(%lld)\n",x,now,i,now,len[x][i],(long long)1<<(now));
        }
        //printf("dp %d %d = %lld\n",x,now,dp[x][now]);
    }
    return dp[x][now];
}
main()
{
    int i,j,x,y,e;
    long long val;
    scanf("%d%d%d%d",&n,&e,&L,&Q);
    for(i=0;i<e;i++)
    {
        scanf("%d%d%lld",&x,&y,&val);
        from[x].push_back(node(y,val));
    }
    memset(num,-1,sizeof(num));
    num[1] = 0;
    num[n] = 1;
    m = 2;
    for(i=0;i<L;i++)
    {
        scanf("%d",&x);
        if(num[x]==-1) num[x] = m++;
        ok[num[x]] = true;
    }
    for(i=1;i<=n;i++)
    {
        if(num[i]!=-1) sp(i);
    }
    memset(dp,-1,sizeof(dp));
    printf("%lld",f(0,0));
}
/*
3 3 2 8
1 2 256
2 1 256
2 3 256000
1 2
*/
