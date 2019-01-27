#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
int mem[1000001];
main()
{
    int n,k,i,a,l=inf,r=0;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        mem[a]++;
        l = min(a,l);
        r = max(a,r);
    }
    long long ans=0;
    int t;
    while(r-l>k)
    {
        if(mem[l]>mem[r])
        {
            ans += mem[r];
            t = mem[r];
            mem[l]-=t;
            mem[r-1] += t;
            mem[l+1] += t;
            mem[r] = 0;
            r--;
        }
        else if(mem[r]>mem[l])
        {
            ans += mem[l];
            t = mem[l];
            mem[r] -=t;
            mem[l] -= t;
            mem[l+1] += t;
            mem[r-1] += t;
            l++;
        }
        else
        {
            ans += mem[l];
            t = mem[l];
            mem[r] -= t;
            mem[l] -= t;
            mem[l+1] += t;
            mem[r-1] += t;
            l++,r--;
        }
    }
    printf("%lld",ans);
}
