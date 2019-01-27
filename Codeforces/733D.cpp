#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>,int >mp,mp2;
int k,ans1,ans2,ans;
void check(int x,int y,int z,int ind)
{
    if(x>y)swap(x,y);
    pair<int,int>p;
    p = make_pair(x,y);
    if(mp.find(p)==mp.end())
    {
        //printf("(%d)(%d)\n",x,y);
        mp[p] = z;
        mp2[p] = ind;
    }
    else
    {
        int _max;
        _max = min(mp[p]+z,min(x,y));
        //printf("_max = %d\n",_max);
        if(ans < _max)
        {
            k = 2;
            ans = _max;
            ans1 = mp2[p];
            ans2 = ind;
        }
        if(mp[p]<z)
        {
            mp[p] = z;
            mp2[p] = ind;
        }
    }
}
main()
{
    int n,i,a,b,c;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        int _max;
        _max = min(a,min(b,c));
        if(ans<_max)
        {
            k = 1;
            ans = _max;
            ans1 = i;
        }
        check(a,b,c,i);
        check(a,c,b,i);
        check(c,b,a,i);
        //printf("ans = %d\n",ans);
    }
    printf("%d\n",k);
    if(k==1)printf("%d",ans1);
    if(k==2)printf("%d %d",ans1,ans2);
}
