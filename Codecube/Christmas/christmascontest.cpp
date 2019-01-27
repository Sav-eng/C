#include<stdio.h>
long long laka[100][10];
long long lakb[100][10];
long long ans=0;
long long a,b;
main()
{
    long long n,i,j,m;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&a);
        for(j=0;j<27;j++)
        {
            if((a&(1<<j))!=0)laka[j][1]++;
            else laka[j][0]++;
        }
    }
    scanf("%lld",&m);
    for(i=0;i<m;i++)
    {
        scanf("%lld",&b);
        for(j=0;j<27;j++)
        {
            if((b&(1<<j))!=0)lakb[j][1]++;
            else lakb[j][0]++;
        }
    }
    for(i=0;i<27;i++)
    {
        ans += (long long)((long long)(1<<i)*(long long)((long long)(laka[i][0]*lakb[i][1])+(long long)(laka[i][1]*lakb[i][0])));
    }
    printf("%lld",ans);
}
