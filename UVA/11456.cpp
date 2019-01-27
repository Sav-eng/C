#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
int n,ans;
int mem[2000][50000];
int mem2[2000][50000];
int a[2000];
int f1(int x,int y)
{
    if(x==n)return 0;
    if(!mem[x][y])
    {
        mem[x][y] = f1(x+1,y);
        if(a[x]>y)mem[x][y] = max(f1(x+1,a[x])+1,mem[x][y]);
    }
    return mem[x][y];
}
int f2(int x,int y)
{
    if(x==n)return 0;
    if(!mem2[x][y])
    {
        mem2[x][y] = f2(x+1,y);
        if(a[x]<y)mem2[x][y] = max(f2(x+1,a[x])+1,mem2[x][y]);
    }
    return mem2[x][y];
}
main()
{
    //freopen("out.txt","w",stdout);
    int time,i,j;
    scanf("%d",&time);
    while(time--)
    {
        //memset(mem,0,sizeof(mem));
        //memset(mem2,0,sizeof(mem));
        ans = 0;
        memset(a,0,sizeof(a));
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<n;i++)
        {
            ans = max(ans,f1(i+1,a[i])+1+f2(i+1,a[i])+1-1);
        }
        printf("%d\n",ans);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                mem[i][a[j]] = 0;
                mem2[i][a[j]] = 0;
            }
        }
    }
}
