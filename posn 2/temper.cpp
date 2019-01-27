#include<stdio.h>
#include<algorithm>
#include<limits.h>
using namespace std;
int n;
int ans = INT_MIN;
int x[50][50];
bool visit[50][50];
void f(int i,int j)
{
    if(i<0 || j<0 || i>=n || j>= n)
    {
        return;
    }
    if(x[i+1][j] > x[i][j] && x[i+1][j] != 100 && visit[i+1][j] == 0 && i!=n-1)
    {
        visit[i+1][j] = 1;
        ans = max(ans,x[i+1][j]);
        f(i+1,j);
    }
    if(x[i][j+1] > x[i][j] && x[i][j+1] != 100 && visit[i][j+1] == 0 && j!=n-1)
    {
        visit[i][j+1] = 1;
        ans = max(ans,x[i][j+1]);
        f(i,j+1);
    }
    if( x[i-1][j] > x[i][j] && x[i-1][j] != 100 && visit[i-1][j]  == 0 && i!=0)
    {
        visit[i-1][j] = 1;
        ans = max(ans,x[i-1][j]);
        f(i-1,j);
    }
    if( x[i][j-1] > x[i][j] && x[i][j-1] != 100 && visit[i][j-1] == 0 && i!=0)
    {
        visit[i][j-1] = 1;
        ans = max(ans,x[i][j-1]);
        f(i,j-1);
    }
}
main()
{
    int a,b,i,j;
    scanf("%d%d%d",&n,&a,&b);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&x[i][j]);
        }
    }
    ans = x[i][j];
    f(b-1,a-1);
    printf("%d",ans);
}
/*
4
2 1
100 1 3 8
0 2 1 4
2 3 5 100
0 8 8 100

1
1 1
9

5
4 2
0 1 100 100 0
100 2 3 1 1
100 100 4 5 100
8 7 100 6 100
7 100 100 100 9
*/
