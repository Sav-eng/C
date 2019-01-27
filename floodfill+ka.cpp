#include<stdio.h>
int a[100][100]={{}};
int aikea=0;
void ffind(int i,int j)
{
    if(a[i+1][j] == 0 && a[i-1][j] == 0 && a[i][j+1] == 0 && a[i][j-1] == 0)
    {

    }
    else
    {
        if(a[i][j]==2)aikea++;
        a[i][j]=0;
        if(a[i+1][j]==1 || a[i-1][j]==2)
        {
            if(a[i+1][j]==2)aikea++;
            a[i+1][j] = 0;
            ffind(i+1,j);
        }
        if(a[i-1][j]==1 ||  a[i-1][j]==2)
        {
            if(a[i-1][j]==2)aikea++;
            a[i-1][j] = 0;
            ffind(i-1,j);
        }
        if(a[i][j+1]==1 ||  a[i][j+1]==2)
        {
            if(a[i][j+1]==2)aikea++;
            a[i][j+1] = 0;
            ffind(i,j+1);
        }
        if(a[i][j-1]==1 ||  a[i][j-1]==2)
        {
            if(a[i][j-1]==2)aikea++;
            a[i][j-1] = 0;
            ffind(i,j-1);
        }
    }
}
main()
{
    int n,i,j,check=0,checkkea=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]==1 || a[i][j]==2)
            {
                ffind(i,j);
                check++;
                if(aikea>=1)
                {
                    checkkea++;
                    aikea = 0;
                }
            }
        }
    }
    printf("%d %d",check,checkkea);
}
