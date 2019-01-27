#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
struct node
{
    int x,y,val,ord;
    bool operator <(node a)const
    {
        return a.val<val;
    }
};
int head[201];
int findhead(int x)
{
    if(x==head[x])return x;
    return head[x] = findhead(head[x]);
}
priority_queue<node>heap;
int a[201];
int b[201];
int val[201];
int choose[201];
main()
{
    int time=0,T,i,j,n,m,ord,way,ans,sum;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=m;i++)
        {
            scanf("%d%d%d",&a[i],&b[i],&val[i]);
            heap.push({a[i],b[i],val[i],i});
        }
        node t;
        int check=0;
        for(i=1;i<=m;i++)head[i]=i;
        while(!heap.empty())
        {
            t = heap.top();heap.pop();
            if(findhead(head[t.x])!=findhead(head[t.y]))
            {
                choose[check++] = t.ord;
                head[findhead(t.x)]=findhead(head[t.y]);
            }
        }
        printf("Case #%d : ",++time);
        if(check!=n-1)printf("No way\n");
        else
        {
            way = 0;
            ans = inf;
            for(i=0;i<n-1;i++)
            {
                //printf("choose[%d] = %d\n",i,choose[i]);
                for(j=1;j<=n;j++)head[j] = j;
                for(j=1;j<=m;j++) if(j!=choose[i])heap.push({a[j],b[j],val[j],ord});
                check = 0;
                sum = 0;
                while(!heap.empty())
                {
                    t = heap.top(); heap.pop();
                    if(findhead(head[t.x])!=findhead(head[t.y]))
                    {
                        sum += t.val;
                        check++;
                        head[findhead(t.x)]=findhead(head[t.y]);
                    }
                }
                //printf("check = %d\n",check);
                if(check==n-1)way++,ans = min(sum,ans);
            }
            if(way==0)printf("No second way\n");
            else printf("%d\n",ans);
        }
    }
}
