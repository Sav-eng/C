#include<stdio.h>
#define inf 1e9
#include<algorithm>
using namespace std;
int a[5000];
int check[5000];
int abs(int x)
{
    if(x<0)return -x;
    else return x;
}
bool cmp(int x,int y)
{
    return x<y;
}
main()
{
    int n,i,ans1=0,_min=inf;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        check[a[i]]++;
    }
    sort(&a[0],&a[n],cmp);
    for(i=0;i<n;i++)
    {
        if(check[a[i]]==1)
        {
            if(abs(2017-a[i])<_min)
            {
                _min = abs(2017-a[i]);
                ans1 = a[i];
            }
        }
    }
    if(ans1==0 && check[ans1] == 0)printf("-1");
    else printf("%d",ans1);
}
/*
3
3 2000 2000
*/

