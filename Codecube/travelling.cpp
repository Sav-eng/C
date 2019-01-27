#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
set<int>myset;
int from[205][205];
int mem[20][40005];
int k,n;
int tras[205];
int f(int x,int check)
{
    if(x==k-1 && check == (1<<k)-1)
    {
        //printf("a");
        return 0;
    }
    else if(x==k-1 && check!=(1<<k)-1)
    {
        //printf("b");
        //printf("mem[%d][%d] = %d\n",x,check,mem[x][check]);
        return inf;
    }
    else if(mem[x][check]== inf)
    {
        //printf("a");
        int i;
        for(i=0;i<k;i++)
        {
            if(((1<<i) & check) ==0)
            {
                //printf("%d-->%d = %d\n",tras[x],tras[i],from[tras[x]][tras[i]]);
                mem[x][check] = min(mem[x][check],f(i,check|(1<<i))+from[tras[x]][tras[i]]);
            }
        }
    }
    //printf("mem[%d][%d] = %d %d\n",x,check,mem[x][check],(1<<k)-1);
    return mem[x][check];
}
main()
{
    int m,i,j,a,b,c,_k;
    bool check=0;
    scanf("%d%d%d",&n,&m,&k);
    tras[0] = 1;
    for(i=1;i<=k;i++)
    {
        scanf("%d",&a);
        tras[i] = a;
    }
    tras[k+1]=n;
    k+=2;
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)from[i][j] = inf;
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        from[a][b] = c;
        from[b][a] = c;
    }
    for(_k=1;_k<=n;_k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                from[i][j] = min(from[i][j],from[i][_k]+from[_k][j]);
            }
        }
    }
    /*for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%d ",from[i][j]);
        }
        printf("\n");
    }*/
    for(i=0;i<k;i++)for(j=0;j<(1<<k);j++)mem[i][j] = inf;
    printf("%d",f(0,1));
}
/*

7 9 1
4
1 2 1
1 3 2
4 1 2
2 4 2
3 4 1
4 5 1
4 6 3
5 7 1
7 6 2





*/
