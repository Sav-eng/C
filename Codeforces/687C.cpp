#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
int mem[2][500][500];
vector<int>ans;
main()
{
    int n,m,i,j,k,a;
    bool flag;
    scanf("%d%d",&n,&m);
    mem[0][0][0] = 1;
    flag = 1;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        for(j=0;j<=m;j++)
        {
            for(k=0;k<=m;k++)
            {
                mem[flag][j][k] |= mem[!flag][j][k];
                if(j-a>=0)
                {
                    mem[flag][j][k] |= mem[!flag][j-a][k];
                    if(k-a>=0)mem[flag][j][k] |= mem[!flag][j-a][k-a];
                }
            }
        }
        flag = !flag;
    }
    for(i=0;i<=m;i++)if(mem[!flag][m][i])ans.push_back(i);
    printf("%d\n",ans.size());
    for(i=0;i<ans.size();i++)printf("%d ",ans[i]);
}
