#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
string s;
int mem[1001][1001];
int trac[1001][1001];
int f(int l,int r)
{
    if(l>=r)return 0;
    else if(!mem[l][r])
    {
        if(s[l]==s[r])
        {
            mem[l][r] = f(l+1,r-1);
            trac[l][r] = 1;
        }
        else
        {
            mem[l][r] = inf;
            int t,t2;
            t = f(l+1,r)+1;
            t2 = f(l,r-1)+1;
            if(mem[l][r] >t)
            {
                mem[l][r] = t;
                trac[l][r] = 2;
            }
            if(mem[l][r] > t2)
            {
                mem[l][r] = t2;
                trac[l][r] = 3;
            }
        }
    }
    return mem[l][r];
}
void path(int l,int r)
{
    if(l>r) return ;
    else
    {
        if(l==r)printf("%c",s[l]);
        else if(trac[l][r] ==1)
        {
            printf("%c",s[l]);
            path(l+1,r-1);
            printf("%c",s[l]);
        }
        else if(trac[l][r]==2)
        {
            printf("%c",s[l]);
            path(l+1,r);
            printf("%c",s[l]);
        }
        else
        {
            printf("%c",s[r]);
            path(l,r-1);
            printf("%c",s[r]);
        }
    }
}
main()
{
    while(cin >> s)
    {
        memset(mem,0,sizeof(mem));
        memset(trac,0,sizeof(trac));
        printf("%d ",f(0,s.size()-1));
        path(0,s.size()-1);
        printf("\n");
    }
}
