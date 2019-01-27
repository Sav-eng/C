#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
int tab[101][101];
main()
{
    int n,m,T,i,j,a,b,val,k,time=0;;
    while(scanf("%d%d%d",&n,&m,&T)&&n)
    {
        for(i=1;i<=n;i++)for(j=1;j<=n;j++)tab[i][j] = inf;
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&val);
            tab[a][b] = val;
            tab[b][a] = val;
        }
        for(k=1;k<=n;k++)
        {
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=n;j++)
                {
                    tab[i][j] = tab[j][i] = min(tab[i][j],max(tab[i][k],tab[k][j]));
                }
            }
        }
        if(time)printf("\n");
        printf("Case #%d\n",++time);
        while(T--)
        {
            scanf("%d%d",&a,&b);
            if(tab[a][b]==inf)printf("no path\n");
            else printf("%d\n",tab[a][b]);
        }
    }
}
