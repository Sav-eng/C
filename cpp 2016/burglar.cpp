#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
int cx[] = {0,0,1,-1};
int cy[] = {1,-1,0,0};
int visit[1005][1005];
int tab[15][15];
int check,k;
int go[10000][15];
int a[1005][1005];
int mem2[10000][15];
struct node
{
    int x,y;
};
int n,m,l;
bool checkk(int x,int y)
{
    if(x>=0 &&x<n &&y>=0 &&y<m)return 1;
    else return 0;
}
int f(int x,int bit,int y)
{
    //printf("%d %d\n",y,l);
    if(y>l)return -inf;
    else if(x==check-1)return 0;
    else if(!go[bit][x])
    {
        int checkbit,i;
        for(i=1;i<check;i++)
        {
            //printf("a[%d][%d] = %d\n",x,i,a[x][i]);
            checkbit = (1<<i) & bit;
            if(!checkbit)
            {
                if(i!=1 && i!=check-1)mem2[bit][x] = max(mem2[bit][x],f(i,bit|(1<<i),y+1) + tab[x][i]);
                else mem2[bit][x] = max(mem2[bit][x],f(i,bit|(1<<i),y) + tab[x][i]);
                //printf("%d-->%d mem2[%d][%d] = %d\n",x,i,bit,x,mem2[bit][x]);
            }
        }
        go[bit][x] = 1;
        //printf("mem2[%d] = %d\n",bit,mem2[bit]);
    }
    return mem2[bit][x];

}
node s[15];
int coin[15][15];
int mem[1005][1005];
queue<node>q;
node t,t2;
int main()
{

    int i,j;
    for(i=0;i<15;i++)for(j=0;j<15;j++)tab[i][j] = -inf;
    scanf("%d%d%d%d",&n,&m,&k,&l);
    check = 2;
    coin[0][0]=1;

    s[1].x = 0;
    s[1].y = 0;

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]>=1)
            {
                s[check].x = i;
                s[check].y = j;
                //coin[j][i] = check;
                coin[i][j] = check++;
            }
        }
    }
    coin[n-1][n-1] =check;
    s[check].x = n-1;
    s[check++].y = n-1;
    //printf("check =%d\n",check);
    for(j=1;j<check;j++)
    {
        //printf("s[%d] = %d %d\n",j,s[j].x,s[j].y);
        memset(mem,0,sizeof(mem));
        memset(visit,0,sizeof(visit));
        q.push(s[j]);
        t2 = s[j];
        visit[s[j].x][s[j].y] = 1;
        while(!q.empty())
        {
            t = q.front();
            q.pop();
            for(i=0;i<4;i++)
            {
                if(!visit[t.x+cx[i]][t.y+cy[i]] && a[t.x+cx[i]][t.y+cy[i]]>=0 && checkk(t.x+cx[i],t.y+cy[i]))
                {
                    q.push({t.x+cx[i],t.y+cy[i]});
                    visit[t.x+cx[i]][t.y+cy[i]] = 1;
                    mem[t.x+cx[i]][t.y+cy[i]] = mem[t.x][t.y]-1;
                    //else mem[t.x+cx[i]][t.y+cy[i]] = mem[t.x][t.y]+a[t.x+cx[i]][t.y+cy[i]];
                    //printf("coin = %d ",coin[t.x+cx[i]][t.y+cy[i]]);
                    //printf("s[] = %d %d\n",s[j].x,s[j].y);
                    if(coin[t.x+cx[i]][t.y+cy[i]]>0)
                    {
                        //printf("coin[%d][%d] = %d  coin[%d][%d] = %d\n",t.x+cx[i],t.y+cy[i],coin[t.x+cx[i]][t.y+cy[i]],t2.x,t2.y,coin[t2.x][t2.y]);
                        tab[coin[t2.x][t2.y]][coin[t.x+cx[i]][t.y+cy[i]]] = mem[t.x+cx[i]][t.y+cy[i]]+a[t.x+cx[i]][t.y+cy[i]];
                        //tab[coin[t.x+cx[i]][t.y+cy[i]]][coin[t2.x][t2.y]] = mem[t.x+cx[i]][t.y+cy[i]]+a[t.x+cx[i]][t.y+cy[i]];
                    }
                }
                //printf("%d %d\n",t.x+cx[i],t.y+cy[i]);
            }

            //printf("a");
        }
    }
    /*for(i=1;i<check;i++)
    {
        for(j=1;j<check;j++)
        {
            printf("%2d ",tab[i][j]);
        }
        printf("\n");
    }*/

    for(i=0;i<(1<<check-1);i++)for(j=0;j<check;j++)mem2[i][j] = -inf;
    //printf("l = %d\n",l);
    printf("%d\n",max(0,f(1,2,0)));
    //for(i=0;i<1<<check;i++)printf("mem2[%d] = %d\n",i,mem2[i]);
}

/*
*/
