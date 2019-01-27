#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
struct node
{
    int x,y,direc,val;
    bool operator <(node a)const
    {
        return a.val<val;
    }
};
int n,m;
char a[305][305];
int check(int x,int y)
{
    if(x<n && y<m && x>=0 && y>=0 && (a[x][y] == '.' || a[x][y] == 'X'))return 1;
    return 0;
}
priority_queue<node>heap;
int mymap[305][305];
int mem[305][305][10];
int cx[] = {-1,-1,0,1,1,1,0,-1};
int cy[] = {0,1,1,1,0,-1,-1,-1};

queue<node>q;
node s;
node e[1005];
int ans[1005];
main()
{
    int k,i,j,ii;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf(" %c",&a[i][j]);
            if(a[i][j] == 'J')
            {
                s.x = i;
                s.y = j;
            }
        }
    }
    for(i=1;i<=k;i++)
    {
        scanf("%d%d",&e[i].x,&e[i].y);
        e[i].x--; e[i].y--;
        mymap[e[i].x][e[i].y]=i;
        ans[i] = inf;
    }
    s.direc = 0;
    s.val = 0;
    for(i=0;i<n;i++)for(j=0;j<m;j++)for(ii=0;ii<8;ii++)mem[i][j][ii] = inf;
    node t;
    for(i=0;i<8;i++)mem[s.x][s.y][i]=0;
    heap.push(s);
    while(!heap.empty())
    {
        t = heap.top(); heap.pop();
        //printf("mem[%d][%d][%d] = %d %d\n",t.x,t.y,t.direc,mem[t.x][t.y][t.direc],mymap[t.x][t.y]);
        if(mymap[t.x][t.y]!=0)
        {
            ans[mymap[t.x][t.y]] = min(ans[mymap[t.x][t.y]],t.val);
            //printf("ans[%d] = %d\n",mymap[t.x][t.y],ans[mymap[t.x][t.y]]);
        }
        if(t.x == s.x && t.y == s.y)
        {
            for(i=0;i<8;i++)
            {
                if(check(t.x+cx[i],t.y+cy[i]))
                {
                    mem[t.x+cx[i]][t.y+cy[i]][i] = t.val;
                    heap.push({t.x+cx[i],t.y+cy[i],i,t.val});
                }
            }
        }
        else
        {
            for(i=0;i<4;i++)
            {
                if(i==0)
                {
                    if(check(t.x+cx[t.direc],t.y+cy[t.direc])&&(mem[t.x+cx[t.direc]][t.y+cy[t.direc]][t.direc]> t.val))
                    {
                        mem[t.x+cx[t.direc]][t.y+cy[t.direc]][t.direc] =  t.val;
                        heap.push({t.x+cx[t.direc],t.y+cy[t.direc],t.direc,t.val});
                    }
                }
                else
                {
                    //printf("a ");
                    if(check(t.x+cx[(t.direc+(i*2))%8],t.y+cy[(t.direc+(i*2))%8])&&(mem[t.x+cx[(t.direc+(i*2))%8]][t.y+cy[(t.direc+(i*2))%8]][(t.direc+(i*2))%8]> t.val+1)&&i!=2)
                    {
                        //printf("mem[%d][%d][%d] = %d\n",t.x+cx[(t.direc+(i*2))%8],t.y+cy[(t.direc+(i*2))%8],(t.direc+(i*2))%8,mem[t.x+cx[(t.direc+(i*2))%8]][t.y+cy[(t.direc+(i*2))%8]][(t.direc+(i*2))%8]);
                        mem[t.x+cx[(t.direc+(i*2))%8]][t.y+cy[(t.direc+(i*2))%8]][(t.direc+(i*2))%8] = t.val+1;
                        heap.push({t.x+cx[(t.direc+(i*2))%8],t.y+cy[(t.direc+(i*2))%8],(t.direc+(i*2))%8,t.val+1});
                    }
                }
            }
        }
    }
    for(i=1;i<=k;i++)
    {
        if(ans[i]==inf)printf("-1\n");
        else printf("%d\n",ans[i]);
    }
}
/*

4 10 2
..........
##########
...X..#..J
..X....#.#
3 4
4 3




*/
