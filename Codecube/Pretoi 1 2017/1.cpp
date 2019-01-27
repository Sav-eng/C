#include<bits/stdc++.h>
#define MAXN 1000001
using namespace std;
vector<int>have;
long long tab[MAXN];
long long mem[MAXN];
long long ans,ans2;
main()
{
    int n,task,i,j,a;
    scanf("%d%d",&n,&task);
    for(i=1;i<MAXN;i++)mem[i] = 1e9;
    tab[1]=1;
    mem[1]=0;
    for(j=0;j<n;j++)
    {
        scanf("%d",&a);
        if(!tab[a])
        {
            have.push_back(a);
            tab[a] = 1;
            mem[a] = 1;
        }
        else
        {
            ans++;
            ans2 += mem[a];
        }
        for(i=0;i<have.size();i++)
        {
            if((long long)a*have[i]<(long long)MAXN)
            {
                if(!tab[a*have[i]])
                {
                    have.push_back(a*have[i]);
                    tab[a*have[i]] = 1;
                    //printf("%d\n",a*have[i]);
                }
                mem[a*have[i]] = min(mem[a*have[i]],mem[a]+mem[have[i]]);
            }
        }
    }
    if(task==2)printf("%lld %lld",ans,ans2);
    else printf("%lld",ans);
}

/*
7 2
3 2 15 6 6 6 6

3 2
10 10000 5

*/
