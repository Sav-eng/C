#include<stdio.h>
main()
{
    int i,j,a[5][5],sum1,minar[5][5],min=999999;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            sum1 = a[i][j]+a[i][j+1]+a[i+1][j]+a[i+1][j+1];
            if(min > sum1)
            {
                    min = sum1;
                    minar[0][0] =a[i][j];
                    minar[0][1] =a[i][j+1];
                    minar[1][0] =a[i+1][j];
                    minar[1][1] =a[i+1][j+1];

            }
        }
    }
    printf("%d\n%d%d\n%d%d",min,minar[0][0],minar[0][1],minar[1][0],minar[1][1]);


}
