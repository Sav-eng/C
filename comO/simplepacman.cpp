#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e3+1;
int mem[MAXN][MAXN][3];
main()
{
    int n,m,i,j,a,ans=0,k;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&a);
            for(k=0;k<3;k++)
            {
                if(k==1)mem[i][j][k] = a;
                if(i>0)
                {
                    if(k-1>=0)mem[i][j][k] = max(mem[i][j][k],mem[i-1][j][k-1]+a);
                    mem[i][j][0] = max(mem[i][j][0],mem[i-1][j][k]);
                }
                if(j>0)
                {
                    if(k-1>=0)mem[i][j][k] = max(mem[i][j][k],mem[i][j-1][k-1]+a);
                    mem[i][j][0] = max(mem[i][j][0],mem[i][j-1][k]);
                }
                if(i==n-1 && j==m-1)ans = max(ans,mem[i][j][k]);
            }
            for(k=0;k<3;k++)
            {

                //printf("mem[%d][%d][%d] = %d\n",i,j,k,mem[i][j][k]);
            }

        }
    }
    printf("%d",ans);
}
