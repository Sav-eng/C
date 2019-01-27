#include<stdio.h>
#include<algorithm>
#define inf 1<<30
using namespace std;
int tab[1050000];
int mem[1050000];
int tr[100];
int trace[1050000];
void trac(int n)
{
    if(n<=0)return ;
    tr[trace[n]] +=1;
    trac(n-tab[trace[n]]);
}
main()
{
    int n,m,t,i,j;
    int ans;
    int ans1 = inf;
    int ans2 = inf;
    int t1,t2;
    ans = inf;
    scanf("%d%d%d",&n,&m,&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&tab[i]);
    }
    for(i=0;i<m;i++)mem[i]=inf/2;
    mem[0]=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<t;j++)
        {
            if(i-tab[j]>=0)
            {
                mem[i] = min(mem[i],mem[i-tab[j]]+1);
                if(mem[i]==mem[i-tab[j]]+1)
                {
                    trace[i] = j;
                }
            }
        }
    }
    for(i=n;i<m;i++)
    {
        ans = min(ans,mem[i]+mem[i-n]);
        if(ans==mem[i]+mem[i-n])
        {
            ans1 = mem[i];
            ans2 = mem[i-n];
            t1 = i;
            t2 = i-n;
        }
    }
    printf("%d %d\n",ans1,ans2);
    for(i=0;i<t;i++)tr[i]=0;
    trac(t1);
    for(i=0;i<t;i++)
    {
        printf("%d ",tr[i]);
    }
    for(i=0;i<t;i++)tr[i]=0;
    trac(t2);
    printf("\n");
    for(i=0;i<t;i++)
    {
        printf("%d ",tr[i]);
    }
}
