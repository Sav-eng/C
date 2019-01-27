#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+1;
int mem[MAXN];
int n;
int a[MAXN];
int dp(int x)
{
    if(x>=n)return 0;
    else if(!mem[x])
    {
        mem[x] = dp(x+1);
        if(x+1<n)mem[x] = max(mem[x],dp(x+3)+a[x+1]);
    }
    return mem[x];
}
main()
{
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    printf("%d",dp(1));
}
