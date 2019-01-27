#include<bits/stdc++.h>
using namespace std;
map<long long,int>mem;
main()
{
    int n,a,i,ans;
    long long sum;
    scanf("%d",&n);
    ans = n-1;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        sum+=a;
        mem[sum]++;
        ans = min(ans,n-mem[sum]);
    }
    printf("%d",ans);
}
