#include<bits/stdc++.h>
#define inf 1e16
using namespace std;
struct node
{
    long long x;
    long long val;
    long long k,room;
    bool operator <(node a)const
    {
        return a.val<val;
    }
};
vector<node>from[80001];
priority_queue<node>heap;
long long mem[80001][10];
long long have[80001];
main()
{
    long long n,m,q,l,a,b,c,i,j;
    scanf("%lld%lld%lld%lld",&n,&m,&l,&q);
    for(i=0;i<m;i++)
    {
        scanf("%lld%lld%lld",&a,&b,&c);
        from[a].push_back({b,c,0});
        //from[b].push_back({a,c,0});
    }
    for(i=0;i<l;i++)
    {
        scanf("%d",&a);
        have[a] = 1;
    }
    heap.push({1,0,0,0});
    if(have[1])heap.push({1,0,1,1});
    for(i=0;i<=n;i++)for(j=0;j<=q;j++)mem[i][j] = inf;
    node t;
    while(!heap.empty())
    {
        t = heap.top();heap.pop();
        if(t.x==n)
        {
            printf("%lld",t.val);
            break;
        }
        for(i=0;i<from[t.x].size();i++)
        {
            if(have[from[t.x][i].x] && t.k+1<=q && t.room != from[t.x][i].x)
            {
                if(mem[from[t.x][i].x][t.k+1] > t.val+(from[t.x][i].val/(1<<t.k)))
                {
                    mem[from[t.x][i].x][t.k+1] = t.val+(from[t.x][i].val/(1<<t.k));
                    heap.push({from[t.x][i].x,mem[from[t.x][i].x][t.k+1],t.k+1,from[t.x][i].x});
                }
            }
            if(mem[from[t.x][i].x][t.k]>t.val+(from[t.x][i].val/(1<<t.k)))
            {
                mem[from[t.x][i].x][t.k] = t.val+(from[t.x][i].val)/(1<<t.k);
                heap.push({from[t.x][i].x,mem[from[t.x][i].x][t.k],t.k,t.room});
            }
            //printf("a");
        }
        //printf("mem[%d][%d] = %d\n",t.x,t.k,t.val);
    }
}
/*

9 9 1 1
1 2 2560000000
2 3 2560000000
3 4 2560000000
4 9 2560000000
1 5 2560000000
5 6 2560000000
6 7 2560000000
7 8 2560000000
8 9 2560000000
5







*/
