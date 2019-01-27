#include<stdio.h>
#include<algorithm>
using namespace std;
int x[1000000];
int w[1000000];
int ans[1000000];
main()
{
    int n,k,i,j;
    int a;

    int check;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d",&w[i]);
        for(j=0;j<k;j++)
        {
            scanf("%d",&a);
            x[i] += a<<j;
        }
        //printf("%d",x[i]);
    }
    for(i=0;i<(1<<k);i++)ans[i]=100000000;
    ans[0] = 0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<(1<<k);j++)
        {
            ans[j|x[i]] = min(ans[j|x[i]],w[i]+ans[j]);
        }
    }
    printf("%d",ans[(1<<k)-1]);
}
