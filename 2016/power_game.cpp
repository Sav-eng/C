#include<stdio.h>
#include<algorithm>
using namespace std;
bool cmp(int x,int y)
{
    return x>y;
}
int a[100000];
int b[100000];
main()
{
    int n,i,j,ans;
    int sum=0;
    int p1=0;
    int p2=0;
    ans =0;
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
    while(p2!=n)
    {
        if(a[p1]>b[p2])
        {
            ans+=a[p1];
            p1++;
            p2++;
        }
        else p2++;
    }
    printf("%d",ans);
}
