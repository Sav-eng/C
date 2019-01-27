#include<bits/stdc++.h>
using namespace std;
int a[1001][1001];
int sum[1001][1001];
int main()
{
    int n,m,time,i,j,ans,x1,x2,y1,y2;
    scanf("%d%d%d",&n,&m,&time);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
            sum[i][j] = a[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
            //printf("%d ",sum[i][j]);
        }
        //printf("\n");
    }
    /*printf("------------------------------\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            printf("%d ",sum[i][j]);
        }
        printf("\n");
    }
    printf("------------------------------\n");*/
    while(time--)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        ans = sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
        printf("%d\n",ans);
    }

}
/*


3 3 5
1 2 1
1 2 3
1 2 5
1 1 3 3
1 1 1 2
1 1 3 1
1 3 3 3
2 2 3 3

*/
