#include<stdio.h>
#include<algorithm>
#include<limits.h>
using namespace std;
long tab[500005];
bool cmp(long x,long y)
{
    return x<y;
}
main()
{
    int n,m,k,i,c,a,b;
    long bup=n,bdown=0;
    int l,r;
    scanf("%d%d%d",&n,&m,&k);
    tab[0]=1;
    tab[1]=n+1;
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        tab[i*2]=a;
        tab[i*2+1]=a+b;
    }
    sort(&tab[0],&tab[(m+1)*2],cmp);
    for(i=1;i<=(m+1)*2;i++)
    {
        if(tab[i]==tab[i-1])
        {
            tab[i] = INT_MAX;
            tab[i-1] = INT_MAX;
        }
    }
    sort(&tab[0],&tab[(m+1)*2],cmp);
    for(i=0;i<=(m+1)*2;i++)
    {
        if(tab[i]==INT_MAX)
        {
            m = i-1;
            break;
        }
    }
    for(i=0;i<k;i++)
    {
        bup = n+1;
        bdown = 1;
        scanf("%d",&c);
        l = 0;
        r = m;
        int mid;
        while(l<=r)
        {
            mid = (l+r)/2;
            if(tab[mid]<=c)
            {
                bdown = tab[mid];
                l = mid+1;
            }
            else
            {
                bup = tab[mid];
                r = mid-1;
            }
        }
        printf("\t%ld\n",bup-bdown);
    }
}

/*
10 1 10
1 3
1
2
3
4
5
6
7
8
9
10


10
*/

