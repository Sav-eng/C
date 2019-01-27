#include<bits/stdc++.h>
using namespace std;
int a[100001];
bool cmp(int x,int y)
{
    return x>y;
}
main()
{
    int n,x,y,i,j;
    long long ans=0;
    scanf("%d%d%d",&n,&x,&y);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n,cmp);
    for(i=0;i<n;i+=x)
    {
        for(j=i;j<i+y;j++,j<n)
        {
            //printf("%d ",j);
            ans += a[j];
        }
    }
    printf("%lld",ans);
}
/*
5 4 2
1 2 3 4 5

*/
