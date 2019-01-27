#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
char x[1001];
int mem[1001][1001];
int f(int l,int r)
{
    if(l>=r)return 0;
    else if(!mem[l][r])
    {
        mem[l][r] = inf;
        if(x[l]==x[r])mem[l][r] = f(l+1,r-1);
        else mem[l][r] = min(f(l+1,r)+1,min(f(l,r-1)+1,f(l+1,r-1)+1));
    }
    return mem[l][r];
}
main()
{
    //freopen("out.txt","w",stdout);
    int T,time=0;
    scanf("%d",&T);
    while(T--)
    {
        memset(mem,0,sizeof(mem));
        scanf("%s",x);
        printf("Case %d: %d\n",++time,f(0,strlen(x)-1));
    }
}
