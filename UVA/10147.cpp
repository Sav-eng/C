#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,y;
    double val;
    bool operator <(node a)const
    {
        return a.val<val;
    }
};
int head[751];
priority_queue<node>heap;
int findhead(int x)
{
    if(x==head[x])return x;
    return head[x] = findhead(head[x]);
}
int a[1001];
int b[1001];
main()
{
    //freopen("out.txt","w",stdout);
    int i,j,val,m,n,k,T;
    double delx,dely,cost;
    scanf("%d",&T);
    while(T--)
    {
        while(!heap.empty())heap.pop();
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&a[i],&b[i]);
        }
        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                delx = fabs(a[i]-a[j]);
                dely = fabs(b[i]-b[j]);
                cost = sqrt((delx*delx)+(dely*dely));
                heap.push({i,j,cost});
            }
            head[i] = i;
        }
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&a[i],&b[i]);
            if(findhead(head[a[i]])!=findhead(head[b[i]]))head[findhead(a[i])]=findhead(head[b[i]]);
        }
        node t;
        bool check=0;

        while(!heap.empty())
        {
            t = heap.top(); heap.pop();
            if(findhead(head[t.x])!=findhead(head[t.y]))
            {
                printf("%d %d\n",t.x,t.y);
                check++;
                head[findhead(t.x)]=findhead(head[t.y]);
            }
        }
        if(!check)printf("No new highways need\n");
        if(T)printf("\n");
    }
}
