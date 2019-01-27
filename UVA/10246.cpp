#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
int tab[101][101];
int mem[101][101];
int x[101];
main()
{
    //freopen("out.txt","w",stdout);
    int n,m,T,i,j,k,a,b,val,time=0,p;
    while(scanf("%d%d%d",&n,&m,&T)&&n)
    {
        for(i=1;i<=n;i++)for(j=1;j<=n;j++)mem[i][j] = inf;
        memset(tab,0,sizeof(tab));
        for(i=1;i<=n;i++)scanf("%d",&tab[i][i]);
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&val);
            tab[a][b] = max(tab[a][a],tab[b][b]);
            tab[b][a] = max(tab[a][a],tab[b][b]);
            mem[a][b] = min(mem[a][b],val);
            mem[b][a] = min(mem[b][a],val);
        }
        for(p=0;p<2;p++)
        {
            for(k=1;k<=n;k++)
            {
                for(i=1;i<=n;i++)
                {
                    for(j=1;j<=n;j++)
                    {
                        if(mem[i][j]+tab[i][j]>mem[i][k]+mem[k][j]+max(tab[i][k],tab[k][j]))
                        {
                            mem[i][j] = mem[i][k]+mem[k][j];
                            tab[i][j] = max(tab[i][k],tab[k][j]);
                        }
                    }
                }
            }
        }
        if(time)printf("\n");
        printf("Case #%d\n",++time);
        while(T--)
        {
            scanf("%d%d",&a,&b);
            if(mem[a][b] != inf)printf("%d\n",mem[a][b]+tab[a][b]);
            else printf("-1\n");
        }
        //printf("\n");
    }
}
