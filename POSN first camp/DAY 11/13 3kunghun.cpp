#include<stdio.h>
main()
{
    char a[300][300];
    int i,j,check=0,n,count1=0,count2=0;
    scanf("%d",&n);
    for(i=0;i<2*n-1;i++)
    {
        check++;
        for(j=0;j<n*6-3;j++)
        {
            if(i+j==2*n-2)a[i][n*2-1-check] = '/';
            if(i==j)a[i][j] = '\\';
            if(i+j==2*n+3)
            {
                if(i+0x31>n+'0')
                {
                    count1+=2;
                    a[i][4*n-2-check] = i+0x31-count1;
                }
                else a[i][4*n-2-check] = i+0x31;
            }
            if(j-i==2*n-1)
            {
                if(i+0x31>n+'0')
                {
                    count2+=2;
                    a[i][2*n-1+i] = i+0x31-count2;
                }
                else a[i][2*n-1+i] = i+0x31;
            }
            if(j-i==4*n-2)a[i][i+4*n-2]= '*';
            if(i+j==4*n+5)a[i][6*n-3-check] = '*';
        }
        if(i==n-1)a[n-1][n-1] = 'X';
    }
    for(i=0;i<2*n-1;i++)
    {
        for(j=0;j<n*6-3;j++)
        {
            printf("%2c",a[i][j]);
        }
        printf("\n");
    }
}
