#include<stdio.h>
#include<string.h>
#define mod 1000000007
int n,k;
long long mem[105][105][5];
long long f(int x,int y,int ok)
{
    int i;
    if(x==n && y==n) return ok;
    if(mem[x][y][ok]==-1)
    {
        mem[x][y][ok] = 0;
        if(x<n && y>=n) mem[x][y][ok] = (mem[x][y][ok] + f(x+1,y,ok) + mod)%mod;//,printf("\t\t\t%d %d %d -> %d %d %d (%d)\n",x,y,ok,x+1,y,ok,f(x+1,y,ok));
        if(y<n && x>=n) mem[x][y][ok] = (mem[x][y][ok] + f(x,y+1,ok) + mod)%mod;//,printf("\t\t\t%d %d %d -> %d %d %d (%d)\n",x,y,ok,x,y+1,ok,f(x,y+1,ok));
        if(x<n && y<n) mem[x][y][ok] = (mem[x][y][ok] + f(x+1,y,ok) + f(x,y+1,ok) - f(x+1,y+1,ok) + mod)%mod;
        for(i=1;i<=k;i++)
        {
            if(x+i<n && y<n)
            {
                mem[x][y][ok] = (mem[x][y][ok] + f(x+i+1,y+1,1) + mod)%mod;
                //printf("\t\t\t%d %d %d -> %d %d %d (%d)\n",x,y,ok,x+i+1,y+1,1,f(x+i+1,y+1,1));
            }
        }
        for(i=1;i<=k;i++)
        {
            if(y+i<n && x<n)
            {
                mem[x][y][ok] = (mem[x][y][ok] + f(x+1,y+i+1,1) + mod)%mod;
                //printf("\t\t\t%d %d %d -> %d %d %d (%d)\n",x,y,ok,x+1,y+i+1,1,f(x+1,y+i+1,1));
            }
        }
        //printf("mem %d %d %d = %d\n",x,y,ok,mem[x][y][ok]);
    }
    return mem[x][y][ok];
}
main()
{
    scanf("%d%d",&n,&k);
    memset(mem,-1,sizeof(mem));
    printf("%lld",f(0,0,0));
}
