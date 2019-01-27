#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+1;
int FT[MAXN];
int a[MAXN];
int b[MAXN];
int link[MAXN];
int n;
map<int,int>mp;
int mp2[MAXN];
void update(int x,int val){for(;x<=MAXN;x+=x&-x)FT[x]+=val;}
int query(int x){
    int ans =0;
    for(;x>0;x-=x&-x)ans += FT[x];
    return ans;
}
main()
{
    int check,i;
    scanf("%d",&n);
    check = 1;
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&a[i],&b[i]);
        mp[a[i]] = 0;
        mp[b[i]] = 0;
    }
    for(auto it = mp.begin();it!=mp.end();it++)
    {
        it->second = check;
        mp2[check] = it->first;
        link[check] = check;
        check++;
        //printf("mp2[%d] = %d\n",check-1,mp2[check-1]);
    }
    for(i=0;i<n;i++)swap(link[mp[a[i]]],link[mp[b[i]]]);
    long long ans = 0;
    for(i=1;i<check;i++)
    {
        //printf("%d ",link[i]);
        update(link[i],1);
        ans += i-query(link[i]) + abs(mp2[i]-mp2[link[i]]) - abs(i-link[i]);
        //printf("%lld update(%d) pos1(%d-%d) pos2(%d-%d)\n",ans,link[i],mp2[i],mp2[link[i]],i,link[i]);
    }
    printf("%I64d",ans);
}
