#include<bits/stdc++.h>
#define inf 1e9
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
int head[501];
int findhead(int x)
{
    if(x==head[x])return x;
    return head[x] = findhead(head[x]);
}
priority_queue<node>heap;
vector<int>from[501];
int a[501];
int b[501];
int check[501];
int tab[501];
main()
{
    //freopen("out.txt","w",stdout);
    int T,n,m,i,j;
    scanf("%d",&T);
    while(T--)
    {
        while(!heap.empty())heap.pop();
        scanf("%d%d",&n,&m);
        for(i=1;i<=m;i++) scanf("%d%d",&a[i],&b[i]);
        for(i=1;i<=m;i++)
        {
            for(j=i+1;j<=m;j++)heap.push({i,j,(double)sqrt(((a[i]-a[j])*(a[i]-a[j]))+((b[i]-b[j])*(b[i]-b[j])))});
            head[i] = i;
        }
        double ans=0;
        int number=0;
        node t;

        while(!heap.empty())
        {
            t = heap.top(); heap.pop();
            if(findhead(head[t.x])!=findhead(head[t.y]))
            {
                head[findhead(t.x)]=findhead(head[t.y]);
                memset(check,0,sizeof(check));
                number = 0;
                ans = t.val;
                for(i=1;i<=m;i++)
                {
                    if(!check[findhead(head[i])])
                    {
                        check[findhead(head[i])] = 1;
                        number++;
                    }
                }
            }
            if(number==n)break;
        }
        printf("%.2lf\n",ans);
    }
}
/*

1
2 12
0 1
0 2
0 4
0 5
0 7
0 12
100 1
100 2
100 4
100 5
100 7
100 13
*/
