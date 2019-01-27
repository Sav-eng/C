#include<bits/stdc++.h>
using namespace std;
bool leaf(int day)
{
    int i;
    int now=0;
    for(i=0;i<n;i++)
    {
        if((a[i]-now)%2==0)
        {

        }
        else
        {

        }
    }
}
main()
{
    scanf("%d%d\n",&n,&m);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    long long l=0,r=inf,mid;
    for(;;);
    while(l<r)
    {
        mid = l+r>>1;
        if(leaf(mid)>=m)
        {
            ans = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
}
