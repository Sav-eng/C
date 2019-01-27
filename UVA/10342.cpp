#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
int mem[101][101][2];
main()
{
    //freopen("out.txt","w",stdout);
    int n,m,p,i,j,k,a,b,val,T,time=0;
    while(scanf("%d%d",&n,&m) != EOF)
    {
        for(i=0;i<n;i++)for(j=0;j<n;j++)mem[i][j][0] = mem[i][j][1] = inf;
        for(i=0;i<n;i++)mem[i][i][0] = 0;
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&val);
            mem[a][b][0] = mem[b][a][0] = val;
        }
        //for(i=0;i<n;i++)for(j=0;j<n;j++)printf("mem[%d][%d] = %d\n",i,j,mem[i][j][0]);
        for(p=0;p<2;p++)
        {
            for(k=0;k<n;k++)
            {
                for(i=0;i<n;i++)
                {
                    for(j=0;j<n;j++)
                    {
                        if(mem[i][j][0] > mem[i][k][0]+mem[k][j][0])
                        {
                            mem[i][j][1] = mem[i][j][0];
                            mem[i][j][0] = mem[i][k][0]+mem[k][j][0];
                        }
                        else if(mem[i][j][0] < mem[i][k][0]+mem[k][j][0]) mem[i][j][1] = min(mem[i][j][1],mem[i][k][0]+mem[k][j][0]);
                        if(mem[i][j][0] < mem[i][k][0]+mem[k][j][1])mem[i][j][1] = min(mem[i][j][1],mem[i][k][0]+mem[k][j][1]);
                        if(mem[i][j][0] < mem[i][k][1]+mem[k][j][0])mem[i][j][1] = min(mem[i][j][1],mem[i][k][1]+mem[k][j][0]);
                    }
                }
            }
        }
        scanf("%d",&T);
        printf("Set #%d\n",++time);
        while(T--)
        {
            scanf("%d%d",&a,&b);
            if(mem[a][b][1]==inf)printf("?\n");
            else printf("%d\n",mem[a][b][1]);
        }
    }
}
