#include<stdio.h>
#include<queue>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
vector<int>from[1000];
queue<int>q;
int mem[10000];
bool visit[10000];
main()
{
    //FILE *fp = fopen("10000.txt","w");
    int check =0,n,m,x,y,t,i,ans1,ans2;
    while(scanf("%d",&n) && n)
    {
        scanf("%d",&m);
        for(i=1;i<=n;i++)from[i].clear();
        memset(mem,0,sizeof(mem));
        memset(visit,0,sizeof(visit));
        ans1 = 1;
        ans2 = 0;
        check++;
        while(scanf("%d%d",&x,&y) && x && y)
        {
            from[x].push_back(y);
            //from[y].push_back(x);
        }
        q.push(m);
        while(!q.empty())
        {
            //printf("a");
            t = q.front();
            q.pop();
            for(i=0;i<from[t].size();i++)
            {
                if(!visit[from[t][i]])
                {
                    mem[from[t][i]] = mem[t]+1;
                    if(ans1<mem[from[t][i]])
                    {
                        ans1 = mem[from[t][i]];
                        ans2 = from[t][i];
                    }
                    q.push(from[t][i]);
                    visit[t]=1;
                }
            }
        }
        //for(i=1;i<=n;i++)printf("%d ",mem[i]);
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",check,m,ans1,ans2);
    }
}
