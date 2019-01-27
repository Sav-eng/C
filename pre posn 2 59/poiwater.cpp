#include<bits/stdc++.h>
using namespace std;
int cx[]={0,0,1,-1};
int cy[]={1,-1,0,0};
char a[1001][1001];
void f(int x,int y)
{
    if(a[x][y]=='#')return;
    else
    {
        int i;
        a[x][y] = '#';
        for(i=0;i<4;i++)if(a[x+cx[i]][y+cy[i]]=='.')f(x+cx[i],y+cy[i]);
    }

}
int main()
{
    int n,m,i,j,ans;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf(" %c",&a[i][j]);
        }
    }
    ans=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(a[i][j]=='.')
            {
                f(i,j);
                ans++;
            }
        }
    }
    printf("%d",ans);
}
/*

4 4
.#..
#.#.
#.#.
##.#

*/
