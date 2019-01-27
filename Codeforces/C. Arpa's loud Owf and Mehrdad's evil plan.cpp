#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int a[1000];
int mem[1000];
int ck;
int findloop(int x)
{
    if(mem[a[x]]==1)
    {
        return 0;
    }
    else
    {
        mem[a[x]]=1;
        return findloop(a[x])+1;
    }
}
int in[1000];
int out[1000];
main()
{
    int i,n,ans=1e9;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        //a[i].ind = i;
        scanf("%d",&a[i]);
        in[a[i]]++;
        out[i]++;
    }
    for(i=1;i<=n;i++)
    {
        if(in[i]!=out[i] && a[i]!=i && in[i]!=0)
        {
            printf("a[%d] = %d\n",i,a[i]);
            printf("-1");
            return 0;
        }
    }
    int temp;
    for(i=1;i<=n;i++)
    {
        memset(mem,0,sizeof(mem));
        temp = findloop(a[i]);
        if(temp>1)ans = min(ans,temp);
        if(temp == 1)
        {
            ck++;
        }
    }
    if(ck==n)
    {
        //printf("a");
        printf("-1");
        return 0;
    }
    if(ans == 2)
    {
        //printf("a");
        printf("%d",ans-1);
    }
    else printf("%d",ans);
}

/*
5
2 3 4 5 2

6
2 3 4 5 6 6
*/
