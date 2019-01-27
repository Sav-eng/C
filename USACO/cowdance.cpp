#include<stdio.h>
#include<algorithm>
#define inf 1e9
using namespace std;
struct cmp
{
    bool operator()(int& x,int& y)
    {
        return x>y;
    }
};
int a[100005];
int cpy[100005];
int n,k,i,l,r,mid,cnt=0,sum,time,j,_min,t,temp,cont,pl,_min2,_max;
int ans=0;
main()
{
    freopen("cowdance.in","r",stdin);
    freopen("cowdance.out","w",stdout);

    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    l=1;r=n+1;
    ans = 1;
    for(i=0;i<100000;i++)cpy[i] = inf;
    while(l<=r)
    {
        mid = (l+r)/2;
        for(i=0;i<mid;i++)cpy[i] = a[i];
        cnt=mid;
        //printf("%d\n",mid);
        i=mid;
        sum = 0;
        while(1)
        {
            _min = inf;
            for(j=0;j<mid;j++)
            {
                _min = min(cpy[j],_min);
            }
            //printf("_min = %d\n",_min);
            //printf("mid = %d l =%d r = %d\n",mid,i,r);
            for(j=0;j<mid;j++)
            {
                cpy[j]-=_min;
                if(cpy[j]<=0 && i <n)
                {
                    cpy[j]=a[i++];
                }
                //for(t=0;t<mid;t++)printf("%d ",cpy[t]);
                //printf("\n");
                //printf("%d\n",i);
            }
            if(i==n)
            {
                _max = 0;
                for(j=0;j<mid;j++)
                {
                    _max = max(_max,cpy[j]);
                }
                //for(j=0;j<mid;j++)printf("%d ",cpy[j]);
                //printf("\n");
                //printf("a");
                sum+=_max;
                //printf("%d",_max);
                break;

            }
            sum+=_min;
            //printf("%d ",sum);
            //printf("%d\n",i);
        }
        //printf("%d",sum);
        if(sum<k)
        {
            //printf("%d ",sum);
            ans = mid;
            r = mid-1;
        }
        else l = mid +1;
        //printf("mid = %d sum = %d\n",mid,sum);
    }
    printf("%d",ans);
}
/*
5 20
4
4
4
4
4

5 8
4
7
8
6
4

1 2
2
*/
