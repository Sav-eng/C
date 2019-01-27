#include<stdio.h>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
queue<int>q;
vector<int>from[10000];
int tab[10000];
main()
{
    int n,m,k,i,a,j,x,y,t;
    int _count =0,ans;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<k;i++)
    {
        scanf("%d",&a);
        tab[a]==1;
    }
    for(j=0;j<m;j++)
    {
        scanf("%d%d",&x,&y);
        from[x].push_back(y);
        from[y].push_back(x);
    }
    while(!q.empty())
    {
        t = q.front();
        q.pop();
        for(i=0;i<from[t].size();i++)
        {
            if(!tab[from[t][i]])
            {
                _count++;
                q.push(from[t][i]);
            }
        }
    }
    ans = _count*(_count-1)/2;
    printf("%d",ans+_count-m);

}
