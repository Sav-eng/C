#include<stdio.h>
#include<algorithm>
#define inf 1e9
#include<set>
#include<string.h>
using namespace std;
set<int>myset;
int a[1500000];
int b[1500000];
int jod[1500000];
int newbox[1500000];
main()
{
    int t,n,k,check,mid,l,r,i,sum,ans,check1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&a[i],&b[i]);
            newbox[i] = inf;
            if(jod[b[i]]==0)
            {
                jod[b[i]] = i;
            }
            else
            {
                newbox[jod[b[i]]] = i;
                jod[b[i]] = i;
            }
        }
        l = 0;
        r = inf;
        ans = -1;
        /*for(i=1;i<=n;i++)
        {
            printf("%d ",jod[i]);
        }
        printf("\n");
        for(i=1;i<=n;i++)
        {
            //printf("%d1 ",jod[i]);
            printf("%d ",newbox[i]);
        }
        printf("\n");*/
        while(l<=r)
        {
            mid = (l+r)/2;
            sum = 0;
            check1 = inf;
            check =1;
            for(i=1;i<=n;i++)
            {
                if(sum+a[i]<=mid && check1 != i)
                {
                    check1 = min(check1,newbox[i]);
                    sum+=a[i];
                }
                else
                {
                    check++;
                    check1 = newbox[i];
                    sum = a[i];
                }
            }
            //printf("%d\n",check);
            if(check<=k)
            {
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        printf("%d\n",ans);
        for(i=1;i<=n;i++) jod[b[i]] = 0;
    }
}
