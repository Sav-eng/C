#include<bits/stdc++.h>
using namespace std;
int a[35][30];
int mem[35];
int trac[35];
int n,m;
int f(int x)
{
    if(!mem[x])
    {
        int i,j;
        bool check;
        for(i=0;i<n;i++)
        {
            //printf("A");
            check=0;
            if(i!=x)
            {
                for(j=0;j<m;j++)
                {
                    //printf("%d-----%d\n",a[x][j],a[i][j]);
                    if(a[x][j]<=a[i][j])check=1;
                }
                if(!check)
                {
                    if(mem[x]<=f(i)+1)
                    {
                        mem[x] = f(i)+1;
                        trac[x] = i;
                    }
                }
            }
        }
    }
    //printf("mem[%d] = %d\n",x,mem[x]);
    return mem[x];

}
int ans2[35];
main()
{
    freopen("out.txt","w",stdout);
    int i,j,ans=0,t;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        ans=0;
        memset(ans2,0,sizeof(ans2));
        memset(mem,0,sizeof(mem));
        memset(trac,0,sizeof(trac));
        t=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf("%d",&a[i][j]);
            }
            sort(&a[i][0],&a[i][j]);
        }
        for(i=0;i<n;i++)
        {
            if(ans<=f(i)+1)
            {
                ans = f(i)+1;
                t = i;
            }
        }
        printf("%d\n",ans);
        for(i=0;i<ans;i++)
        {
            ans2[i] = t+1;
            t = trac[t];
        }
        printf("%d",ans2[ans-1]);
        for(i=ans-2;i>=0;i--)printf(" %d",ans2[i]);
        printf("\n");
    }
}
