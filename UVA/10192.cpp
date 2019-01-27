#include<bits/stdc++.h>
using namespace std;
int n,m;
int mem[101][101];
string s,s2,t,t2,k;
int f(int x,int y)
{
    if(x==n || y==m)return 0;
    else if(mem[x][y]==-1)
    {
        mem[x][y] = 0;
        if(s[x]==s2[y])mem[x][y] = f(x+1,y+1)+1;
        else mem[x][y] = max(f(x+1,y),f(x,y+1));
    }
    return mem[x][y];
}
main()
{
    //freopen("out.txt","w",stdout);
    int time=0;
    while(getline(cin,t))
    {
        if(t=="#")break;
        memset(mem,-1,sizeof(mem));
        ss.str(t);
        s.clear();
        while(ss>>k);
        s2.clear();
        getline(cin,t2);
        ss.str(t2);
        while(ss>>k)s2+=k;
        cout << "s=" << s << endl << "s2 = " << s2 << endl;
        n = s.size();
        m = s2.size();
        printf("Case #%d: you can visit at most %d cities.\n",++time,f(0,0));
    }
}
/*

abcd abc
abbc
#

*/

