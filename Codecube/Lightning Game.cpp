#include<stdio.h>
main()
{
    int t,n,m,i,j;
    int sum1,sum2;
    int ans;
    int p1,p2;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d %d",&n,&m);
        p1 = n-m-2;
        p2 = n-m;
        sum1 = 1;
        sum2=1;
        //printf("%d %d\n",p1,p2);
        for(j=0;j<p1;j++)
        {
            sum1*=2;
            sum1%=1000000007;
        }
        if(p1<0)sum1=0;
        for(j=0;j<p2;j++)
        {
            sum2*=2;
            sum2%=1000000007;
        }
        if(p2<0)sum2=0;
        ans = sum1+sum2;
        printf("%d\n",ans);
    }
}
/*
2
2 1
4 2
*/
