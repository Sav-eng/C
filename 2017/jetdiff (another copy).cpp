#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
int mem[2][105];
int t1[101];
int t2[101];
int a[200001];
int sumt,sum,ans;
bool flag;
main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    int m;
    scanf("%d",&m);
    for(i=1;i<=100;i++)mem[0][i] = inf;
    for(i=a[1];i<=100;i++)mem[0][i] = (i-a[1])*(i-a[1]);
    flag = 1;
    for(i=2;i<=n;i++)
    {
        for(j=0;j<=101;j++)mem[flag][j] = t1[j] = t2[j] = inf;
        for(j=1;j<=100;j++)t1[j] = min(t1[j-1]+m,mem[!flag][j]);
        for(j=100;j>=1;j--)t2[j] = min(t2[j+1]+m,mem[!flag][j]);
        for(j=a[i];j<=100;j++)mem[flag][j] = (j-a[i])*(j-a[i])+min(t1[j],t2[j]);
        flag = !flag;
    }
    ans = inf;
    for(i=a[n];i<=100;i++)ans = min(ans,mem[!flag][i]);
    printf("%d",ans);
}
/*


3
4 5 1
2

4
5 2 2 5
2

*/
