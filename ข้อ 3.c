#include<stdio.h>
main()
{
    long x[100000],y,n,i,j,min = 1000000,k,a;
    scanf("%ld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%ld",&x[i]);

    }
    for(i=0;i<n;i++)
    {
        for(j=1;j<=x[i];j++)
        {
            for(k=1;k<=x[i];k++)
            {
                a = j*k;
                if(a==x[i])
                {

                    if(j<k)
                    {
                        y = k-j ;
                    if(min>y)min = y;
                    }
                    if(j>k)
                    {
                        y = j-k;
                        if(min>y)min = y;
                    }
                    if(j==k){min = 0;}
                }
            }
        }
        printf("Case #%ld \n",i+1);
        printf("%ld",min);
        min = 1000000;
    }
}
