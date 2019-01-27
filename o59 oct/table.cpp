#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
int tab[305][5005];
int mem[305];
main()
{
    int n,m,time,i,a,x,y,val,j,ans,t;
    scanf("%d%d%d",&n,&m,&time);
    while(time--)
    {
        scanf("%d",&a);
        //printf("a = %d\n",a);
        if(a==1)
        {
            scanf("%d%d%d",&x,&y,&val);
            tab[x][y] = val;
            t = inf;
            for(i=1;i<=m;i++)t = min(t,tab[x][i]);
            mem[x] = t;
        }
        else if(a==2)
        {
            scanf("%d%d",&x,&val);
            for(i=1;i<=m;i++)
            {
                tab[x][i] = val;
            }
            mem[x] = val;
        }
        else if(a==3)
        {
            scanf("%d%d",&x,&y);
            printf("%d\n",tab[x][y]);
        }
        else
        {
            ans = inf;
            for(i=1;i<=n;i++)ans = min(ans,mem[i]);
            printf("%d\n",ans);
        }
    }
    /*for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            printf("%d ",tab[i][j]);
        }
        printf("\n");
    }*/
}
/*
3 3 20
3 1 2 4
2 1 100
2 2 10
2 3 40 4
1 2 1 50
1 2 3 200 4
1 3 3 25
3 3 2 4
1 2 2 60 4
2 1 40
2 2 20
2 3 100
4




*/
