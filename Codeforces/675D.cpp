#include<bits/stdc++.h>
using namespace std;
set<int>MS;
main()
{
    map<int,int>left;
    int n,a,i,ans;
    scanf("%d%d",&n,&a);
    MS.insert(a);
    for(i=0;i<n-1;i++)
    {
        scanf("%d",&a);
        auto it = MS.upper_bound(a);
        int ans;
        if(it != MS.end() && left.count(*it)==0)
        {
            left[*it] = a;
            ans = *it;
        }
        else
        {
            it--;
            ans = *it;
        }
        MS.insert(a);
        printf("-----------------------------%d-----------------------------\n",ans);
    }
}
