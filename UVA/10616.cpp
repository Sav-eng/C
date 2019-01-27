#include<bits/stdc++.h>
using namespace std;
int n,m,d;
long long mem[201][21][21];
int a[201];
long long f(int x,int y,int sum)
{
    if(x==n && y==m && sum==0)return 1;
    else if(x==n)return 0;
    else if(mem[x][y][sum]==-1)
    {
        long long t=a[x];
        if(t<0)t = (long long)d-(-t%d);
        else t= (long long)t%d;
        mem[x][y][sum] = f(x+1,y,sum);
        if(y+1<=m)mem[x][y][sum] += f(x+1,y+1,(t+sum)%d);
        //printf("mem[%d][%d][%d] = %lld\n",x,y,sum,mem[x][y][sum]);
    }
    return mem[x][y][sum];
}
main()
{
    int i,time,check=0,time2;
    //freopen("out.txt","w",stdout);
    while(scanf("%d%d",&n,&time)&&n&&time)
    {
        for(i=0;i<n;i++)scanf("%d",&a[i]);
        printf("SET %d:\n",++check);
        time2 = time;
        while(time--)
        {
            memset(mem,-1,sizeof(mem));
            scanf("%d%d",&d,&m);
            printf("QUERY %d: %lld\n",time2-time,f(0,0,0));
        }
    }
}
