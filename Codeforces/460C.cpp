#include<bits/stdc++.h>
#define inf 2e9
using namespace std;
int n,m,k;
int sum[100001];
int a[100001];
int b[100001];
bool check(int x)
{
    int t2 = 0;
    int t,i;
    for(i=0;i<n;i++)b[i] = a[i],sum[i] = 0;
    for(i=0;i<n;i++)
    {
        sum[i] += sum[i-1];
        b[i]+=sum[i];
        t = 0;
        while(b[i]+t<x)
        {
            t++;
            t2++;
            if(t2>m)return 0;
        }
        //printf("x = %d sum = %d\n",x,b[i]+t);
        sum[i] += t;
        if(i+k<n)sum[i+k]-=t;
    }
    //printf("mid = %d t2 = %d\n",x,t2);
    if(t2>m)return 0;
    return 1;
}
main()
{
    int i,_max=0,ans = 0;
    long long l,r,mid;
    scanf("%d%d%d",&n,&m,&k);//t la k //m t
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    l = 0,r = inf;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(check(mid))
        {
            ans = mid;
            l = mid+1;
        }
        else r = mid-1;
        //printf("l = %d r = %d mid = %d ans = %d\n",l,r,mid,ans);
    }
    printf("%d",ans);
}
