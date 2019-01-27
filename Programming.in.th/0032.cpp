#include<stdio.h>
main()
{
    int n,i,tmp,a[10000],j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
    j=1;
    if(a[0]==0)
    {
        while(a[j]==0)j++;
        a[0] = a[j];
        a[j] = 0;
    }
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }

}
