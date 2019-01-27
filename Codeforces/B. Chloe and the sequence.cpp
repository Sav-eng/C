#include<stdio.h>
long long tab[100];
main()
{
    int n,now,ans,l,r,i;
    long long m,mid;
    scanf("%d%I64d",&n,&m);
    now = n-1;
    ans = n;
    r = n;
    l = 0;
    tab[0]=1;
    for(i=1;i<n;i++)
    {
        tab[i] = tab[i-1]*2;
    }
    i = n-1;

    while(1)
    {
        mid = tab[i];
        i--;
        if(mid+l == m)
        {
            printf("%d",ans);
            return 0;
        }
        //if(mid+l < m)l = mid+1;
        if(mid < m)m = m-mid;
        //printf("%d ",now);
        ans--;
        //now--;
    }
}
