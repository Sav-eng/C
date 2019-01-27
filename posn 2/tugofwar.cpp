#include<stdio.h>
#include<algorithm>
using namespace std;
bool cmp(int x,int y)
{
    return x<y;
}
int abs(int x)
{
    if(x>0)return x;
    else return -x;
}

main()
{
    int n,i,a[10000],b[10000];
    int sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    sort(&a[0],&a[n],cmp);
    sort(&b[0],&b[n],cmp);
    for(i=0;i<n;i++)
    {
        sum+= abs(b[i]-a[i]);
    }
    printf("%d",sum);
}
