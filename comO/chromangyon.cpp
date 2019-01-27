#include<bits/stdc++.h>
using namespace std;
const int MAXN = 105;
const int mod = 2009;
struct node
{
    int val[25];
};
node mem[MAXN][MAXN];
int vis[MAXN][MAXN];
int n;
int a[MAXN][MAXN];
int x[MAXN];
node retone(int x)
{
    node t;
    int i;
    for(i=0;i<n;i++)t.val[i]=0;
    t.val[x] = 1;
    return t;
}
node combine(node x,node y)
{
    int i,j;
    node ans;
    for(i=0;i<n;i++)ans.val[i] = 0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            ans.val[a[i][j]] += x.val[i]*y.val[j];
            ans.val[a[i][j]] %= mod;
        }
    }
    return ans;
}
node dp(int l,int r)
{
    if(l==r)return retone(x[l]);
    else if(!vis[l][r])
    {
        //printf("%d %d\n",l,r);
        vis[l][r] = 1;
        int i,j;
        for(i=l;i<r;i++)
        {
            node t = combine(dp(l,i),dp(i+1,r));
            int j;
            for(j=0;j<n;j++)mem[l][r].val[j] = (mem[l][r].val[j]+t.val[j])%mod;
        }
        /*printf("L: %d R: %d\n",l,r);
        for(i=0;i<n;i++)printf("%d ",mem[l][r].val[i]);
        printf("\n");*/
    }
    return mem[l][r];
}
main()
{
    int i,j,m;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    scanf("%d",&m);
    for(i=0;i<m;i++)scanf("%d",&x[i]);
    dp(0,m-1);
    for(i=0;i<n;i++)printf("%d\n",mem[0][m-1].val[i]);
}
