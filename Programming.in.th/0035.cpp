#include<stdio.h>
int x[1000],y[1000];
double abs(int x)
{
    if(x>=0)return x;
    else return -x;
}
double area(int i,int j,int k)
{
    return abs(x[i]*y[j] + x[j]*y[k] + x[k]*y[i] - y[i]*x[j] - y[j]*x[k] - y[k]*x[i])/2;
}
main()
{
    double max = -1;
    int n,i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&x[i],&y[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                if(area(i,j,k)>max)max = area(i,j,k);
            }
        }
    }
    printf("%.3lf",max);
}
