#include<bits/stdc++.h>
using namespace std;
int mem[1001][1001];
string s;
int f(int l,int r)
{
    if (l>r)return 0;
    else if(!mem[l][r])
    {
        if(s[l]==s[r] && l!=r)mem[l][r] = f(l+1,r-1)+2;
        else if(s[l]==s[r])mem[l][r] = f(l+1,r-1)+1;
        else mem[l][r] = max(f(l+1,r),f(l,r-1));
    }
    return mem[l][r];
}
main()
{
    int T;
    scanf("%d",&T);
    getline(cin,s);
    while(T--)
    {
        memset(mem,0,sizeof(mem));
        getline(cin,s);
        printf("%d\n",f(0,s.size()-1));
    }
}
