#include<bits/stdc++.h>
using namespace std;
vector<int>a[2];
main()
{
    int n,i,x,_max=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        _max = max(_max,x);
        a[0].push_back(x);
    }
    int t = 1;
    while(t<_max)t<<=1;
    t>>=1;
    bool flag= 0;
    while(t>0)
    {
        a[!flag].clear();
        for(i=0;i<a[flag].size();i++)
        {
            if(a[flag][i]&t)
            {
                a[!flag].push_back(a[flag][i]);
            }
        }
        if(a[!flag].size()>=2)flag = !flag;
        t>>=1;
    }
    printf("%d",a[flag][0]&a[flag][1]);

}
