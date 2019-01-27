#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
#define inf 1<<30
int n,m,k;
int p[1000005];
int mem[1000005];
int trace[1000005];
int cnt[15];
void cal(int x)
{
    if(x==0) return ;
    cnt[trace[x]]++;
    cal(x-p[trace[x]]);
}
main()
{
    int i,j,a,b;
    int ans,x,y;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<k;i++) scanf("%d",&p[i]);
    for(i=1;i<=m;i++)
    {
        mem[i] = inf;
        for(j=0;j<k;j++)
        {
            if(p[j]>i) continue;
            mem[i] = min(mem[i],1+mem[i-p[j]]);
            if(mem[i]==1+mem[i-p[j]]) trace[i] = j;
        }
    }
    ans = inf;
    for(i=n;i<=m;i++)
    {
        a = mem[i]; b = mem[i-n];
        if(a+b<ans)
        {
            ans = a+b;
            x = i; y = i-n;
        }
    }
    printf("%d %d\n",mem[x],mem[y]);
    memset(cnt,0,sizeof(cnt));
    cal(x);
    for(i=0;i<k;i++) printf("%d ",cnt[i]);
    printf("\n");
    memset(cnt,0,sizeof(cnt));
    cal(y);
    for(i=0;i<k;i++) printf("%d ",cnt[i]);
}
