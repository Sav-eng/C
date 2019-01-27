#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
struct node
{
    int x,val;
    bool operator <(node a)const
    {
        return a.val<val;
    }
};
vector<node>from[151];
priority_queue<node>heap;
set<int>myset;
int key[151];
main()
{
    int T,n,m,a,b,val,i,ans,time=0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)from[i].clear();
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&val);
            from[a].push_back({b,val});
        }
        for(i=0;i<n;i++)key[i] = inf;
        while(!heap.empty())heap.pop();
        heap.push({0,0});
        node t;
        ans=0;
        int check=0;
        myset.clear();
        key[0]=0;
        int j;
        for(j=0;j<n-1;j++)
        {
            while(myset.find(heap.top().x)!=myset.end())heap.pop();
            t = heap.top();
            myset.insert(t.x);
            for(i=0;i<from[t.x].size();i++)
            {
                if(from[t.x][i].val < key[from[t.x][i].x] && myset.find(from[t.x][i].x)==myset.end())
                {
                    key[from[t.x][i].x] = from[t.x][i].val;
                    heap.push({from[t.x][i].x,from[t.x][i].val});
                }
            }

        }
        for(i=0;i<n;i++)ans+=key[i];
        printf("Case #%d: ",++time);
        if(ans<inf)printf("%d\n",ans);
        else printf("Possume!\n");
    }
}
/*

1
3 3
0 1 1000
0 2 1000
1 2 1

*/
