#include<stdio.h>
#include<algorithm>
using namespace std;
char x;
int p[100005];
int s[100005];
int h[100005];
main()
{
    freopen("hps.in","r",stdin);
    freopen("hps.out","w",stdout);
    int n,i,ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf(" %c",&x);
        if(x=='P')p[i]++;
        else if(x=='H')h[i]++;
        else s[i]++;
    }
    for(i=0;i<n;i++)
    {
        p[i] = p[i]+p[i-1];
        h[i] = h[i]+h[i-1];
        s[i] = s[i]+s[i-1];
    }
    for(i=0;i<n;i++)
    {
        ans = max(p[i]+s[n-1]-s[i],ans);
        ans = max(p[i]+h[n-1]-h[i],ans);
        ans = max(h[i]+p[n-1]-p[i],ans);
        ans = max(h[i]+s[n-1]-s[i],ans);
        ans = max(s[i]+h[n-1]-h[i],ans);
        ans = max(s[i]+p[n-1]-p[i],ans);
    }
    printf("%d",ans);

}
