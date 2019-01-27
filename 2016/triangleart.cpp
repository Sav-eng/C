#include<stdio.h>
#include<algorithm>
#define mod 1000000007
using namespace std;
int n,m;
long long mem[205][205];
int f(int x,int y)
{
    if(x==n && y==n)return 1;
    else if(x>n || y>n)return 0;
    else
    {
        if(mem[x][y]!=0)return mem[x][y];
        int i;
        for(i=1;i<=m;i++)
        {
            mem[x][y] = (mem[x][y] + f(x+i+1,y+1)+mod)%mod;
        }
        for(i=1;i<=m;i++)
        {
            mem[x][y] = (mem[x][y] + f(x+1,y+i+1)+mod)%mod;
        }
        mem[x][y] = (mem[x][y] + f(x+1,y)+f(x,y+1)-f(x+1,y+1)+mod)%mod;
        return mem[x][y];
    }
}
main()
{
    scanf("%d%d",&n,&m);
    printf("%d",f(0,0)-1);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=1;k<=m;k++)
            {
                mem[x][y] = (mem[x][y] + f(x+k+1,y+1)+mod)%mod;
            }
            for(k=1;k<=m;k++)
            {
                mem[x][y] = (mem[x][y] + f(x+1,y+k+1)+mod)%mod;
            }
        }
    }
}
