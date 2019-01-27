#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#define inf 1e9
using namespace std;
int mem[200000];
int ans=1;
vector<int>from[200000];
queue<int>q;
int a,b,t;
main()
{
    int n,m,i,k;
    scanf("%d%d%d",&k,&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&a,&b);
        from[a].push_back(b);
    }
    //for(i=0;i<=n;i++)mem[i] = inf;
    //mem[1]=0;
    q.push(1);
    while(!q.empty())
    {
        t = q.front();
        q.pop();
        for(i=0;i<from[t].size();i++)
        {
            if(mem[from[t][i]]==0)
            {
                mem[from[t][i]] = mem[t]+1;
                if(mem[from[t][i]] <= k)ans = max(ans,from[t][i]);
                q.push(from[t][i]);
            }

        }
    }
    printf("%d",ans);
}
/*

2 6 5
1 2
1 3
2 6
3 4
5 6

3 5 4
1 2
1 3
2 3
3 5

*/
