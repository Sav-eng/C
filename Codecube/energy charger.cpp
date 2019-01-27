#include<stdio.h>
#define inf 1e9
#include<algorithm>
using namespace std;
int a[1000005];
main()
{
    int n,k,i,mid,en,now,cnt,l,r,_min=0,_max=0,mx=0;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        mx = max(mx,a[i]);
    }
    if(k==1 || k==n)
    {
        printf("-1");
        return 0;
    }
    l = mx;
    r = inf;
    while(l<=r)
    {
        mid = (l+r)/2;
        en = mid;
        now = 0;
        cnt = 0;
        for(i=0;i<n;i++)
        {
            if(now-a[i]<0)
            {
                cnt++;
                now=en;
            }
            now-=a[i];
        }
        //printf("\n");
        if(cnt<=k)
        {
            _min = en;
            r = mid-1;
        }
        else
        {
            l = mid+1;
        }
    }
    l = mx;
    r = inf;
    while(l<=r)
    {
        mid = (l+r)/2;
        en = mid;
        now = 0;
        cnt = 0;
        for(i=0;i<n;i++)
        {
            if(now-a[i]<0)
            {
                cnt++;
                now=en;
            }
            now-=a[i];
        }
        //printf("\n");
        if(cnt>=k)
        {
            l = mid+1;
            _max = en;
        }
        else r = mid-1;
    }
    printf("%d",_max-_min+1);

}
