#include<stdio.h>
#include<algorithm>
#define inf 1e9
using namespace std;
bool cmp (int x,int y)
{
    return x<y;
}
int a[1000];
int b[1000];
main()
{
    int n,m,i,ans;
    for(i=0;i<100;i++)a[i]=inf;
    for(i=0;i<100;i++)b[i]=inf;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<m;i++)
    {
        scanf("%d",&b[i]);
    }
    sort(&a[0],&a[n],cmp);
    sort(&b[0],&b[m],cmp);
    //for(i=0;i<n;i++)printf("%d ",a[i]);
    ans = min(a[0]+b[0]+100,min(a[0]+a[1],b[0]+b[1]));
    printf("%d",ans);
}
/*

2 4
150 100
40 10 30 20

*/
