#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
map<int,int>havel,haver;
int b[200001];
main()
{
    int n,k,i;
    long long ans = 0;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
        haver[b[i]]++;
    }
    for(i=0;i<n;i++)
    {
        haver[b[i]]--;
        if(b[i]%k==0 && (long long)b[i]*k<=(long long)inf && (long long)b[i]*k >= (long long)-inf)ans += (long long)havel[b[i]/k]*haver[b[i]*k];
        havel[b[i]]++;
        //printf("%I64d ",ans);
    }
    printf("%I64d",ans);
}
