#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,y;
};
int cx[] = {0,1};
int cy[] = {1,0};
long long mem[51][51];
int tab[51][51];
int vis[51][51];
queue<node>q;
main()
{
    int i,j,k,n,m,a,b;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            tab[i][j] = 1;
        }
    }
    for(i=0;i<k;i++)
    {
        scanf("%d%d",&a,&b);
        tab[a-1][b-1] = 0;
    }
    q.push({0,0});
    mem[0][0]=1;
    node t;
    while(!q.empty())
    {
        t = q.front(); q.pop();
        if(!vis[t.x][t.y])
        {
            vis[t.x][t.y]=1;
            for(i=0;i<2;i++)
            {
                if(tab[t.x+cx[i]][t.y+cy[i]])
                {
                    mem[t.x+cx[i]][t.y+cy[i]] += mem[t.x][t.y];
                    q.push({t.x+cx[i],t.y+cy[i]});
                }
            }
        }

        //printf("mem[%d][%d] = %d\n",t.x,t.y,mem[t.x][t.y]);
    }
    /*for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d ",mem[i][j]);
        }
        printf("\n");
    }*/
    printf("%lld",mem[n-1][m-1]);
}


