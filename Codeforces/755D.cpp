#include<bits/stdc++.h>
using namespace std;
main()
{
    long long n,k,i,ans=1,a=0,b=0;
    scanf("%I64d%I64d",&n,&k);
    k = min(k,n-k);
    for(i=0;i<n;i++)
    {
        if(a>n)b+=2;
        ans++;
        a%=n;
        a+=k;
        ans += b+(a>n);
        printf("%I64d ",ans);
    }
}
