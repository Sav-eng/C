#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
struct node
{
    int x,y,val,use;
    bool operator <(node a)const
    {
        return a.val<val;
    }
};
priority_queue<node>heap;
int cx[]={1,-1,0,0};
int cy[]={0,0,1,-1};
pair<int,int>hole[25][25];
int mem[25][25][25];
int tab[25][25];
int check[25][25];
main()
{
    int i,j,n,m,k,a,b,c,d,_i;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&tab[i][j]);
            for(_i=0;_i<=m;_i++)mem[i][j][_i]=inf;
        }
    }
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        hole[a][b] = make_pair(c,d);
        check[a][b]=1;
    }
    heap.push({0,0,0,0});
    while(!heap.empty())
    {
        node t = heap.top(); heap.pop();
        if(t.x==n-1 && t.y == n-1)
        {
            printf("%d",mem[t.x][t.y][t.use]);
            return 0;
        }
        for(i=0;i<4;i++)
        {
            int vx = t.x+cx[i];
            int vy = t.y+cy[i];
            if(vx>=0 && vx<n && vy>=0 && vy<n)
            {
                if(mem[vx][vy][t.use]>t.val+tab[vx][vy])
                {
                    mem[vx][vy][t.use] = t.val+tab[vx][vy];
                    heap.push({vx,vy,mem[vx][vy][t.use],t.use});
                }
                if(check[vx][vy])
                {
                    int X = hole[vx][vy].first;
                    int Y = hole[vx][vy].second;
                    if(mem[X][Y][t.use+1]>t.val+tab[vx][vy] && t.use+1 <=k)
                    {
                        //printf("go %d %d\n",X,Y);
                        mem[X][Y][t.use+1] = t.val+tab[vx][vy];
                        heap.push({X,Y,mem[X][Y][t.use+1],t.use+1});
                    }
                }
            }
        }
        //printf("mem[%d][%d][%d] = %d\n",t.x,t.y,t.use,t.val);
    }
}
