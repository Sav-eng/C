#include<bits/stdc++.h>
using namespace std;
string s;
long long mem[201];
long long f(int x)
{
    if(x==s.size())return 0;
    else if(s[x]=='0')mem[x] = f(x+1);
    else if(!mem[x])
    {
        int i,j;
        long long t=0;
        for(i=1;i+x<=s.size();i++)
        {
            t = 0;
            for(j=0;j<i;j++)
            {
                t*=10;
                t+=s[j+x]-'0';
            }
            if(t>INT_MAX)break;
            mem[x] = max(mem[x],f(x+i)+t);
        }
    }
    return mem[x];
}
main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(mem,0,sizeof(mem));
        cin >> s;
        printf("%lld\n",f(0));
    }
}
