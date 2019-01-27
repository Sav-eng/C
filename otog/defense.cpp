#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int a[3001];
int mem[3001][3001];
main()
{
    int n,m,i,j,k;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    int ans = inf;
    for(i=1;i<=n;i++)
    {
        mem[i][0] = inf;
        for(j=1;j<=k;j++)
        {
            if(i-j>=0)mem[i][j] = mem[i-j][k-j]+a[i];
            else mem[i][j] = inf;
            mem[i][j] = min(mem[i][j],mem[i][j-1]);
            if(i-j>=n-k+1)ans = min(mem[i][j],ans);
        }
    }
    printf("%d",ans);
}
/*
6 3
1 9 1 1 9 1


*/
