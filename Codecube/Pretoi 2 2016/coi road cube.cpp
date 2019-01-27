#include<stdio.h>
#include<algorithm>
using namespace std;
int n,m,k;
int tab[105][10005];
int taba[105][10005];
int f(int x,int y)
{
    if(taba[x][y]!=0)return taba[x][y];
    int temp=0;
    int i;
    if(x<0 || y<0 || x>=n || y >=m)return 0;
    for(i=1;i<=k;i++)
    {
        temp = max(f(x+1,y-i),f(x+1,y+i));
    }
    temp = max(temp,f(x+1,y))+tab[x][y];
    return taba[x][y] = temp;
}
main()
{
    int i,j,ans;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&tab[i][j]);
        }
    }
    ans = 0;
    for(i=0;i<m;i++)
    {

        ans = max(ans,f(0,i)); //printf("%d ",ans);
    }
    printf("%d",ans);
}
