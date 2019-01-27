#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
int n,m,a[15][105];
int mem[15][105];
int trac[15][105];
int f(int x,int y)
{
    if(y==m)return 0;
    else if(!mem[x][y])
    {
        mem[x][y] = inf;
        if(x==0)
        {
            mem[x][y] = min(f(x,y+1),min(f(x+1,y+1),f(n-1,y+1)))+a[x][y];
            if(mem[x][y] == f(x,y+1)+a[x][y])trac[x][y] = x;
            else if(mem[x][y] == f(x+1,y+1)+a[x][y])trac[x][y] = x+1;
            else trac[x][y] = n-1;
        }
        else if(x==n-1)
        {
            mem[x][y] = min(f(x,y+1),min(f(0,y+1),f(x-1,y+1)))+a[x][y];
            if(mem[x][y] == f(0,y+1)+a[x][y])trac[x][y] = 0;
            else if(mem[x][y] == f(x-1,y+1)+a[x][y])trac[x][y] = x-1;
            else trac[x][y] = x;
        }
        else
        {
            mem[x][y] = min(f(x,y+1),min(f(x+1,y+1),f(x-1,y+1)))+a[x][y];
            if(mem[x][y] == f(x-1,y+1)+a[x][y])trac[x][y] = x-1;
            else if(mem[x][y] == f(x,y+1)+a[x][y])trac[x][y] = x;
            else trac[x][y] = x+1;
        }
    }
    return mem[x][y];
}
main()
{
    //freopen("out.txt","w",stdout);
    int i,j,ans,t;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(mem,0,sizeof(mem));
        memset(trac,0,sizeof(trac));
        memset(a,0,sizeof(a));
        ans = inf;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for(i=0;i<n;i++)
        {
            if(ans>f(i,0))
            {
                ans = f(i,0);
                t = i;
            }
        }
        /*printf("---------------------------\n");
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                printf("%d ",trac[i][j]);
            }
            printf("\n");
        }
        printf("-------------------------------\n");
        printf("t = %d\n",t);*/
        for(i=0;i<m;i++)
        {
            if(i!=m-1)printf("%d ",t+1);
            else printf("%d",t+1);
            t = trac[t][i];
        }
        printf("\n%d\n",ans);

    }
}
