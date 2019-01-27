#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
struct node
{
    int x,y,val,direc;
    bool operator <(node a)const
    {
        return a.val < val;
    }
};
int n,m;
bool check(int x,int y)
{
    return (x>=1 && x<=n && y>=1 && y<=m) || (x==1 && y==m+1);
}
int cx[] = {-1,0,1,0};
int cy[] = {0,1,0,-1};
priority_queue<node>heap;
int mem[102][102][5];
char tab[102][102];
main()
{
    int a,b,c,i,j,k;
    scanf("%d%d%d",&a,&b,&c);
    scanf("%d%d",&m,&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            scanf(" %c",&tab[i][j]);
            for(k=0;k<4;k++)mem[i][j][k] = inf;
        }
    }
    tab[1][m+1] = '.';

    if(tab[n][1]=='.')
    {
        heap.push({n,0,0,1});
        mem[n][0][1] = 0;
    }
    else
    {
    heap.push({n,0,c,1});
        mem[n][0][1] = c;
    }
    //printf("mem1 = %d\n",mem[n][0][1]);
    node t;
    while(!heap.empty())
    {
        t = heap.top(); heap.pop();
        for(i=0;i<4;i++)
        {
            if(check(t.x+cx[i]+cx[t.direc],t.y+cy[i]+cy[t.direc]))
            {
                if(t.direc==i)
                {
                    if(tab[t.x+cx[t.direc]+cx[i]][t.y+cy[t.direc]+cy[i]]=='X' && mem[t.x+cx[t.direc]][t.y+cy[t.direc]][i] > t.val+c+a)
                    {
                        mem[t.x+cx[t.direc]][t.y+cy[t.direc]][i] = t.val+c+a;
                        //printf("%d %d %d ---> %d %d %d useA %d\n",t.x,t.y,t.direc,t.x+cx[t.direc],t.y+cy[t.direc],i,t.val+c+a);
                        heap.push({t.x+cx[t.direc],t.y+cy[t.direc],mem[t.x+cx[t.direc]][t.y+cy[t.direc]][i],i});
                    }
                    else if(tab[t.x+cx[t.direc]+cx[i]][t.y+cy[t.direc]+cy[i]]=='.' && mem[t.x+cx[t.direc]][t.y+cy[t.direc]][i] > t.val+a)
                    {
                        mem[t.x+cx[t.direc]][t.y+cy[t.direc]][i] = t.val+a;
                        heap.push({t.x+cx[t.direc],t.y+cy[t.direc],mem[t.x+cx[t.direc]][t.y+cy[t.direc]][i],i});
                        //printf("%d %d %d ---> %d %d %d useB %d\n",t.x,t.y,t.direc,t.x+cx[t.direc],t.y+cy[t.direc],i,t.val+a);
                    }
                }
                else if(t.direc != (i+2)%4)
                {
                    if(tab[t.x+cx[t.direc]+cx[i]][t.y+cy[t.direc]+cy[i]]=='X' && mem[t.x+cx[t.direc]][t.y+cy[t.direc]][i] > t.val+c+b)
                    {
                        mem[t.x+cx[t.direc]][t.y+cy[t.direc]][i] = t.val+c+b;
                        heap.push({t.x+cx[t.direc],t.y+cy[t.direc],mem[t.x+cx[t.direc]][t.y+cy[t.direc]][i],i});
                        //printf("%d %d %d ---> %d %d %d useC %d\n",t.x,t.y,t.direc,t.x+cx[t.direc],t.y+cy[t.direc],i,t.val+c+b);
                    }
                    else if(tab[t.x+cx[t.direc]+cx[i]][t.y+cy[t.direc]+cy[i]]=='.' && mem[t.x+cx[t.direc]][t.y+cy[t.direc]][i] > t.val+b)
                    {
                        mem[t.x+cx[t.direc]][t.y+cy[t.direc]][i] = t.val+b;
                        heap.push({t.x+cx[t.direc],t.y+cy[t.direc],mem[t.x+cx[t.direc]][t.y+cy[t.direc]][i],i});
                        //printf("%d %d %d ---> %d %d %d useD %d\n",t.x,t.y,t.direc,t.x+cx[t.direc],t.y+cy[t.direc],i,t.val+b);
                    }
                }

            }
        }
        //printf("mem[%d][%d][%d] = %d\n",t.x,t.y,t.direc,t.val);
    }
    printf("%d",mem[1][m][1]);

}
