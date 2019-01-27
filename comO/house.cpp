#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1<<18;
struct node
{
    int _max,_min,ans,l,r;
    bool operator <(node a)const
    {
        return l<a.l;
    }
};
node ST[3*MAXN];
int QS[MAXN];
int a[MAXN];
void build(int now,int l,int r)
{
    ST[now].l = l;
    ST[now].r = r;
    if(l==r)
    {
        ST[now]._max = ST[now]._min = QS[l];
        ST[now].ans = max(a[l],0);
        return;
    }
    int mid = l+r>>1;
    build(now<<1,l,mid);
    build(now<<1|1,mid+1,r);
    ST[now].ans = max(ST[now<<1].ans,ST[now<<1|1].ans);
    ST[now].ans = max(ST[now].ans,ST[now<<1|1]._max-min(ST[now<<1]._min,QS[ST[now<<1].l-1]));
    ST[now]._max = max(ST[now<<1]._max,ST[now<<1|1]._max);
    ST[now]._min = min(ST[now<<1]._min,ST[now<<1|1]._min);
}
int n;
int query(int l,int r)
{
    int ans = 0,_min=QS[l-1],_max = 0,i;
    l += MAXN;
    r += MAXN;
    l--;
    vector<node>seg;
    while(l<r)
    {
        if(l&1)seg.push_back(ST[l++]);
        if(r&1)seg.push_back(ST[--r]);
        l>>=1;
        r>>=1;
    }
    //if(l==r)seg.push_back(ST[l]);
    sort(seg.begin(),seg.end());
    for(i=0;i<seg.size();i++)
    {
        _max = max(_max,seg[i]._max);
        ans = max(ans,seg[i].ans);
        ans = max(ans,seg[i]._max-_min);
        _min = min(_min,seg[i]._min);
    }
    return ans;
}
main()
{
    int m,i,j,l,r,sum,ans;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        QS[i] = QS[i-1]+ a[i];
    }
    //limit = 1;
    //while(limit<n)limit<<=1;
    build(1,1,MAXN);
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&l,&r);l++,r++;
        printf("%d\n",query(l,r));
    }
}
/*

4 5
1 -2 3 -4
0 3
0 0
1 1
2 2
0 3



*/

