#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
struct node
{
    int x,y;
};
int cx[] = {0,0,-1,1};
int cy[] = {1,-1,0,0};
queue<node>q;
int Map[1001][1001];
int mem[1001][1001];
int mem2[1001][1001];
int mem3[1001][1001];
int mem4[1001][1001];
bool vis[1001][1001];
main()
{
    int n,i,j;
    char x;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf(" %c",&x);
            Map[i][j] = (x=='1')?1:0;
        }
    }
    q.push({0,0});
    mem[0][0] = 1;
    node t;
    while(!q.empty())
    {
        t = q.front(); q.pop();
        if(vis[t.x][t.y])continue;
        vis[t.x][t.y] = 1;
        mem[t.x+1][t.y] = (mem[t.x+1][t.y]+mem[t.x][t.y])%mod;
        mem3[t.x+1][t.y] = mem3[t.x][t.y]+1;
        if(!vis[t.x+1][t.y] && Map[t.x+1][t.y])q.push({t.x+1,t.y});
        mem[t.x][t.y+1] = (mem[t.x][t.y+1]+mem[t.x][t.y])%mod;
        mem3[t.x][t.y+1] = mem3[t.x][t.y]+1;
        if(!vis[t.x][t.y+1] && Map[t.x][t.y+1])q.push({t.x,t.y+1});
        //printf("%d %d\n",t.x,t.y);
    }
    q.push({n-1,0});
    mem2[n-1][0] = 1;
    memset(vis,0,sizeof(vis));
    while(!q.empty())
    {
        t = q.front(); q.pop();
        if(vis[t.x][t.y])continue;
        vis[t.x][t.y] = 1;
        mem2[t.x][t.y+1] = (mem2[t.x][t.y+1] + mem2[t.x][t.y])%mod;
        mem4[t.x][t.y+1] = mem4[t.x][t.y]+1;
        if(!vis[t.x][t.y+1] && Map[t.x][t.y+1])q.push({t.x,t.y+1});
        mem2[t.x-1][t.y] = (mem2[t.x-1][t.y]+mem2[t.x][t.y])%mod;
        mem4[t.x-1][t.y] = mem4[t.x][t.y]+1;
        if(!vis[t.x-1][t.y] && Map[t.x-1][t.y] && t.x-1>=0)q.push({t.x-1,t.y});
        //printf("%d %d\n",t.x,t.y);
    }
    /*for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",mem[i][j]);
        }
        printf("\n");
    }
    printf("-------------------------------------------------------------------------------\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",mem2[i][j]);
        }
        printf("\n");
    }*/
    int ans=0;
    int k;
    int t1,t2;
    for(i=1;i<n-1;i++)
    {
        for(j=1;j<n-1;j++)
        {
            int check = 0;
            for(k=0;k<4;k++)if(Map[i+cx[k]][j+cy[k]])check++;
            if(check==4 && Map[i][j])
            {
                t1 = 0;
                t2 = 0;
                if(mem4[i][j-1]!=0 && mem3[i-1][j]!=0)t1 = (mem2[i][j-1]*mem[i-1][j])%mod;
                if(mem4[i+1][j]!=0 && mem3[i][j-1]!=0)t2 = (mem2[i+1][j]*mem[i][j-1])%mod;
                ans = (ans + t1+t2)%mod;
                //printf("%lld %lld %lld %lld\n",mem[i][j],mem2[i][j],t1,t2);
            }
        }
    }
    printf("%d",ans);
}
/*

4
1111
1111
1111
1111

*/
