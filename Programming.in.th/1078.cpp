
#include<stdio.h>
#include<algorithm>
using namespace std;
bool cmp(int x,int y)
{
    return x<y;
}
int a[1005];
main()
{   int n,i,j,check=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    sort(&a[0],&a[n],cmp);
    i=0;
    j=n-1;
    while(i<=j)
    {
        //printf("a");

        check += a[j]-a[i];
        j--;
        i++;
    }
    printf("%d",check);
}
