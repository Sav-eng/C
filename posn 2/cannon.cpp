#include<stdio.h>
#include<algorithm>
using namespace std;
int tab[10000005];
int sum;
int n;
int f(int x)
{
    int l = 0;
    int r = n-1;
    int mid;
    int ans = -1;
    while(l<=r)
    {
        mid = (l+r)/2;
        if(tab[mid]<=x)
        {
            ans = mid;
            l =  mid+1;
        }
        else r = mid-1;
    }
    return ans;
}
main()
{
    int _i=0,m,l,k;
    int i,j,xx,yy;
    int _max=0;
    int a,fi;
    scanf("%d%d%d%d",&n,&m,&k,&l);
    for(i=0;i<n;i++)
    {
        scanf("%d",&tab[i]);
    }
    //tab[0]=0;
    int r;
    for(i=0;i<k;i++)
    {
        sum = 0;
        r = 0;
        fi = 0;
        for(j=0;j<m;j++)
        {
            scanf("%d",&a);
            fi = max(r,a-l-1);
            r = a+l;
            sum += f(r)-f(fi);
            //printf("%d %d\n",f(r),f(fi));
        }
        printf("%d\n",sum);
    }
    //for(i=0;i<k;i++)
}


/*
3 1 1 2
1 2 6
2

3 2 4 100
100 300 500
200 1000
199 1000
200 600
1000 1001

*/
