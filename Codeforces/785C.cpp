#include<bits/stdc++.h>
#define inf 1e11
main()
{
    double l,r,i;
    int n,m;
    double eat,get,ans,mid,_eat,_get;
    scanf("%d%d",&n,&m);
    if(m>n)m=n;
    //printf("%d %d",m,n);
    l=0;
    r=inf;
    /*for(i=0;i<10;i++)
    {
        printf("%d\n",(((i*i)+i)/2)-n-(m*i));
    }*/
    while(l<=r)
    {
        mid = floor((l+r)/2);
        //printf("l = %lld r = %lld mid = %lld\n",l,r,mid);
        eat = ((mid*mid)+mid)/2;
        if(mid>m)get = n+(m*(mid-m)+((m*m)-m)/2);
        else get = n+((m*m)-m)/2;

        //printf("eat = %.0lf get = %.0lf mid = %.0lf l = %.0lf r = %.0lf\n",eat,get,mid,l,r);
        if(eat<get)
        {
            l = mid+1;
        }
        else
        {
            ans = mid;
            r = mid-1;
        }

    }
    printf("%.0lf",ans);
}
/*
1000000000000000000 1000000000000000000
100000000000000000 100000000000000000

*/
