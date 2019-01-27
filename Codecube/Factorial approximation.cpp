#include<stdio.h>
main()
{
    double a=1;
    int ans[100005];
    int i,j,lak=1,b[10005],n;
    int max = 1;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
        if(b[i]<=max);
        else
        {
            for(j=max+1;j<=b[i];j++)
            {
                a = a*j;
                while(a>=10)
                {
                    a/=10;
                    lak++;
                }
                ans[j] = lak;
            }
            max = b[i];
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d\n",ans[b[i]]);
    }
    return 0;
}
