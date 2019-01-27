#include<stdio.h>
int x,maxval=0,val=0,sum=0;
int a[50000];
int b[50000];
int n;
void pick(int i)
{
    if(sum+a[i]>x)
    {
        if(maxval<val)maxval=val;
    }
    else
    {
        int j;
        for(j=0;j<n;j++)
        {
            sum+=a[j];
            val+=b[j];
            pick(j+1);
        }

    }
}
main()
{
    int i;
    scanf("%d %d",&n,&x);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&a[i],&b[i]);
    }
    for(i=0;i<n;i++)
    {
        pick(i);
    }
    printf("%d",maxval);
}
