#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
struct node
{
    int x,check;
    node(int _x =0,int _check =0)
    {
        x = _x;
        check = _check;
    }
};
vector<node>from[1000];
vector<int>bac[1000];
queue<node>q;
int nin[10000];
int mem[10000];
main()
{
    int n,m,i,j;
    int ans=0;
    int a,b;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        from[a].push_back(node(b,0));
        bac[b].push_back(a);
    }
    node t;
    for(i=0;i<n;i++)
    {
        if(mem[i]==0 || nin[i]!=bac[i].size())q.push(node(i,0));
        while(!q.empty())
        {
            t = q.front();
            mem[t.x]=1;
            nin[t.x]++;
            q.pop();
            if(from[t.x].size()==0 && t.check==1)
            {
                ans++;
            }
            else if(mem[from[t.x][j].x]==0)
            {
                for(j=0;j<from[t.x].size();j++)
                {
                    q.push(node(from[t.x][j].x,1));
                }
            }
        }
    }
    printf("%d",ans);
}
