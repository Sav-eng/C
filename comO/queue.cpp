#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+1;
int tree[MAXN];
int mem[MAXN];
int mem2[MAXN];
void update(int x,int val)
{
    while(x<=MAXN)
    {
        tree[x] += val;
        x+= x&-x;
    }
}
int query(int x)
{
    int sum = 0;
    while(x>0)
    {
        sum += tree[x];
        x -= x&-x;
    }
    return sum;
}
main()
{
    int check = 0,T,op,l,x,r;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d",&x);
            mem[++check] = x;
            mem2[x] = check;
            update(x,1);
        }
        else if(op==2)
        {
            if(query(MAXN)==0)
            {
                printf("0\n");
                continue;
            }
            int l = 1,r = MAXN;
            int mid,ans;
            while(l<=r)
            {
                mid = (l+r)/2;
                int t = query(mid);
                if(t>=1)r = mid-1,ans=mid;
                else l = mid+1;
            }
            //printf("%d",ans);
            //besearch find val == 1
            update(ans,-1);
            printf("%d\n",mem2[ans]);
        }
        else
        {
            scanf("%d",&x);
            printf("%d\n",query(mem[x]-1));
        }
    }
}
