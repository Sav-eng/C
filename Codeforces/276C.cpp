#include<bits/stdc++.h>
#define MAXN 200001
using namespace std;
int a[MAXN],b[MAXN],sum[MAXN];
bool cmp(int x,int y)
{
    return x>y;
}
main()
{
    int n,m,i,j,x,y;
    long long ans=0;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        sum[x]+=1;
        sum[y+1]+=-1;
    }
    for(i=1;i<=n;i++)sum[i] += sum[i-1];
    sort(&a[0],&a[n],cmp);
    sort(&sum[1],&sum[n+1],cmp);
    for(i=0;i<n;i++)
    {
        //printf("%d * %d\n",sum[i+1],a[i]);
        ans += (long long)sum[i+1]*a[i];
    }
    printf("%I64d",ans);
}
