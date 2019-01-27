#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
int cx[]={0,0,-1,1,1,1,-1,-1};
int cy[]={1,-1,0,0,1,-1,1,-1};
int f(int x,int y)
{
    if(x==n*m)return 0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(visit[i][j] == 0)
            {
                mp = y + a[i][j] +f(x+1,y+(10*(a[i][j]+y)));
            }
            vis
        }
    }
}
main()
{
    int m,n;
    int i,j,k;
    int a[5][5];
    double sum =0;
    scanf("%d %d",&m,&n);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("%d",f(0,0));

}
/*
1 2
500 750

2 2
500 750
1000 800

3 3
500000 750000 1000000
500000 1200000 1000000
1000000 800000 750000
*/
