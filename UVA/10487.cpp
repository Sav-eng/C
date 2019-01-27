#include<bits/stdc++.h>
using namespace std;
int a[1001];
int tab[1000001];
main()
{
    //freopen("out.txt","w",stdout);
    int n,m,i,j,check=0,l,r,mid,x,lower,upper,time=0;
    while(scanf("%d",&n)&&n)
    {
        memset(tab,0,sizeof(tab));
        check = 0;
        for(i=0;i<n;i++)scanf("%d",&a[i]);
        for(i=0;i<n;i++)
        {
                for(j=i+1;j<n;j++)
                {
                    tab[check++] = a[i]+a[j];
                    //printf("tab[%d] = %d\n",check-1,tab[check-1]);
                }
        }
        n= check;
        sort(&tab[0],&tab[check]);
        scanf("%d",&m);
        printf("Case %d:\n",++time);
        for(i=0;i<m;i++)
        {
            scanf("%d",&x);
            l = 0,r=n-1,lower = 0;
            while(l<=r)
            {
                mid = (l+r)/2;
                if(tab[mid]<=x)
                {
                    l = mid+1;
                    lower = mid;
                }
                else
                {
                    r = mid-1;
                }
                //printf("l = %d r = %d\n",l,r);
            }
            l = 0,r=n-1,upper = n-1;
            while(l<=r)
            {
                mid = (l+r)/2;
                if(tab[mid]<x)
                {
                    l = mid+1;
                }
                else
                {
                    upper = mid;
                    r = mid-1;
                }
                //printf("l = %d r = %d\n",l,r);
            }
            if(x-tab[lower]<tab[upper]-x)printf("Closest sum to %d is %d.\n",x,tab[lower]);
            else printf("Closest sum to %d is %d.\n",x,tab[upper]);
        }
    }
}
