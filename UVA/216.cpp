#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
double ans;
int n;
double mem[9][1<<9];
double dis[9][9];
int a[9];
int b[9];
int trac[9][1<<9];
double dis2(int x,int y)
{
    double t1,t2,ans;
    t1 = a[x]-a[y];
    if(t1<0)t1 = -t1;
    t2 = b[x]-b[y];
    if(t2<0)t2 = -t2;
    ans = sqrt((t1*t1)+(t2*t2));
    //printf("[%d][%d] = %lf %lf\n",x,y,t1,t2);
    return ans;
}
double f(int x,int bit)
{
    if(bit == (1<<n)-1)return 0;
    else if(mem[x][bit]==0)
    {
        mem[x][bit] = inf;
        int i;
        for(i=0;i<n;i++)
        {
            //printf("a");
            if(!((bit>>i)&1))
            {
                if(mem[x][bit] > f(i,bit|(1<<i))+dis[x][i])
                {
                    mem[x][bit] = f(i,bit|(1<<i))+dis[x][i];
                    trac[x][bit] = i;
                    //printf("trac[%d][%d] = %d\n",x,bit,trac[x][bit]);
                }
            }
        }
    }
    //printf("mem[%d][%d] = %lf\n",x,bit,mem[x][bit]);
    return mem[x][bit];
}
main()
{
    int i,j;
    int check=0;
    while(scanf("%d",&n)&&n)
    {
        for(i=0;i<n;i++)scanf("%d%d",&a[i],&b[i]);
        memset(mem,0,sizeof(mem));
        memset(trac,0,sizeof(trac));
        memset(dis,0,sizeof(dis));
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                dis[i][j] = dis2(i,j)+16;
                //printf("%.2lf ",dis[i][j]);
            }
            //printf("\n");
        }
        printf("**********************************************************\n");
        printf("Network #%d\n",++check);
        ans = inf;
        int x,bit;
        for(i=0;i<n;i++)
        {
            if(ans>f(i,1<<i))
            {
                x = i;
                bit = 1<<i;
                ans = f(i,1<<i);
            }
        }
        int t;
        //printf("trac[%d][%d] = %d",x,bit,trac[x][bit]);
        while(bit!=(1<<n)-1)
        {
            t = trac[x][bit];
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",a[x],b[x],a[t],b[t],dis[x][t]);
            x= t;
            bit |= (1<<x);
        }
        printf("Number of feet of cable required is %.2lf.\n",ans);
    }
}
