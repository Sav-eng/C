#include<stdio.h>
#include<algorithm>
using namespace std;
int n,m,k;
int cut[20005],cost[20005];
int mem[2][20005];
main()
{
    int i,j;
    int flag = 0;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<m;i++) scanf("%d",&cut[i]);
    for(i=0;i<k;i++) scanf("%d",&cost[i]);
    cut[m] = n;
    for(j=0;j<k;j++)
    {
        for(i=0;i<=m;i++)
        {
            mem[flag][i] = 0;
            if(i<j) continue;
            mem[flag][i] = max(mem[!flag][i-1],mem[flag][i-1]) + (cut[i]-cut[i-1])*cost[j];
            //printf("mem[%d][%d] = %d\n",j,i,mem[flag][i]);
        }
        flag = !flag;
    }
    printf("%d",mem[!flag][m]);
}
