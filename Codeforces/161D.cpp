#include<bits/stdc++.h>
using namespace std;
long long mem[50001][501];
int CN[50001][501];
int vis[50001];
vector<int>from[50001];
int k;
long long dfs(int u)
{
    vis[u] = 1;
    long long ans=0;
    CN[u][0] = 1;
    int i,v,p,q;
    for(i=0;i<from[u].size();i++)
    {
        v = from[u][i];
        if(vis[v])continue;
        //printf("%d GO %d\n",u,v);
        ans += dfs(v);
        for(p=0;p<k;p++)
        {
            ans += CN[u][p]*CN[v][k-p-1];
            //printf("CN[%d][%d]= %d \t CN[%d][%d] = %d GET %d\n",u,p,CN[u][p],v,k-p-1,CN[v][k-p-1],CN[u][p]*CN[v][k-p-1]);
        }
        for(p=0;p<k-1;p++)
        {
            int q= p+1;
            CN[u][q] += CN[v][p];
        }
    }
    //printf("%d return %d\n",u,ans);
    return ans;
}
main()
{
    int n,i,a,b,j;
    scanf("%d%d",&n,&k);
    for(i=0;i<n-1;i++)
    {
        scanf("%d%d",&a,&b);
        from[a].push_back(b);
        from[b].push_back(a);
    }
    printf("%I64d\n",dfs(1));
    /*for(i=1;i<=n;i++)
    {
        for(j=0;j<k;j++)
        {
            printf("%d ",CN[i][j]);
        }
        printf("\n");
    }*/
}
