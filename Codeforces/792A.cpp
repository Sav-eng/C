#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
int a[200001];
main()
{
    int n,i,ans,ans2;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    sort(&a[0],&a[n]);
    ans = 2*inf;
    for(i=0;i<n-1;i++)
    {
        ans = min(ans,a[i+1]-a[i]);
    }
    ans2=0;
    for(i=0;i<n-1;i++)
    {
        if(a[i+1]-a[i]==ans)ans2++;
    }
    printf("%d %d",ans,ans2);

}
