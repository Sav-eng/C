#include<bits/stdc++.h>
using namespace std;
struct node
{
    int Day,Minute;
};
int Time,n;
int vis[1001][1001];
int a[1001];
int b[1001];
node mem[1001][1001];
node combine(node x,node y)
{
    node ans;
    ans.Day = x.Day+y.Day;
    ans.Minute = x.Minute+y.Minute;
    if(ans.Minute>Time)
    {
        ans.Day++;
        ans.Minute = x.Minute;
    }
    return ans;
}
node dp(int x,int y)
{
    if(x==0 && y==0)return {0,0};
    else if(!vis[x][y])
    {
        node t,t2,t3,t4;
        vis[x][y] = 1;
        if(x!=0&& y!=0)
        {
            t = {0,a[x]};
            t2 = {0,b[y]};
            t3 = combine(t,dp(x-1,y));
            t4 = combine(t2,dp(x,y-1));
            if(t3.Day<t4.Day)mem[x][y] = t3;
            else if(t3.Day>t4.Day)mem[x][y] = t4;
            else mem[x][y] = (t3.Minute<t4.Minute)?t3:t4;
        }
        else if(y==0)
        {
            t = {0,a[x]};
            t3 = combine(t,dp(x-1,y));
            mem[x][y] = t3;
        }
        else
        {
            t2 = {0,b[y]};
            t4 = combine(t2,dp(x,y-1));
            mem[x][y] = t4;
        }
        //printf("mem[%d][%d] = %d,%d\n",x,y,mem[x][y].Day,mem[x][y].Minute);
    }
    return mem[x][y];
}
main()
{
    int i;
    node ans;
    scanf("%d",&Time);
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=1;i<=n;i++)scanf("%d",&b[i]);
    ans = dp(n,n);
    printf("%d\n%d",ans.Day+1,ans.Minute);
}
