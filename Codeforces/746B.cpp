#include<stdio.h>
char a[1500],ans[1500];
main()
{
    int check=1,n,i;
    scanf("%d",&n);
    scanf("%s",a);
    if(n%2==0)
    {
        for(i=0;i<n/2;i++)
        {
            //printf("%d ",n/2-i);
            //printf("%d ",n/2+i+1);
            //printf("%c ",a[i*2]);
            ans[(n/2)-i] = a[i*2];
            ans[(n/2)+i+1] = a[(i*2)+1];
        }
    }
    else if(n%1==0)
    {
        for(i=0;i<n/2;i++)
        {
            ans[n/2+1+i]=a[i*2];
            ans[n/2-i]=a[i*2+1];
        }
        ans[n] = a[n-1];
    }
    for(i=1;i<=n;i++)
    {
        printf("%c",ans[i]);
    }
}
