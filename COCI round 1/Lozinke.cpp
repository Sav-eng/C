#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int prime = 37;
const int prime2 = 31;
const int mod = 1e9+7;
ll pref[15];
ll pref2[15];
ll has[20005];
ll has2[20005];
string s[20005];
map<pair<ll,ll>,int>mp;
map<pair<ll,ll>,int>check;
main()
{
    int n,i,j,k,T,N,ans=0;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;

    for(i=0;i<10;i++)
    {
        if(!i)pref[i] = 1;
        else
        {
            pref[i] = (1ll*pref[i-1] * prime)%mod;
        }
        //cout << pref[i] << endl;
    }
    for(i=0;i<10;i++)
    {
        if(!i)pref2[i] = 1;
        else
        {
            pref2[i] = (1ll*pref2[i-1] * prime2)%mod;
        }
        //cout << pref[i] << endl;
    }
    for(i=0;i<n;i++)
    {
        cin >> s[i];
        N = s[i].size();
        for(j=0;j<N;j++)
        {
            has[i] = (1ll*has[i]+(1ll*s[i][j]-'a'+1)*pref[j])%mod;
            has2[i] = (1ll*has2[i]+(1ll*s[i][j]-'a'+1)*pref2[j])%mod;
        }
        //cout << has[i] << endl;
        mp[make_pair(has[i],has2[i])]++;
        //cout << "have---->" << mp[has[i]] << endl;
    }
    for(i=0;i<n;i++)
    {
        pair<ll,ll> except = make_pair(has[i],has2[i]);
        N = s[i].size();
        ll t=0;
        ll t2 = 0;
        for(j=1;j<=N;j++)
        {
            check.clear();
            t = 0;
            t2 = 0;
            //cout << "j--> " << j << endl;
            for(k=0;k<j;k++)
            {
                t = (1ll*t+1ll*(s[i][k]-'a'+1)*pref[k])%mod;
                t2 = (1ll*t2+1ll*(s[i][k]-'a'+1)*pref2[k])%mod;
                //cout << "0----->" << k << " "<< t << endl;
            }
            //cout << "FIRST\n";
            pair<ll,ll>T = make_pair(t,t2);
            if(mp[T]!=0 && check[T]!=1)
            {
                check[T] = 1;
                if(T==except)
                {
                    ans += mp[T]-1;
                }
                else ans += mp[T];
            }
            for(;k<N;k++)
            {
                t-= s[i][k-j]-'a'+1;
                t/= 1ll*prime;
                t = (1ll*t+(1ll*(s[i][k]-'a'+1)*pref[j-1]))%mod;
                t2-= s[i][k-j]-'a'+1;
                t2/= 1ll*prime2;
                t2 = (1ll*t2+(1ll*(s[i][k]-'a'+1)*pref2[j-1]))%mod;
                T = make_pair(t,t2);
                //cout << k-j+1 << "----->" << k << " "<< t << endl;
                if(mp[T]!=0 && check[T]!=1)
                {
                    check[T] = 1;
                    if(T==except)
                    {
                        ans += mp[T]-1;
                    }
                    else ans += mp[T];
                }
            }
            //cout << "end " << "ans = "<<ans << endl;
        }

    }
    cout << ans;
}
/*
2
aaaaaaaaaa
aaaaaaaaaa

*/
