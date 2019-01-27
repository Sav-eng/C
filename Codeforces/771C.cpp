#include<bits/stdc++.h>
using namespace std;
long long cn[200001][5];
long long cw[200001][5];
int k;
vector<int>from[200001];
int vis[200001];
long long dfs(int u)
{
    vis[u] = 1;
    long long ans=0;
    int i,p,q,v;
    cn[u][0] = cw[u][0] = 1;
    for(i=0;i<from[u].size();i++)
    {
        v = from[u][i];
        if(vis[v])continue;
        ans+= dfs(v);
        for(p=0;p<k;p++)
        {
            for(q=0;q<k;q++)
            {
                ans += (cn[u][p]*cw[v][q] + cn[v][q]*cw[u][p]);
                if(p+q<k)ans -= (cn[u][p]*cn[v][q]);
            }
        }
        for(q=0;q<k;q++)
        {
            p = (q+1)%k;
            cn[u][p] += cn[v][q];
            cw[u][p] += cw[v][q];
        }
        cw[u][0] += cn[v][k-1];
    }
    return ans;
}
main()
{
    int n,i,a,b;
    scanf("%d%d",&n,&k);
    for(i=0;i<n-1;i++)
    {
        scanf("%d%d",&a,&b);
        from[a].push_back(b);
        from[b].push_back(a);
    }
    printf("%I64d",dfs(1));
}
