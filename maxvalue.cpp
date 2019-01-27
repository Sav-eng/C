#include<stdio.h>
int a[500]={};
int sum;
void fmax(int x)
{
    if(sum<0)
    {
        sum = 0;
    }
    else
    {
        for(i=x;i<n;i++)
        {
            i = x;
            sum+=a[x];
            if(max<sum)max = sum;
            fmax(x+1);
        }
    }
}
main()
{

    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    fmax(0)
}
