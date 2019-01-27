#include<bits/stdc++.h>
using namespace std;
int mem[2][501][501];
main()
{
    int n,m,K,mod,i,j,k,a;
    bool flag = 1;
    scanf("%d%d%d%d",&n,&m,&K,&mod);
    mem[0][0][0]=1;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        for(j=0;j<=m;j++)
        {
            for(k=0;k<=K;k++)
            {
                mem[flag][j][k] = mem[!flag][j][k];
                if(k-a>=0)
                {
                    mem[flag][j][k] = (mem[flag][j][k]+mem[flag][j-1][k-a]+mod)%mod;
                }
                //printf("mem[%d][%d][%d] = %d\n",i,j,k,mem[flag][j][k]);
                //printf("%d\n",k-a);

            }
        }
        flag = !flag;
    }
    int ans = 0;
    flag = !flag;
    for(i=0;i<=K;i++)
    {
        ans = (ans+mem[flag][m][i]+mod)%mod;
    }
    printf("%d",ans);
}
