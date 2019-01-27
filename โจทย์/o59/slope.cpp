#include<stdio.h>
#define mod 999999999
int n,k;
int p[80005];
long long dp[45][80005]; //dp[k][pos]
long long tree[45][80005]; //>= fenwick
void add(int y,int x,long long val)
{
    while(x>0)
    {
        tree[y][x] = (tree[y][x] + val + mod)%mod;
        x -= x&-x;
    }
}
long long sum(int y,int x)
{
    long long ans = 0;
    while(x<=n)
    {
        ans = (ans + tree[y][x] + mod)%mod;
        x += x&-x;
    }
    return ans;
}
main()
{
    int i,x;
    long long ans;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++) scanf("%d",&p[i]);
    for(i=1;i<=n;i++) dp[1][i] = 1;
    for(i=2;i<=k;i++)
    {
        for(x=1;x<=n;x++)
        {
            dp[i][x] = sum(i-1,p[x]);
            add(i-1,p[x],dp[i-1][x]);
        }
    }
    ans = 0;
    for(i=1;i<=n;i++) ans = (ans + dp[k][i] + mod)%mod;
    printf("%lld\n",ans);
}
