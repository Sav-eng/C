#include<bits/stdc++.h>
using namespace std;
int a[100001];
int b[100001];
map<long long,int>havel,haver,have;
main()
{
    bool l;
    int n,get,i,j;
    int _max = 0,_maxl=0,_maxr=0;
    scanf("%d",&n);
    get = (n%2==0)?n/2:n/2+1;
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&a[i],&b[i]);
        havel[a[i]]++;
        have[a[i]]++;
        if(a[i]!=b[i])have[b[i]]++;
        _max = max(_max,max(have[b[i]],have[a[i]]));
        //printf("havel[%d] = %d have[%d] = %d\n",a[i],havel[a[i]],a[i],have[a[i]]);

    }
    for(i=0;i<n;i++)if(_maxl < havel[a[i]] && have[a[i]]>=get)_maxl = havel[a[i]];
    //printf("get = %d\n",get);
    if(_max<get)
    {
        printf("-1");
        return 0;
    }
    //printf("_maxl = %d\n",_maxl);
    printf("%d",(_maxl>get)?0:get-_maxl);

}
