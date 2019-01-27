#include<bits/stdc++.h>
using namespace std;
#define inf 100000
map<int,map<int,int> > mem;
map<int,map<int,int> > track;
int f(int x,int y)
{
    int i,t;
    if(x <0 || y<0 || y>x*x) return inf;
    if(x==0 && y==0) return 0;
    if(!mem[x][y])
    {
        mem[x][y] = inf;
        for(i=1;i<=9;i++)
        {
            t = f(x-i,y-i*i) + 1;
            if(mem[x][y]>t)
            {
                mem[x][y] = t;
                track[x][y] = i;
            }
        }
    }
    return mem[x][y];
}
void g(int x,int y)
{
    if(x==0 && y==0) return ;
    int t = track[x][y];
    printf("%d",t);
    g(x-t,y-t*t);
}
main()
{
    int time,x,y;
    scanf("%d",&time);
    while(time--)
    {
        scanf("%d%d",&x,&y);
        if(f(x,y)==inf) printf("No solution");
        else g(x,y);
        printf("\n");
    }
}
