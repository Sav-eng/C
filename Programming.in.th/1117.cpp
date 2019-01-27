#include<stdio.h>
#include<algorithm>
#include<limits.h>
using namespace std;
bool cmp(long long x,long long y)
{
    return x>y;
}
int n,i;
long long sum=0;
long long ans = LONG_LONG_MIN;
long long x[1000000];
long long a,b;
main()
{
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld%lld",&a,&b);
        x[i] = b-2*a;
        sum+=x[i];
    }
    sort(&x[0],&x[n],cmp);
    long long check=1;
    for(i=n-1;i>=0;i--)
    {
        sum -= check;
        sum -= x[i];
        ans =  max(ans,sum);
        check+=2;
    }
    printf("%lld",ans);
}
