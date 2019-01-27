#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e3+1;
int a[MAXN];
int b[MAXN];
int val[MAXN];
int trac[MAXN];
int mem[MAXN];
main()
{
    int n,i,j,ans=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d%d",&a[i],&b[i],&val[i]);
        mem[i] = val[i];
    }
    int start;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            if(b[j]<=a[i])
            {
                mem[i] = max(mem[i],val[i]+mem[j]);
                if(mem[i]== val[i]+mem[j])trac[i] = j;
            }
        }
        ans = max(ans,mem[i]);
        if(ans==mem[i])start = i;
    }
    int t = start;
    vector<int>Ans;
    while(t!=0)
    {
        Ans.push_back(t);
        t = trac[t];
    }
    printf("%d\n",ans);
    printf("%d\n",Ans.size());
    for(i=Ans.size()-1;i>=0;i--)printf("%d ",Ans[i]);
}
