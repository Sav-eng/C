#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e4+2;
int h[MAXN];
int par[MAXN][30];
vector<int>from[MAXN];
void dfs(int x,int last)
{
    int i;
    h[x] = h[last]+1;
    par[x][0] = last;
    for(i=1;i<=21;i++)par[x][i] = par[par[x][i-1]][i-1];
    for(i=0;i<from[x].size();i++)if(from[x][i]!=last)dfs(from[x][i],x);
}
int lca(int l,int r)
{
    int i,ans=0;
    if(h[l]<h[r])swap(l,r);
    //printf("l = %d[%d] r = %d[%d]\n",l,h[l],r,h[r]);
    for(i=21;i>=0;i--)if(h[par[l][i]] >= h[r])
    {
        //printf("%d ---> %d\n",l,par[l][i]);
        l = par[l][i];
        ans+= 1<<i;
    }
    if(l==r)return ans;

    for(i=21;i>=0;i--)if(par[l][i] != par[r][i])// || (par[l][i]==par[r][i] && par[l][i] && par[r][i]))
    {
        //printf("L(%d--->%d) R(%d--->%d)\n",l,par[l][i],r,par[r][i]);
        l = par[l][i];
        r = par[r][i];
        ans += 2*(1<<i);
        //if(l==r)break;
    }
    return ans+2;
}
main()
{
    int i,n,a,b,ans=0,m;
    scanf("%d",&n);
    for(i=0;i<n-1;i++)
    {
        scanf("%d%d",&a,&b);
        from[a].push_back(b);
        from[b].push_back(a);
    }
    dfs(1,0);
    scanf("%d",&m);
    int now =1;
    for(i=0;i<m;i++)
    {
        scanf("%d",&a);
        ans += lca(now,a);
        now = a;
    }
    printf("%d\n",ans);

}
/*

15
1 2
1 3
2 4
2 5
3 6
3 7
4 8
4 9
5 10
5 11
6 12
6 13
7 14
7 15
7
1 8 2 7 5 10 3


*/
