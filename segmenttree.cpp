#include<bits/stdc++.h>
#define MAXN 1000001
using namespace std;
int limit;
int tree[4*MAXN];
void update(int x,int val)
{
    x+= limit;
    printf("Update at %d\n",x);
    tree[x] = val;
    while(x>1)
    {
        x>>=1;
        tree[x] = max(tree[x<<1],tree[x<<1|1]);
    }
}
int rmq(int l,int r)
{
    int ans = -1e9;
    l+=limit;
    r+=limit;
    while(l<=r)
    {
        if(l%2!=0)ans = max(tree[l++],ans);
        if(r%2==0)ans = max(tree[r--],ans);
        l>>=1,r>>=1;
    }
    return ans;
}
main()
{
    limit =1;
    int N,Q,i,a,x,y,val;
    scanf("%d%d",&N,&Q);
    while(limit<N)limit*=2;
    for(i=0;i<N;i++)  
    {
        scanf("%d",&a);
        update(i,a);
    }
    for(i=0;i<Q;i++) // start index is 0
    {
        scanf("%d",&a);
        if(a==1)//change
        {
            scanf("%d%d",&x,&val);
            update(x,val);
        }
        else //rmq
        {
            scanf("%d%d",&x,&y);
            printf("%d\n",rmq(x,y));
        }
    }
}
/*


5 5
1 5 3 -2 4


*/
