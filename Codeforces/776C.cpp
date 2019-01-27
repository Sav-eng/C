#include<bits/stdc++.h>
#define inf 1e15
#define MAXN 100001
using namespace std;
long long sum[MAXN];
int a[MAXN];
map<long long,int>mp;
main()
{
    int n,i,j;
    long long k;
    scanf("%d%I64d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sum[i] = (long long)a[i]+sum[i-1];
    }
    long long K=1;
    long long ans=0;
    int check = 0;
    while(K<=inf && K>= -inf)
    {
        if(k==1 || k==-1)check++;
        if(check==3 && k==-1)break;
        else if(check ==2 && k==1)break;
        //printf("%d ",K);
        mp.clear();
        mp[0]++;
        for(i=0;i<n;i++)
        {
            long long x= sum[i]-K;
            if(mp.find(x)!=mp.end())ans+=mp[x];
            mp[sum[i]]++;
        }
        K*=k;
    }
    printf("%I64d",ans);
}


/*
10 2
1 0 0 0 0 0 0 0 0 0 0


*/
