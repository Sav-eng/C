#include<stdio.h>
#include<algorithm>
using namespace std;
int a[1005];
main()
{
    int n,i,_max=0,ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        _max = max(_max,a[i]);
    }
    for(i=-0;i<n;i++)
    {
        ans += _max-a[i];
    }
    printf("%d",ans);

}
