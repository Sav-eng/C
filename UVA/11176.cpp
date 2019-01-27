#include<bits/stdc++.h>
#define MAXN 500
using namespace std;
double mem[MAXN+1][MAXN+1];
double pp[MAXN+1];
main()
{
    int n,i,j;
    double p,ans;
    while(scanf("%d%lf",&n,&p)&&n)
    {
        memset(mem,0,sizeof(mem));
        pp[0]=1;
        for(i=1;i<=n;i++)
        {
            pp[i] = pp[i-1]*p;
            mem[0][i] = 1;
        }
        mem[0][0] = 1;
        for(i=1;i<=n;i++)
        {
            for(j=0;j<=n;j++)
            {
                mem[i][j] = mem[i-1][j];
                if(j+1==i)mem[i][j]-=pp[j+1];
                else if(j+1<i)mem[i][j] -= mem[i-j-2][j]*(1-p)*pp[j+1];
                //printf("%lf ",mem[i][j]);
            }
            //printf("\n");
        }
        ans =0;
        for(i=1;i<=n;i++)
        {
            ans += (mem[n][i]-mem[n][i-1])*i;
        }
        printf("%lf\n",ans);
    }
}
