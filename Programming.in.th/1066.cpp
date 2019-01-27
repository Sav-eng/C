#include<stdio.h>
main()
{
    int n,a[1005];
    int i,j,_j;
    int ans,sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        ans =0;
        for(j=0;j<n-1;j++)
        {
            while(a[j]==-1)j++;
            if(a[j+1]-a[j]>ans)
            {
                ans = a[j+1]-a[j];
                _j = j;
            }
        }
        a[_j]=-1;
        a[_j+1]=-1;printf("%d ",ans);
        sum+=ans;
    }

}
