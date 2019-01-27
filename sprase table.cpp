#include<bits/stdc++.h>
using namespace std;
int a[10001];
int m[10001][100];
main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    for(i=0;i<n;i++)m[i][0] = i;
    for(j=1;(1<<j)-1<n;j++)
    {
        for(i=0;i+(1<<j)-1<n;i++)
        {
            if(a[m[i][j-1]] <= a[m[i+(1<<j-1)][j-1]])m[i][j] = m[i][j-1];
            else m[i][j] = m[i+(i<<(j-1))][j-1];
            printf("m[%d][%d] = %d\n",i,j,m[i][j]);
        }
    }
}
