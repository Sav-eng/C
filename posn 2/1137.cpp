#include<stdio.h>
#include<algorithm>
using namespace std;
bool cmp(int x,int y)
{
    return x<y;
}
int a[1000005];
main()
{
    int n,i,sum=0,check;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(&a[0],&a[n],cmp);
    for(i=1;i<n;i++)
    {
        sum+=a[i];
        //printf("%d ",sum);
    }
    check = a[0]*(n-2);
    printf("%d",sum+check);
}
