#include<stdio.h>
#include<algorithm>
using namespace std;
int mem[5][505][55];
int tab[505][505];
int n,k;
int checkn=0;
bool flag;
main()
{
    int i,j,ans=0,o;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&tab[i][j]);
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            for(o=0;o<=k;o++)
            {
                mem[flag][j][o] = mem[flag][j][o-1];
                if(o==0)mem[flag][j][o] = max(mem[flag][j][o],max(mem[!flag][j][k],mem[flag][j-1][k]));
                else mem[flag][j][o] = max(mem[flag][j][o],max(mem[!flag][j][o-1] + tab[i][j] , mem[flag][j-1][o-1] + tab[i][j] ));
                ans = max(mem[flag][j][o],ans);
            }
        }
        flag = !flag;
    }
    printf("%d",ans);

}
/*

5 2
1 1 3 2 1
1 1 2 9 1
1 1 1 9 1
1 1 1 1 9
1 1 1 1 1

32

*/
