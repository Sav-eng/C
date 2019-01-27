#include<stdio.h>
main()
{
    int n,i,j,k,a[500],sum=0;
    for(i=0;i<9;i++)
    {
        scanf("%d",&a[i]);
        sum += a[i];
    }
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            if(sum - a[i] - a[j] == 100)
            {
                for(k=0;k<9;k++)
                {
                    if(k!=i && k != j)printf("%d\n",a[k]);
                }
                return 0;
            }
        }
    }
}
