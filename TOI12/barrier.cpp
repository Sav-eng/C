#include<bits/stdc++.h>
using namespace std;
int a[600001];
main()
{
    int i,n,k;
    int _max=0;
    int sum=0;
    int s=0,e=0;
    int ans=1e9;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sum = 0;
    for(i=0;i<n;i++)
    {
        sum+=a[i];
        if(sum<0)
        {
            sum = 0;
            s = i+1;
            e = i+1;
        }
        else e = i;
        if(e-s+1>k)
        {
            sum-=a[s++];
        }
        if(_max<=sum)
        {
            _max = sum;
            if(e-s+1<ans)ans = e-s+1;
        }
    }
    if(_max==0)printf("0\n0");
    else printf("%d\n%d",_max,ans);
}
