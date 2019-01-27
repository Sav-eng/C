#include<bits/stdc++.h>
using namespace std;
struct node
{
    double x;
    long long y;
};
node mem[1001][1001];
double p,q;
int check;
node f(int x,int y)
{
    //printf("mem[%d][%d] = %lf\n",x,y,mem[x][y]);
    if(x==0)
    {
        node t;
        t.x =1;
        t.y = 1;
        return t;
    }
    else if(y==0)
    {
        node t;
        t.x = 0;
        t.y = 1;
        return t;
    }
    else if(mem[x][y].y ==0 && mem[x][y].x==0)
    {
        node t,t2;
        t = f(x-1,y);
        t2 = f(x,y-1);
        mem[x][y].x = (double)p*t.x + (double)q*t2.x;
        mem[x][y].y = t.y+t2.y+1;
    }
    //printf("mem[%d][%d] = %lf %d\n",x,y,mem[x][y].x,mem[x][y].y);
    return mem[x][y];
}
main()
{
    int time,a,b;
    double n;
    while(scanf("%lf%d",&n,&time) && time)
    {
        int i,j;
        for(i=0;i<=1000;i++)for(j=0;j<=1000;j++)mem[i][j].x = 0,mem[i][j].y = 0;
        p = n;
        q = 1-p;
        //printf("%lf %lf",p,q);
        f(1000,1000);
        while(time--)
        {
            scanf("%d%d",&a,&b);
            check =0;
            if(!a && !b)printf("-1.00000\n0\n");
            else if(!a)printf("1.00000\n0\n");
            else if(!b)printf("0.00000\n0\n");
            else printf("%.5lf\n%lld\n",mem[a][b].x,mem[a][b].y-1);

        }
    }
}
/*
0.5 3
1 1
2 2
3 3



*/
