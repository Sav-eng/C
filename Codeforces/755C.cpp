#include<stdio.h>
int a[10005];
main()
{
    int n,i,ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(i!=0)
        {
            if(a[i]==a[i-1])
            {
                ans++;
            }
        }
        else ans++;
    }
    printf("%d",ans);
}
