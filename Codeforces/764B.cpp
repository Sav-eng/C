#include<stdio.h>
int a[1000005];
main()
{
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    if(n==2)
    {
        printf("%d %d",a[2],a[1]);
        return 0;
    }
    for(i=1;i<=n;i++)
    {
        if(n%2!=0 || i<=n/2)
        {
            if(i%2!=0)printf("%d ",a[n-i+1]);
            else printf("%d ",a[i]);
        }
        else
        {
            if((i==(n/2)+1) && n%2==0)
            {
                if((i/2)%2==1)printf("%d ",a[(n/2)]);
                else printf("%d ",a[n/2+1]);
            }
            else
            {
                if(i%2==0)printf("%d ",a[n-i+1]);
                else printf("%d ",a[i]);
            }

        }

    }
}
