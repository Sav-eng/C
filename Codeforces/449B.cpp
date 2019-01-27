#include<bits/stdc++.h>
#define inf 1e16
#define MAXN 1000001
using namespace std;
struct node
{
    int x;
    long long val;
    long long ind;
    bool operator <(node a)const
    {
        if(a.val==val)return a.ind<ind;
        return a.val<val;
    }
};
long long mem[MAXN];
int tab[MAXN];
long long trac[MAXN];
int a[MAXN];
int b[MAXN];
int val[MAXN];
int check[MAXN];
vector<node>from[MAXN];
priority_queue<node>heap;
main()
{
    int n,m,k,i;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=m;i++)
    {
        trac[i] = inf;
        scanf("%d%d%d",&a[i],&b[i],&val[i]);
        from[a[i]].push_back({b[i],val[i],i});
        from[b[i]].push_back({a[i],val[i],i});
    }
    for(i=m+1;i<=k+m;i++)
    {
        trac[i] = inf;
        a[i] = 1;
        scanf("%d%d",&b[i],&val[i]);
        from[1].push_back({b[i],val[i],i});
    }
    node t;
    for(i=1;i<=n;i++)mem[i] = inf;
    heap.push({1,0,0});
    while(!heap.empty())
    {
        t = heap.top(); heap.pop();
        if(mem[t.x]<t.val)continue;
        //if((long long)t.val<=(long long)mem[t.x])trac[t.x] = min(trac[t.x],t.ind);
        for(i=0;i<from[t.x].size();i++)
        {
            if((long long)mem[from[t.x][i].x] > (long long)from[t.x][i].val + t.val)
            {
                mem[from[t.x][i].x] = (long long)from[t.x][i].val+t.val;
                trac[from[t.x][i].x] = from[t.x][i].ind;
                heap.push({from[t.x][i].x,mem[from[t.x][i].x],from[t.x][i].ind});
            }
            else if((long long)mem[from[t.x][i].x] == (long long)from[t.x][i].val + t.val)
            {
                trac[from[t.x][i].x] = min(trac[from[t.x][i].x],from[t.x][i].ind);
            }
        }
    }
    int ans=0;
    //ans = k;
    for(i=2;i<=n;i++)
    {
        //printf("%I64d %I64d\n",trac[i],mem[i]);
        if(trac[i]>m && trac[i]!=inf)
        {
            if(!check[trac[i]])ans++;
            check[trac[i]] = 1;
        }
    }
    //printf("\n");
    printf("%d",k-ans);
}
/*

5 4 2
1 2 100
2 3 1
3 4 1
4 5 1
2 1
4 3



*/
