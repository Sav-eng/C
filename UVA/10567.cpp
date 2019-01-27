#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
vector<vector<int> >from;
bool check;
string a,x;
main()
{
    from.resize(256);
    int i,T,s,e,n,ans,l,r,mid,ind;
    cin >> a;
    for(i=0;i<a.size();i++)
    {
        from[a[i]].push_back(i);
    }
    scanf("%d",&T);
    while(T--)
    {
        cin >> x;
        n = x.size();
        ind = -1;
        check = 0;
        for(i=0;i<n;i++)
        {
            vector<int>::iterator last = upper_bound(from[x[i]].begin(),from[x[i]].end(),ind);
            if(last == from[x[i]].end()) check=1;
            ind = last - from[x[i]].begin();
            ind = from[x[i]][ind];
            if(i==0)s = ind;
            if(i==n-1)e = ind;
        }
        if(check)printf("Not matched\n");
        else printf("Matched %d %d\n",s,e);
    }
}
