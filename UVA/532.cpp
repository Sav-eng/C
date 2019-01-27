#include<stdio.h>
#include<queue>
#include<string.h>
#define inf 1e9
using namespace std;
struct node
{
    int x,y,z;
    node(int _x = 0,int _y = 0,int _z = 0)
    {
        x = _x;
        y = _y;
        z = _z;
    }
};
queue<node>q;
int mem[50][50][50];
char a[50][50][50];
node start,en,t;
int cx[10] = {0,0,0,0,1,-1};
int cy[10] ={0,0,1,-1,0,0};
int cz[10] = {1,-1,0,0,0,0};
main()
{
    int n,m,o,i,j,k;
    while(1)
    {
        memset(a,' ',sizeof(a));
        scanf("%d%d%d",&n,&m,&o);
        if(n==0 && m==0 && o==0)break;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                for(k=0;k<o;k++)
                {
                    scanf(" %c",&a[i][j][k]);
                    if(a[i][j][k]=='S')
                    {
                        start.x = i;
                        start.y = j;
                        start.z = k;
                    }
                    if(a[i][j][k]=='E')
                    {
                        en.x = i;
                        en.y = j;
                        en.z = k;
                    }
                    //mem[i][j][k] = inf;
                }
            }
        }
        for(i=0;i<30;i++)for(j=0;j<30;j++)for(k=0;k<30;k++)mem[i][j][k] = inf;
        mem[start.x][start.y][start.z] = 0;
        q.push(node(start.x,start.y,start.z));
        while(!q.empty())
        {
            t = q.front();
            q.pop();
            for(i=0;i<6;i++)
            {
                if(a[t.x+cx[i]][t.y+cy[i]][t.z+cz[i]]=='.' || a[t.x+cx[i]][t.y+cy[i]][t.z+cz[i]]=='E')
                {
                    if(mem[t.x+cx[i]][t.y+cy[i]][t.z+cz[i]] > mem[t.x][t.y][t.z]+1)
                    {
                        mem[t.x+cx[i]][t.y+cy[i]][t.z+cz[i]] = mem[t.x][t.y][t.z]+1;
                        q.push(node(t.x+cx[i],t.y+cy[i],t.z+cz[i]));
                    }
                }
            }
        }
        if(mem[en.x][en.y][en.z]==inf)printf("Trapped!\n");
        else printf("Escaped in %d minute(s).\n",mem[en.x][en.y][en.z]);
    }
}
