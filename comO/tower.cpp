#include<bits/stdc++.h>
using namespace std;
int mem[1005];
main()
{
    int n,m,val,ans,check,i,j,l,r,_max;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&l,&r,&val);
        for(j=l;j<=r;j++)
        {
            mem[j]+=val;
        }
        _max = INT_MIN;
        for(j=1;j<=n;j++)
        {
            _max = max(_max,mem[j]);
        }
        ans = 0;
        check =0;
        for(j=1;j<=n;j++)
        {
            if(mem[j]==_max)
            {
                if(!check)ans++;
                check=1;
            }
            else check = 0;
        }
        printf("%d %d\n",_max,ans);
    }
}
