#include<bits/stdc++.h>
using namespace std;
int a[200001];
long long sum[200001];
main()
{
    int n,i,j;
    long long ans = LONG_LONG_MAX;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum[i] = sum[i-1]+a[i];
    }
    for(i=1;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            long long tmax =max(sum[i],max(sum[j]-sum[i],sum[n]-sum[j]));
            long long tmin =min(sum[i],min(sum[j]-sum[i],sum[n]-sum[j]));
            ans = min(ans,tmax-tmin);
            //printf("i = %d j = %d\n",i,j);
            //printf("\t %lld %lld-%lld(%lld) %lld-%lld(%lld) %lld\n",sum[i],sum[j],sum[i],sum[j]-sum[i],sum[n],sum[j],sum[n]-sum[j],ans);
        }
    }
    printf("%d",ans);
}
