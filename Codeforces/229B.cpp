#include<bits/stdc++.h>
#define MAXN 200001
using namespace std;
struct node
{
    long long x,val;
    bool operator <(node a)const
    {
        return a.val<val;
    }
};
vector<node>from[MAXN];
set<long long>S[MAXN];
long long mem[MAXN];
priority_queue<node>heap;
main()
{
    int n,m,i,j,a,b,val;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&a,&b,&val);
        from[a].push_back({b,val});
        from[b].push_back({a,val});
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        for(j=0;j<a;j++)
        {
            scanf("%d",&b);
            S[i+1].insert(b);
        }
    }
    heap.push({1,0});
    node t;
    for(i=1;i<=n;i++)mem[i] = 2e9;
    while(!heap.empty())
    {
        t = heap.top(); heap.pop();
        while(S[t.x].find(t.val)!=S[t.x].end())t.val++;
        for(i=0;i<from[t.x].size();i++)
        {
            if(mem[from[t.x][i].x] > from[t.x][i].val + t.val)
            {
                mem[from[t.x][i].x] = from[t.x][i].val+t.val;
                heap.push({from[t.x][i].x,mem[from[t.x][i].x]});
            }
        }
    }
    printf("%I64d",(mem[n]==2e9)?-1:mem[n]);
}
/*

3 3
1 2 3
2 3 3
1 3 100
0
2 3 4
0


*/
