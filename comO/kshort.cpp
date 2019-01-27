#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 1e4+2;
const int inf = 2e9;
struct node
{
    int x;
    ll val;
    int cnt;
    bool operator <(node a)const
    {
        return a.val<val;
    }
};
priority_queue<node>heap;
ll mem[MAXN][52];
vector<node>from[MAXN],from2[MAXN];
main()
{
    int n,m,s,l,i,j,a,b,val;
    scanf("%d%d%d%d",&n,&m,&s,&l);
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&a,&b,&val);
        from[a].push_back({b,val});
        //from[b].push_back({a,val});
    }
    for(i=0;i<s;i++)
    {
        scanf("%d%d%d",&a,&b,&val);
        from2[a].push_back({b,val});
        //from2[b].push_back({a,val});
    }
    for(i=1;i<=MAXN-2;i++)for(j=0;j<=s;j++)mem[i][j] = inf;
    heap.push({1,0,0});
    while(!heap.empty())
    {
        node t = heap.top(); heap.pop();
        int u =t.x;
        int cnt = t.cnt;
        if(u==n)
        {
            printf("%lld",mem[u][cnt]);
            return 0;
        }
        for(i=0;i<from[u].size();i++)
        {
            int v = from[u][i].x;
            int val = from[u][i].val;
            if(mem[v][cnt]>t.val+val)
            {
                mem[v][cnt] = t.val+val;
                heap.push({v,mem[v][cnt],cnt});
            }
        }
        if(cnt<l)
        {
            for(i=0;i<from2[u].size();i++)
            {
                int v = from2[u][i].x;
                int val = from2[u][i].val;
                if(mem[v][cnt+1]>t.val+val)
                {
                    mem[v][cnt+1] = t.val+val;
                    heap.push({v,mem[v][cnt+1],cnt+1});
                }
            }
        }
        //printf("mem[%d][%d] = %d\n",u,cnt,t.val);
    }
}
/*

4 4 2 1
1 2 10
1 3 15
2 4 10
3 4 15
1 4 100
1 3 4


*/
