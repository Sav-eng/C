#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,y,val;
};
bool cmp(node x,node y)
{
    return x.x<y.x;
}
int mem[1001][1001];
node tab[1001];
int n;
int start[1001];
int f(int x,int y)
{
    if(x>n || y>n)return 0;
    else if(!mem[x][y])
    {
        if(x<=y)mem[x][y] = max(mem[x][y],f(x+1,y));
        if(y<=x)mem[x][y] = max(mem[x][y],f(x,y+1));
        if(x<y)mem[x][y] = max(mem[x][y],f(start[x],y)+tab[x].val);
        if(y<x)mem[x][y] = max(mem[x][y],f(x,start[y])+tab[y].val);
        //printf("mem[%d][%d] = %d\n",x,y,mem[x][y]);
    }
    return mem[x][y];
}
main()
{
    int i,l,r,mid;
    scanf("%d",&n);
    //memset(mem,-1,sizeof(mem));
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&tab[i].x,&tab[i].y,&tab[i].val);
        //m = max(m,tab[i].y);
    }
    sort(&tab[0],&tab[n],cmp);
    int t;
    for(i=0;i<n;i++)
    {
        l = 0,r = n-1,t=n;
        while(l<=r)
        {
            mid = (l+r)/2;
            if(tab[i].y<=tab[mid].x)
            {
                t = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        start[i] = t;
        //printf("start[%d] = %d\n",i,t);
    }
    start[n] = n+1;
    printf("%d",f(0,1));
}
