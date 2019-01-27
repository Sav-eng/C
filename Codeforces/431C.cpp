#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int n,m,k;
long long mem[101][2];
int f(int x,bool check)
{
    if(x==n && check)return 1;
    else if(x==n)return 0;
    else if(mem[x][check]==-1)
    {
        int i;
        mem[x][check]=0;
        for(i=1;i<=m;i++)
        {
            if(x+i<=n)
            {
                if(i>=k)mem[x][check] = (mem[x][check]+f(x+i,1))%mod;
                else mem[x][check] = (mem[x][check]+f(x+i,check))%mod;
            }
        }
        //printf("mem[%d][%d] = %d\n",x,check,mem[x][check]);
    }
    return mem[x][check];
}
main()
{
    scanf("%d%d%d",&n,&m,&k);
    memset(mem,-1,sizeof(mem));
    printf("%d",f(0,0));
}
