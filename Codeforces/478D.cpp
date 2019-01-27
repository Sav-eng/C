#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long mem[200001];
/*int f(int x,int y)// y mean red
{
    if(x==n)return 1;
    else if(!mem[x][y])
    {
        int diff = g-((x*(x+1)/2)-y);
        if(diff >= x)mem[x][y] = (f(x+1,y)+mem[x][y])%mod;
        if(r-y >= x)mem[x][y] = (mem[x][y] + f(x+1,y))%mod;
    }
}*/
long long ans;
main()
{
    int r,g,i,j,n;
    scanf("%d%d",&r,&g);
    n = 1;
    while(n*(n+1)/2<=r+g)n++;
    n--;
    bool flag = 1;
    int num = 0;
    //printf("%d\n",n);
    mem[0]= 1;
    for(i=1;i<=n;i++)
    {
        num+=i;
        /*for(j=0;j<=r;j++)
        {
            mem[flag][j] = 0;
            int diff = g-(num-j);
            if(diff>=0)mem[flag][j] = (mem[flag][j]+mem[!flag][j])%mod;
            if(j-i>=0)mem[flag][j] = (mem[flag][j]+ mem[!flag][j-i])%mod;
            //if(i==n)ans = (ans + mem[flag][j])%mod;
            //printf("mem[%d][%d] = %d\n",i,j,mem[flag][j]);
        }
        flag = !flag;*/
        for(j=min(r,num);j>=i;j--)mem[j] = (mem[j]+mem[j-i])%mod;
    }
    for(i=max(0,n*(n+1)/2-g);i<=r;i++)ans = (ans+mem[i])%mod;
    printf("%I64d",ans);
}
/*
200000 200000
*/
