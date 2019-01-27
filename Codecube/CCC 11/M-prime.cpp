#include<bits/stdc++.h>
using namespace std;
map<long long,int>mp;
main()
{
    long long t = 1;
    int i;
    int t2,j;
    bool check;
    /*for(i=0;i<=64;i++)
    {
        t2 = sqrt(i);
        check = 0;
        for(j=2;j<=t2;j++)if(i%j==0)check=1;
        if(!check)mp[t-1] = 1;
        t<<=1;
    }
    mp.erase(11);
    mp.erase(1);
    mp.erase(23);
    mp.erase(29);
    mp.erase(37);
    mp.erase(41);
    mp.erase(43);
    mp.erase(47);
    mp.erase(53);
    mp.erase(59);*/
    mp[3] = 1;
    mp[7] = 1;
    mp[31] = 1;
    mp[127] = 1;
    mp[8191] = 1;
    mp[131071] = 1;
    mp[524287] = 1;
    mp[2147483647] = 1;
    mp[2305843009213693951] = 1;
    int T;
    long long a;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld",&a);
        if(mp.find(a)==mp.end())printf("NO\n");
        else printf("YES\n");
    }
}
