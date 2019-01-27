#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long sum[1000001];
int h[1000001];
int check(int H)
{
    int _k=0,i,destroy;
    memset(sum,0,sizeof(sum));
    for(i=0;i<n;i++)
    {

        if(i!=0)sum[i] += sum[i-1];
        if(h[i]-sum[i]>H)
        {
            destroy = h[i]-H-sum[i];
            _k += destroy;
            sum[i]+=destroy;
            sum[i+m]-=destroy;
        }
        //printf("sum[%d] = %d\n",i,sum[i]);
    }
   // printf("H = %d _k = %d\n",H,_k);
    return _k<=k;
}
main()
{
    int _max,i,l,r,mid,ans;
    scanf("%d%d%d",&n,&m,&k);
    _max = 0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&h[i]);
        _max = max(h[i],_max);
    }
    l = 0;
    r = _max;
    while(l<=r)
    {

        mid = (l+r)/2;
        //printf("l = %d r = %d mid = %d\n",l,r,mid);
        if(check(mid))
        {
            ans = mid;
            r = mid-1;
        }
        else
        {

            l = mid+1;
        }

    }
    printf("%d",ans);
}
/*

5 3 3
2 4 3 5 1



*/
