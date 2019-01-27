#include<bits/stdc++.h>
#define inf 1e19
using namespace std;
struct node
{
    int x;
    double sp,ti;
    bool operator <(node a)const
    {
        if(a.ti==ti)return a.sp<sp;
        return a.ti<ti;
    }
};
double minsp[205];
int n;
double adjmatrix[205][205];
double solve(int s,int e,double v,double c)
{
    int i;
    for(i=1;i<=n;i++)minsp[i]=0;
    priority_queue<node>heap;
    heap.push({s,v,0});
    node t;
    while(!heap.empty())
    {
        t = heap.top(); heap.pop();
        if(t.x==e)return t.ti;
        if(minsp[t.x]>=t.sp)continue;
        minsp[t.x] = t.sp;
        //printf("[%d][%lf][%lf]\n",t.x,t.sp,t.ti);

        for(i=1;i<=n;i++)
        {
            double newspeed;
            if(adjmatrix[t.x][i]>=inf-1)continue;
            newspeed = (t.sp/adjmatrix[t.x][i]<=c)? 0:t.sp-adjmatrix[t.x][i]*c;
            if(minsp[i]>=newspeed && i!=e)continue;
            double newtime = t.ti+adjmatrix[t.x][i]/t.sp;
            //printf("newmin = %lf\n",newmin);
            heap.push({i,newspeed,newtime});
        }
    }
    return -1;
}
main()
{
    int m,k,i,j,a,b;
    double val;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)adjmatrix[i][j]=inf;
    for(i=0;i<m;i++)
    {
        scanf("%d%d%lf",&a,&b,&val);
        adjmatrix[a][b] = min(adjmatrix[a][b],val);
        adjmatrix[b][a] = min(adjmatrix[b][a],val);
    }
    char s[20];
    double c,v;
    while(k--)
    {
        scanf("%s",&s);
        if(s[0]=='t')
        {
            scanf("%d%d%lf%lf",&a,&b,&v,&c);
            //printf("%d %d %lf %lf",a,b,c,v);
            double ans = solve(a,b,v,c);
            if(ans==-1)printf("IMPOSSIBLE\n");
            else printf("%lf\n",ans);
        }
        else if(s[0]=='a')
        {
            int _n,_m;
            scanf("%d%d",&a,&_m);
            for(i=0;i<_m;i++)
            {
                scanf("%d%lf",&b,&val);
                adjmatrix[a][b] = min(adjmatrix[a][b],val);
                adjmatrix[b][a] = min(adjmatrix[b][a],val);
            }
        }
        else
        {
            scanf("%d",&a);
            for(i=1;i<=n;i++)
            {
                adjmatrix[i][a] = adjmatrix[a][i] = inf;
            }
        }
    }
}
/*

5 10 8
1 2 5.0
1 1 5.5
3 1 6.0
1 3 7.0
2 1 3.0
2 2 9.5
3 3 8.5
4 4 10.0
5 5 11.0
1 2 5.5
travel 2 3 10.0 1.0
travel 2 4 6.0 0.0
destroy 4
add 4 1
3 15.5
travel 1 4 3.5 0.1
destroy 2
add 2 3
1 1.0
3 3.0
5 5.0
travel 4 5 1.0 0.2

*/
