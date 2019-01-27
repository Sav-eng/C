#include<bits/stdc++.h>
using namespace std;
long long sum[1000001];
main()
{
    int n,i,a;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        sum[i] = sum[i-1] +a;
    }
    if(sum[n-1]%3!=0)
    {
        printf("0");
        return 0;
    }
    long long half = sum[n-1]/3;
    long long cnt=0,ans=0;
    //printf("%d",half);
    for(i=0;i<n-1;i++)
    {
        if(sum[i]==half*2)ans+=cnt;
        if(sum[i]==half)cnt++;
    }
    printf("%I64d",ans);
}
