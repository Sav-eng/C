#include<stdio.h>
#include<queue>
#include<string.h>
#include<algorithm>
using namespace std;
struct node
{
    int x,y;
    node(int _x = 0,int _y = 0)
    {
        x = _x;
        y = _y;
    }
};
queue<node>q;
int tab[500][500];
int mem[500][500];
int check[500][500];
int cx[5] = {0,0,1,-1};
int cy[5] = {1,-1,0,0};
node t;
main()
{
    //FILE *fp = fopen("10259.txt","w");
    int time,i,j,n,k,_max=0;
    scanf("%d",&time);
    while(time--)
    {
        //if(time)
        memset(mem,0,sizeof(mem));
        memset(tab,0,sizeof(tab));
        scanf("%d%d",&n,&k);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&tab[i][j]);
            }
        }
        q.push(node(0,0));
        //check[0][0] = 1;
        mem[0][0] = tab[0][0];
        _max = tab[0][0];
        while(!q.empty())
        {
            t = q.front();
            q.pop();
            for(i=0;i<4;i++)
            {
                for(j=1;j<=k;j++)
                {
                    if(tab[t.x+(cx[i]*j)][t.y+(cy[i]*j)] > tab[t.x][t.y] && t.x+cx[i]*j >=0 && t.y+cy[i]*j >= 0 && t.x+cx[i]*j < n && t.y+cy[i]*j < n)
                    {
                        if(mem[t.x+cx[i]*j][t.y+cy[i]*j] < mem[t.x][t.y] + tab[t.x+cx[i]*j][t.y+cy[i]*j])
                        {
                            mem[t.x+cx[i]*j][t.y+cy[i]*j] = mem[t.x][t.y] + tab[t.x+cx[i]*j][t.y+cy[i]*j];
                            _max = max(_max,mem[t.x+cx[i]*j][t.y+cy[i]*j]);
                            q.push(node(t.x+cx[i]*j,t.y+cy[i]*j));
                            //check[t.x+cx[i]*j][t.y+cy[i]*j] = 1;
                        }
                    }
                }
            }
        }
        /*for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                printf("%d ",mem[i][j]);
            }
            printf("\n");
        }*/
        if(time==1)printf("%d\n",_max);
        else printf("%d\n\n",_max);
    }
}
