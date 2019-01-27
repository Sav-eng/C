#include<bits/stdc++.h>
#define MAXN 100001
using namespace std;
int tree[25][MAXN];
int lazy[25][MAXN];
int limit;
void update1(int x,int bit)
{
    x += limit;
    tree[bit][x]++;
    while(x>1)
    {
        x>>=1;
        tree[bit][x] = tree[bit][x<<1]+tree[bit][x<<1|1];
    }
}
int update(int now,int l,int r,int L,int R,int bit)
{
    if(l<L&&r<=L)return (lazy[bit][now]%2)?r-l-tree[bit][now]:tree[bit][now];
    else if(l>=R && r>R)return (lazy[bit][now]%2)?r-l-tree[bit][now]:tree[bit][now];
    else if(l>=L && r<=R)
    {
        int dif,New;
        //tree[bit][now] = New;
        lazy[bit][now]++;
        New = (lazy[bit][now]%2==0)?tree[bit][now]:r-l-tree[bit][now];
        //printf("bit = %d up %d---%d return %d\n",bit,l,r,New);
        return New;
    }
    else
    {
        int mid = (l+r)/2;
        int t= 0;
        t += update(now<<1,l,mid,L,R,bit);
        t += update(now<<1|1,mid,r,L,R,bit);
        //printf("[%d,%d) t = %d\n",l,r,t);
        tree[bit][now] = t;
        return tree[bit][now];
    }
}
int query(int now,int l,int r,int L,int R,int bit)
{
    if(l<L && r<=L)return 0;
    else if(l>=R && r>R)return 0;
    else if(l>=L && r<=R)
    {
        int next = now<<1;
        if(lazy[bit][now]%2)tree[bit][now] = r-l-tree[bit][now];
        lazy[bit][next] += lazy[bit][now];
        lazy[bit][next|1] += lazy[bit][now];
        lazy[bit][now] = 0;
        //printf("%d--%d tree[%d][%d] = %d\n",l,r,bit,now,tree[bit][now]);
        return tree[bit][now];
    }
    else
    {
        int next = now<<1;
        int t;
        int mid = (l+r)/2;
        if(lazy[bit][now]%2)tree[bit][now] = r-l-tree[bit][now];
        lazy[bit][next] += lazy[bit][now];
        lazy[bit][next|1] += lazy[bit][now];
        lazy[bit][now] = 0;
        //printf("%d %d---> (%d %d[%d]) (%d %d[%d])\n",l,r,l,mid,next,mid,r,next|1);
        return query(next,l,mid,L,R,bit)+query(next|1,mid,r,L,R,bit);
    }
}
main()
{
    int n,i,j,a,m,type,l,r,ans,val;
    scanf("%d",&n);
    limit= 1;
    while(limit<n)limit<<=1;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        for(j=0;j<20;j++)
        {
            if(a&1)
            {
                //printf("%d ",j);
                update1(i,j);
            }
            a>>=1;
        }
        //printf("\n");
    }
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&type,&l,&r);
        r++;
        if(type==1)
        {
            ans = 0;
            for(j=0;j<4;j++)
            {
                int t = query(1,1,limit+1,l,r,j);
                ans += t*(1<<j);
                printf("ans = %d(%d)*(%d)\n",ans,t,(1<<j));
            }
            printf("%d\n",ans);
        }
        else
        {
            scanf("%d",&val);
            for(j=0;j<4;j++)
            {
                if(val&1)
                {
                   update(1,1,limit+1,l,r,j);
                }
                val>>=1;
                //printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n");
            }


        }
        /*for(int i=0;i<4;i++)
        {
            printf("----> %d -----> ",i);
            for(int j=1;j<2*limit;j++)
            {
                printf("%d(%d)%d ",tree[i][j],lazy[i][j],j);
            }
            printf("\n");
        }*/
    }
}
/*

5
4 10 3 13 7
8
1 2 4
2 1 3 3
1 2 4
1 3 3
2 2 5 5
1 1 5
2 1 2 10
1 2 3

26
22
0
34
11

10
10 2 10 7 9 6 7 1 10 3
10
2 2 4 8
2 1 9 2
2 7 10 10
1 7 7
2 1 5 5
2 7 9 7
1 2 3
2 6 9 10
2 2 4 4
1 4 8

15
18
46

8
1 2 3 4 5 6 7 8
18
2 1 8 7
1 1 1
1 2 2
1 3 3
1 4 4
1 5 5
1 6 6
1 7 7
1 8 8
2 1 8 7
1 1 1
1 2 2
1 3 3
1 4 4
1 5 5
1 6 6
1 7 7
1 8 8
*/
