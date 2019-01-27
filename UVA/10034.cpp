#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,y;
    double val;
    bool operator < (node a)const
    {
        return a.val<val;
    }
};
int head[101];
priority_queue<node>heap;
int findhead(int x)
{
    if(x==head[x])return x;
    return head[x] = findhead(head[x]);
}
double a[101];
double b[101];
main()
{
    //freopen("out.txt","w",stdout);
    int T,n,i,j,time=0;
    double delx,dely,cost;
    scanf("%d",&T);
    while(T--)
    {
        if(time++)printf("\n");
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%lf%lf",&a[i],&b[i]);
        }
        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                delx = abs(a[i]-a[j]);
                dely = abs(b[i]-b[j]);
                cost = sqrt((delx*delx)+(dely*dely));
                heap.push({i,j,cost});
            }
            head[i] = i;
        }
        double ans=0;
        node t;
        while(!heap.empty())
        {
            t = heap.top(); heap.pop();
            if(findhead(head[t.x])!=findhead(head[t.y]))
            {
                ans += (double)t.val;
                head[findhead(t.x)] = findhead(head[t.y]);
            }
        }
        printf("%.2lf\n",ans);
    }
}
