#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long mem[1001][5][10];
int n,k1,k2,k3;
vector<int>from[5];
long long f(int x,int y,int z)
{
    if(x==n && z==7)return 1;
    else if(x==n && z!=7)return 0;
    else if(!mem[x][y][z])
    {
        int i,j;
        for(i=0;i<from[y].size();i++)
        {
            if(from[y][i]==1)
            {
                for(j=1;j<=k1;j++)
                {
                    if(x+j<=n)mem[x][y][z]  =  (mem[x][y][z]+f(x+j,from[y][i],z|1))%mod;
                }
            }
            else if(from[y][i]==2)
            {
                for(j=1;j<=k2;j++)
                {
                    if(x+j<=n)mem[x][y][z] = (mem[x][y][z]+f(x+j,from[y][i],z|2))%mod;
                }
            }
            else
            {
                for(j=1;j<=k3;j++)
                {
                    if(x+j<=n)mem[x][y][z] = (mem[x][y][z]+f(x+j,from[y][i],z|4))%mod;
                }
            }
        }
    }
    //printf("mem[%d][%d][%d] = %d\n",x,y,z,mem[x][y][z]);
    return mem[x][y][z];
}
long long ans;
main()
{
    int i;
    scanf("%d%d%d%d",&n,&k1,&k2,&k3);
    from[1].push_back(2); from[1].push_back(3);
    from[2].push_back(3); from[3].push_back(1);
    for(i=1;i<=k1;i++)
    {
        ans = (ans +f(i,1,1))%mod;
    }
    printf("%lld",ans);
}
/*

10 2 2 2
611





*/
