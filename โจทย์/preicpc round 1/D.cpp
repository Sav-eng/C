#include<bits/stdc++.h>
using namespace std;
map<char,int>mp;
string s;
main()
{
    int i,ans=0;
    cin >> s;
    mp['0']=1;mp['1']=0;mp['2']=0;mp['3']=0;mp['4']=1;mp['5']=0;mp['6']=1;mp['7']=0;mp['8']=2;mp['9']=1;
    for(i=0;i<s.size();i++)
    {
        ans += mp[s[i]];
    }
    cout << ans;
}
