#include<stdio.h>
#include<algorithm>
#define inf 1e9
using namespace std;
int a[100005];
main()
{
    int n,i,ans=0;
    int _min = inf;
    int _max =0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        _min = min(_min,a[i]);
        _max = max(_max,a[i]);
    }
    for(i=0;i<n;i++)
    {
        if(a[i] != _min && a[i] != _max)
        {
            ans++;
        }
    }
    printf("%d",ans);
}
