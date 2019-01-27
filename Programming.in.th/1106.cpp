#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5;
int tree[MAXN];
void update(int x,int val)
{
    while(x<MAXN)
    {
        tree[x]+=val;
        x+=x&-x;
    }
}
int query(int x)
{
    int sum =0;
    while(x > 0)
    {
        sum += tree[x];
        x -= x&-x;
    }
    return sum;
}
int n;
int point(int now,int go)
{
    int t;
    if(now+go>n)
    {
        t = query(n)-query(now)+query(now+go-n);
        //printf("Q1 = %d Q2 = %d Q3 = %d [%d]\n",query(n-1),query(now-1),query(now+go-n),t);
    }
    else t= query(now+go)-query(now);
    return t;
}
main()
{
    int k,i,now,gonext;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)update(i,1);
    now = k;
    for(i=0;i<n-1;i++)
    {
        update(now,-1);
        //bsearch find next now
        int sum = query(n);
        //printf("%d ",sum);
        if(now>sum)
        {
            if(now%sum==0)gonext = sum;
            else gonext = (now%sum);
        }
        else gonext = now;
        //printf("now : %d GO: %d \n",now,gonext);
        int l = 1,r = n;
        int ans = r;
        while(l<=r)
        {
            int mid = l+r>>1;
            //printf("l = %d r = %d mid = %d\n",l,r,mid);
            //printf("%d ", point(now,mid));
            if(point(now,mid)>=gonext)
            {
                ans = mid;
                r = mid-1;
            }
            else
            {

                l = mid+1;
            }

        }
        now += ans;
        if(now>n)now-=n;
        //printf("\n");
    }
    printf("%d",now);
}
