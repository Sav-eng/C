#include<stdio.h>
#include<algorithm>
using namespace std;
long long n,m,k,x,y;
long long a,b,c,d,e;
long long ans,ans2,ans3,ans4,ans1;
main()
{
    scanf("%d%d%lld%d%d",&n,&m,&k,&x,&y);
    a = (n-x)*m+(m-y)+1;
    if(x-n-1>0)a += y-1+(x-n-1)*m;
    if(y==m)a-=1;
    b = y-1+(x-1)*m+1;
    c =(m-y)+(x-1)*m + (x-2)*m + (y-1)+1;
    if(x-1==0)c = 0;
    d = a+c;
    e = (k-b)/d;
    ans4 = e+1;
    //printf("%lld",e+1);

    x = n; y = m;
    a = (n-x)*m+(m-y)+1;
    if(x-n-1>0)a += y-1+(x-n-1)*m;
    if(y==m)a-=1;
    b = y-1+(x-1)*m+1;
    c =(m-y)+(x-1)*m + (x-2)*m + (y-1)+1;
    if(x==1)c = x-1;
    d = a+c;
    printf("%lld",d);
    e = (k-b)/d;
    ans = e+1;
    //printf("%lld",ans);

    x = 2; y = 1;
    a = (n-x)*m+(m-y)+1;
    if(x-n-1>0)a += y-1+(x-n-1)*m;
    if(y==m)a-=1;
    b = y-1+(x-1)*m+1;
    c =(m-y)+(x-1)*m + (x-2)*m + (y-1)+1;
    if(x-1==0)c = 0;
    d = a+c;
    e = (k-b)/d;
    ans1 = e+1;
    //printf("%lld",d);

    x = n-1; y = 1;
    a = (n-x)*m+(m-y)+1;
    if(x-n-1>0)a += y-1+(x-n-1)*m;
    if(y==m)a-=1;
    b = y-1+(x-1)*m+1;
    c =(m-y)+(x-1)*m + (x-2)*m + (y-1)+1;
    if(x-1==0)c = 0;
    d = a+c;
    e = (k-b)/d;
    ans2 = e+1;
    ans3 = max(ans1,ans2);
    //printf("%lld %lld",ans1,ans2);
    printf("%lld %lld %lld",ans3,ans,ans4);
}
