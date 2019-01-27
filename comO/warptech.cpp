#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int MAXN = 5e3+1;
struct node
{
    int x,y,val;
    bool operator <(node a)const
    {
        return a.val<val;
    }
};
int head[MAXN];
int findhead(int x)
{
    if(x==head[x])return x;
    return head[x] = findhead(head[x]);
}
priority_queue<node>heap;
int ans[MAXN];
main()
{
    int n,m,k,i,a,b,val;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&a,&b,&val);
        heap.push({a,b,val});
    }
    for(i=1;i<=k;i++)ans[i] = inf;
    for(i=0;i<n;i++)head[i] = i;
    int comp = n;
    while(!heap.empty())
    {
        node t = heap.top(); heap.pop();
        if(findhead(t.x)!=findhead(t.y))
        {
            head[findhead(t.x)]=findhead(t.y);
            comp--;
        }
        ans[comp] = min(ans[comp],t.val);
        //printf("ans[%d] = %d\n",comp,ans[comp]);
    }
    int x;
    for(i=0;i<k;i++)
    {
        scanf("%d",&x);
        printf("%d\n",ans[x]);
    }
}
/*

5 6 4
0 1 20
0 2 10
2 3 30
1 3 10
2 4 40
3 4 50
1
2
3
4


*/
