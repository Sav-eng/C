#include<bits/stdc++.h>
using namespace std;
main()
{
    int T,n,m,i,_min,_max,ans;
    bool check1,check2;
    freopen("a2.in","r",stdin);
    freopen("a2.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        _min = 101;
        _max = 0;
        scanf("%d%d",&n,&m);
        _max = max(n,m);
        _min = min(n,m);
        ans = _min;
        check1 = (_max-_min==0);
        if(_max-_min>0)
        {
            check2 = (_max-_min)%2==0;
            ans += ((_max-_min)%2==0)?(_max-_min)/2:(_max-_min)/2+1;
        }
        printf("%d\n",ans);
        for(i=0;i<_min;i++)printf("%d %d\n",i,i);
        if(n==_min)
        {
            if(check2)_min++;
            for(i=_min;i<_max;i+=2)printf("%d %d\n",n-1,i);
        }
        else
        {
            //printf("-%d-",check2);
            if(check2)_min++;
            for(i=_min;i<_max;i+=2)printf("%d %d\n",i,m-1);
        }

    }
}
/*

1
5 3

*/
