#include<bits/stdc++.h>
using namespace std;
int mem[35][35][35][35];
int tab[35][35];
int prep[35][35][35];
int prep2[35][35][35];
int have[1001];
int cnt[1001][35][35];
int f(int a,int b,int x,int y)
{
    if(a==b|| x==y)
    {
        if(x==y)
        {
            return prep[a][b][x];
        }
        else
        {
            return prep2[x][y][a];
        }
    }
    else if(mem[a][b][x][y]==-1)
    {
        mem[a][b][x][y] = 0;
        mem[a][b][x][y] = max(mem[a][b][x][y],f(a+1,b,x,y)+prep2[x][y][a]);
        mem[a][b][x][y] = max(mem[a][b][x][y],f(a,b-1,x,y)+prep2[x][y][b]);
        mem[a][b][x][y] = max(mem[a][b][x][y],f(a,b,x+1,y)+prep[a][b][x]);
        mem[a][b][x][y] = max(mem[a][b][x][y],f(a,b,x,y-1)+prep[a][b][y]);
        //printf("mem[%d][%d][%d][%d] = %d\n",a,b,x,y,mem[a][b][x][y]);
    }
    return mem[a][b][x][y];
}
main()
{
    int n,m,k,i,j,_i,_j,K;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&tab[i][j]);
            have[tab[i][j]]++;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            for(_i=i;_i<n;_i++)
            {
                cnt[tab[_i][j]][i][j]++;
                prep[i][_i][j] = prep[i][_i-1][j];
                if(cnt[tab[_i][j]][i][j]==have[tab[_i][j]])prep[i][_i][j]++;
                //printf("prep[%d][%d][%d] = %d\n",i,_i,j,prep[i][_i][j]);
            }
        }
    }
    for(K=1;K<=k;K++)for(i=0;i<n;i++)for(j=0;j<m;j++)cnt[K][i][j]=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            for(_j=j;_j<m;_j++)
            {
                cnt[tab[i][_j]][i][j]++;
                prep2[j][_j][i] = prep2[j][_j-1][i];
                if(cnt[tab[i][_j]][i][j]==have[tab[i][_j]])prep2[j][_j][i]++;
                //printf("prep2[%d][%d][%d] = %d\n",j,_j,i,prep2[j][_j][i]);
            }
        }
    }
    memset(mem,-1,sizeof(mem));
    //printf("GO ON DP\n");
    printf("%d",f(0,n-1,0,m-1));
}
/*

4 6 11
1 6 5 8 9 10
1 7 5 7 11 11
1 2 5 7 4 4
2 6 3 3 3 3



*/
