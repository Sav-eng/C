#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
int mem[105][105];
int a[105][105];
bool check;
int n,m;
int f(int x,int y)
{
    int i,t;
    if(x==n)return 0;
    else
    {
        if(!mem[x][y])
        {
            mem[x][y] = -inf;
            //choose[x][y] = -1;
            for(i=0;i<y;i++)
            {
                if(a[x][i]<5)continue;
                mem[x][y] = max(mem[x][y],f(x+1,y-i-1)+a[x][i]);
            }
            //mem[x][y] = max(mem[x][y],t);
            //mprintf("mem[%d][%d] = %d\n",x,y,mem[x][y]);
        }
        return mem[x][y];
    }
}
main()
{
    //freopen("out.txt","w",stdout);
    int time,i,j;
    double ans;
    scanf("%d",&time);
    while(time--)
    {
        memset(mem,0,sizeof(mem));
        check=1;
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        ans = (double)f(0,m)*1.0/n;
        //printf("%.2lf\n",ans);
        if(ans>=0)printf("Maximal possible average mark - %.2lf.\n",ans+1e-9);
        else printf("Peter, you shouldn't have played billiard that much.\n");
    }
}
