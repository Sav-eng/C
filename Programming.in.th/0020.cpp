#include<stdio.h>
main()
{
    int i,j,a[100][100],b[100]={},max=-999999,check;
    for(i=0;i<5;i++)
    {
        for(j=0;j<4;j++)
        {
            scanf("%d",&a[i][j]);
            b[i] += a[i][j];
        }
        if(max<b[i])
        {
            max = b[i];
            check = i;
        }
    }
    printf("%d %d",check+1,max);
}
