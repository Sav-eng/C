#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
const int inf = 1e9;
int x[MAXN];
int mem[MAXN][2];
int n,s1,s2;
bool check(int k)
{
    int i,j;
    set<int>S[2];
    memset(mem,0,sizeof(mem));
    S[0].insert(s1);S[1].insert(s2);
    for(i=0;i<n;i++)
    {
        for(j=0;j<=1;j++)
        {
            while(!S[j].empty() && *S[j].begin()< x[i] -k)S[j].erase(S[j].begin());
            while(!S[j].empty() && *S[j].rbegin() > x[i]+k)S[j].erase(prev(S[j].end()));
        }
        for(j=0;j<=1;j++)
        {
            if(!S[j].empty())S[j^1].insert(x[i]),mem[i][j] = 1;
        }
    }
    return mem[n-1][0] | mem[n-1][1];
}
main()
{
    int i;
    scanf("%d%d%d",&n,&s1,&s2);
    for(i=0;i<n;i++)scanf("%d",&x[i]);
    int l=fabs(s2-s1),r=inf,mid,ans=0;
    while(l<=r)
    {
        mid = 1ll*l+r>>1;
        if(check(mid))
        {
            ans = mid;
            r = mid-1;
        }
        else l = mid+1;
        //printf("%d %d %d\n",l,r,mid);
    }
    printf("%d",ans);
}
