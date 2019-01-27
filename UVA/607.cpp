#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
struct node
{
    int x,y;// x = lecture y = DI
};
node mem[1001][501];
int a[1001];
int n,m,k;
node f(int x,int y)//x = topic y = time in this lecture
{
    if(x==n && y==k)return {1,0};
    else if(x==n && k-y <=10)return {1,-m};
    else if(x==n)return {1,((k-y-10)*(k-y-10))};
    else if(mem[x][y].x ==0 || mem[x][y].y == 0)
    {
        node t,t2;
        t2.x = t2.y = inf;
        t.x = t.y = inf;
        if(y==k)
        {
            t = f(x+1,a[x]);
            t.x++;
        }
        else if(k-y<=10)
        {
            t = f(x+1,a[x]);
            t.x++;
            t.y-=m;
        }
        else
        {
            t = f(x+1,a[x]);
            //printf("%d %d\n",t.x,t.y);
            t.x++;
            t.y+=((k-y-10)*(k-y-10));
        }
        if(y+a[x]<=k)
        {
            t2 = f(x+1,a[x]+y);
        }
        if(t.x<t2.x) mem[x][y] = t;
        else if(t.x==t2.x)
        {
            if(t.y>t2.y) mem[x][y] = t2;
            else mem[x][y] = t;
        }
        else mem[x][y] = t2;
        //printf("mem[%d][%d] = %d %d\n",x,y,mem[x][y].x,mem[x][y].y);
    }

    return mem[x][y];
}
main()
{
    //freopen("out.txt","w",stdout);
    int i,x,ans=0,cnt=0;
    node t;
    while(scanf("%d",&n)&& n)
    {
        memset(mem,0,sizeof(mem));
        scanf("%d%d",&k,&m);
        for(i=0;i<n;i++)scanf("%d",&a[i]);
        if(cnt)printf("\n");
        printf("Case %d:\n",++cnt);
        t = f(0,0);
        printf("Minimum number of lectures: %d\n",t.x);
        printf("Total dissatisfaction index: %d\n",t.y);
    }
}
