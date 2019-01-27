#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6;
int x[MAXN];
int y[MAXN];
int mem[MAXN];
main()
{
    int n,m,i,X,Y,ans=0,_min,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
    }
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&X,&Y);
        _min = 2*MAXN;
        for(j=0;j<n;j++)
        {
            int t = fabs(x[j]-X)+fabs(Y-y[j]);
            _min = min(_min,t);
        }
        //printf("\t%d\n",_min);
        mem[_min]++;
        ans = max(ans,mem[_min]);
    }
    printf("%d",ans);
}
