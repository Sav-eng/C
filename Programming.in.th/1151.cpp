#include<stdio.h>
#include<algorithm>
using namespace std;
int a[200005];
int b[200005];
int maxb;
int bsearch(int l,int r,int x)
{
    while(l<r)
    {
        int mid = (l+r)/2;
        if(b[mid]<x) l = mid+1;
        else
        {
            r = mid;
        }
    }
    return l;
}
main()
{
    int i,t,n,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    j=0;
    for(i=0;i<n;i++)
    {
        if(i==0)
        {
            b[j] = a[i];
            j++;
        }
        else
        {
            if(a[i]>b[j-1])
            {
                b[j]=a[i];
                j++;
            }
            else if(a[i]<b[j-1])
            {
                b[bsearch(0,j,a[i])] = a[i];
            }
        }
    }
    printf("%d",j);
}
