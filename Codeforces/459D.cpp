#include<bits/stdc++.h>
#define inf 1e9
#define MAXN 1000001
using namespace std;
map<int,int>cnt;
int tree[MAXN];
int add(int x,int val)
{
    while(x>0)
    {
        tree[x]+=val;
        x -= x&-x;
    }
}
int sum(int x)
{
    int ans=0;
    while(x<MAXN)
    {
        ans+=tree[x];
        x+=x&-x;
    }
    return ans;
}
int a[MAXN];
int tab[MAXN];
main()
{
    int n,i,now;
    long long ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
        tab[i] = ++cnt[a[i]];
        add(tab[i],1);
    }

    cnt.clear();
    for(i=n-1;i>=0;i--)
    {
        add(tab[i],-1);
        now = ++cnt[a[i]];
        ans += sum(now+1);
    }
    printf("%I64d",ans);
}
