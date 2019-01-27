#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int ans[100005];
int a[1005];
main()
{
    int time,n,m,anss;
    int i,j;
    int co = 1;
    scanf("%d",&time);
    while(time--)
    {
        memset(ans,-1,sizeof(ans));
        ans[0]=0;
        anss=0;
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(ans[j]<=i && ans[j]!= -1 && ans[(j+a[i])%m]==-1)
                {
                    ans[(j+a[i])%m]=i+1;
                }
            }
        }
        for(i=0;i<m;i++)
        {
            if(ans[i]>-1) anss = i;
        }
        printf("Case #%d: %d\n",co++,anss);
    }
}
/*
2
5 5
1 2 3 4 2
3 10
1 3 5
*/
