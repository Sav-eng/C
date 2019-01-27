#include<bits/stdc++.h>
using namespace std;
set<int>x,y;
multiset<int>lx,ly;
main()
{
    int n,m,T,b;
    char a;
    long long ans;
    scanf("%d%d%d",&n,&m,&T);
    lx.insert(n);
    ly.insert(m);
    x.insert(0);
    x.insert(n);
    y.insert(0);
    y.insert(m);
    while(T--)
    {
        scanf(" %c%d",&a,&b);
        if(a=='V')
        {
            x.insert(b);
            auto l = x.find(b);
            auto r = x.find(b);
            l--,r++;
            //printf("*r = %d *l = %d\n",*r,*l);
            lx.erase(lx.find(*r-*l));
            lx.insert(b-*l),lx.insert(*r-b);
        }
        else
        {
            y.insert(b);
            auto l = y.find(b),r = y.find(b);
            l--,r++;
            //printf("*r = %d *l = %d\n",*r,*l);
            ly.erase(ly.find(*r-*l));
            ly.insert(b-*l),ly.insert(*r-b);
        }
        ans = *lx.rbegin();
        ans *= *ly.rbegin();
        printf("%I64d\n",ans);
    }
}
