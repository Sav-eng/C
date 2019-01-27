#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int b[1000001];
main()
{
    int n,ans=0,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    for(i=0;i<n;i++)scanf("%d",&b[i]);
    sort(a,a+n);
    sort(b,b+n);
    for(i=0;i<n;i++)ans = max(ans,min(a[i],b[n-i-1]));
    printf("%d",ans);
}
