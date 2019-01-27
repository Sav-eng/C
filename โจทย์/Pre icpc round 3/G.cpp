#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
main()
{
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)mem[i][j].x = mem[i][j].y = inf;
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d%d0",&a[i],&b[i],&c[i],&d[i]);
    }
    scanf("%d",&k);
    while(k>0)
    {
        while(!heap.empty())
        {
            t = heap.top(); heap.pop();
            u = t.x; val = t.val;
            for(i=0;i<from[u].size();i++)
            {
                v = from[u][i];
            }
        }
    }
}
