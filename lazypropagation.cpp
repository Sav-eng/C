#include<bits/stdc++.h>
#define MAXN 100001
using namespace std;
int limit;
int tree[MAXN];
int lazy[MAXN];
int update1(int x,int val)
{
    x+= limit;
    tree[x] += val;
    while(x>1)
    {
        x>>=1;
        tree[x] = tree[x<<1]+tree[x<<1|1];
    }
}
int update(int now,int l,int r,int L,int R,int val)// [L,R) // we want [l,r) in now
{
    printf("l = %d r = %d\n",l,r);
    if(l<L && r<=L)return 0;
    else if(l>=R && r>R)return 0;
    else if(L<=l && r<=R)
    {
        lazy[now] += val;
        //printf("plus %d (%d-%d)*%d\n",(r-l)*val,r,l,val);
        return (r-l)*val;
    }
    else
    {
        int mid = (l+r)/2,t=0;
        t += update(now<<1,l,mid,L,R,val);
        t += update(now<<1|1,mid,r,L,R,val);
        tree[now] += t;
        return t;
    }
}
int query(int now,int l,int r,int L,int R)
{
    if(l>r)return 0;
    else if(l<L && r<=L)return 0;
    else if(l>=R && r>R)return 0;
    else if(l>=L && r<=R)
    {
        int t= now<<1;
        tree[now] += lazy[now]*(r-l);
        lazy[t] +=  lazy[now];
        lazy[t|1] += lazy[now];
        lazy[now] = 0;
        //printf("return %d(%d) %d(%d) (%d)(%d)\n",l,L,r,R,tree[now],lazy[now]);
        return tree[now];
    }
    else
    {
        int t = now<<1;
        int mid = (l+r)/2;
        lazy[t] +=  lazy[now];
        lazy[t|1] += lazy[now];
        lazy[now] = 0;
        //printf("%d %d\n",l,r);
        tree[now] = query(t,l,mid,L,R)+query(t|1,mid,r,L,R);
        return tree[now];
    }
}
main()
{
    int n,T,a,i,type,l,r,val;
    scanf("%d%d",&n,&T);
    limit = 1;
    while(limit<n)limit<<=1;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        update1(i,a);
    }
    for(i=1;i<limit*2;i++)printf("%d ",tree[i]);
    printf("\n");
    while(T--)
    {
        scanf("%d",&type);
        if(type==1)
        {
            scanf("%d%d%d",&l,&r,&val);
            r++;
            update(1,1,limit+1,l,r,val);
            for(i=1;i<limit*2;i++)printf("%d ",tree[i]);
            printf("\n");
            for(i=1;i<limit*2;i++)printf("%d ",lazy[i]);
            printf("\n");
        }
        else
        {
            scanf("%d%d",&l,&r);
            r++;
            printf("\t%d\n",query(1,1,limit+1,l,r));
        }

    }
}
/*

8 5
4 5 7 2 8 9 7 5
1 2 8 5
1 4 6 -3
1 1 6 10
2 1 8
2 3 5



*/
