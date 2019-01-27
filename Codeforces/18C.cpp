#include<bits/stdc++.h>
using namespace std;
long long sum[100001];
int a[100001];
main()
{
    int n,i,ans;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sum[i] = (long long)sum[i-1]+a[i];
    }
    ans = 0;
    /*for(i=0;i<n;i++)
        if(a[i]>0)printf("%d ",i);
        else printf(" %d ",i);
    printf("\n");*/
    for(i=0;i<n-1;i++)
    {
        //printf("%d ",sum[i]);
        if(2*sum[i]==sum[n-1])ans++;
        //printf("i = %d ans = %d\n",i,ans);
    }
    printf("%d",ans);
}
