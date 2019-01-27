#include<bits/stdc++.h>
using namespace std;
set<int>s;
main()
{
    int n,m,k,Q,i,a;
    int sum=0;
    scanf("%d%d%d",&n,&m,&k);
    scanf("%d",&Q);
    n++;k++;
    sum = n/k;
    s.insert(0);
    s.insert(n);
    for(i=1;i<=Q;i++)
    {
        scanf("%d",&a);
        s.insert(a);
        auto l = s.find(a);
        auto r = s.find(a);
        l--,r++;
        sum += ((a-*l)/k)+((*r-a)/k);
        sum -= (*r-*l)/k;
        //printf("sum = %d\n",sum);
        if(sum<m)
        {
            printf("%d",i);
            return 0;
        }

    }
    printf("-1");
}
