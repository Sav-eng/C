#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
main()
{
    int n,i,ans=-inf,a,b,m;
    int _max1,_max2,_min1,_min2;
    _max1 = _max2 = -inf;
    _min1 = _min2 = inf;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        _max1 = max(a,_max1);
        _min1 = min(b,_min1);
    }
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&a,&b);
        _max2 = max(a,_max2);
        _min2 = min(b,_min2);
    }
    //printf("%d %d %d %d",_max1,_min1,_max2,_min2);
    ans = max(_max1-_min2,_max2-_min1);
    if(ans>0)printf("%d",ans);
    else printf("0");
}
