#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int mem[2001][2001];
main()
{
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        mem[0][a[i]] = i;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<n;j++)
        {
            if(a[j+1]<a[j])
            {
                swap(a[j+1],a[j]);
            }
            mem[i][a[j]] = j;
        }
        mem[i][a[j]] = j;
    }
    int x,y;
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        printf("%d\n",mem[x][y]);
    }
}
/*
5 5
4 5 3 1 2
0 1
1 5
2 3
1 4
2 4

*/
