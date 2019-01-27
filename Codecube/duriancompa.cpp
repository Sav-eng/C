#include<stdio.h>
#include<algorithm>
using namespace std;
int _max,_min;
int sum[1000005];
int ans;
main()
{
    int n,l,r,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&l,&r);
        sum[l]++;
        sum[r]--;
        _max =max(_max,r);
        _min =min(_min,l);
    }
    for(i=_min;i<=_max+1;i++)
    {
        sum[i]=sum[i-1]+sum[i];
        ans = max(sum[i],ans);
        //printf("sum[%d] = %d\n",i,sum[i]);
    }

    printf("%d",ans);
}
