#include<stdio.h>
#include<algorithm>
#include<limits.h>
using namespace std;
bool cmp(int x,int y)
{
    return x<y;
}
int a[100005];
main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(&a[0],&a[n],cmp);
    if(n<3)printf("no");
    else if(a[n-1]-a[0]-a[1] <0)
    {
        printf("no");
    }
    else printf("yes");
}
/*
5
2 3 2 5 2

5
3 5 4 4 3
*/
