#include<bits/stdc++.h>
using namespace std;
int n,m;
int mem[101];
int vis[101];
int tab[101][101];
bool check;
void dfs(int x,int now)
{
    int i;
    if(now==m)
    {
        check=1;
        printf("(1");
        for(i=0;i<now;i++)printf(",%d",mem[i]);
        printf(")\n");
    }
    else
    {
        for(i=1;i<=n;i++)
        {
            //printf("tab[%d][%d] = %d\n",x,i,tab[x][i]);
            if(!vis[i] && tab[x][i]==1)
            {
                vis[i] = 1;
                mem[now] = i;
                dfs(i,now+1);
                vis[i] = 0;
            }
        }
    }
}
main()
{
    //freopen("out.txt","w",stdout);
    int i,j,x,time=0;
    do
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf("%d",&tab[i][j]);
            }
        }
        check=0;
        vis[1]=1;
        if(time++)printf("\n");
        dfs(1,0);//index on now,row,colum
        vis[1]=0;
        if(!check)printf("no walk of length %d\n",m);
    }while(scanf("%d",&x)!= EOF);
}
