#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
struct node
{
    int x,val,ind;
    bool operator <(node a)const
    {
        return a.val<val;
    }
};
int trac[10001];
priority_queue<node>heap;
vector<node>from[10001];
int mem[10001];
int n;
int a[10001];
int b[10001];
int c[10001];
int dijkstra(int x,int y,int z)
{
    node t;
    int i;
    heap.push({1,0,0});
    mem[1]=0;
    while(!heap.empty())
    {
        t = heap.top(); heap.pop();
        for(i=0;i<from[t.x].size();i++)
        {
            //printf("mem[%d] = %d > %d+%d = %d\n",from[t.x][i].x,mem[from[t.x][i].x],t.val+from[t.x][i].val,t.val,from[t.x][i].val);
            if(mem[from[t.x][i].x] > t.val+from[t.x][i].val && (t.x != x || from[t.x][i].x != y || from[t.x][i].val!=z) && (t.x != x || from[t.x][i].x != y || from[t.x][i].val!=z))
            {
                mem[from[t.x][i].x] = t.val+from[t.x][i].val;
                //printf("%d------>%d = %d %d %d %d\n",t.x,from[t.x][i].x,mem[from[t.x][i].x],x,y,z);
                if(x==0 && y==0 && z==0)
                {
                    //printf("trac[%d] = %d\n",from[t.x][i].x,from[t.x][i].ind);
                    trac[from[t.x][i].x] = from[t.x][i].ind;
                }
                heap.push({from[t.x][i].x,mem[from[t.x][i].x],from[t.x][i].ind});
            }
        }
    }
    return mem[n];
}
int main()
{
    int m,i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
        from[a[i]].push_back({b[i],c[i],i});
        from[b[i]].push_back({a[i],c[i],i});
    }
    for(i=1;i<=n;i++)mem[i]=inf;
    int t2;
    dijkstra(0,0,0);
   // printf("t=%d\n",t);
    trac[1]=0;
    int last;
    last = n;
    int t =trac[n];
    int ans2=inf,ans=0;
    /*while(a[t]!=1)
    {
        printf("t = %d\n",t);
        t = a[trac[t]];
    }*/
    while(t!=0)
    {
        for(i=1;i<=n;i++)mem[i]=inf;
        t2 = dijkstra(a[t],b[t],c[t]);
        //printf("t2 = %d t = %d\n",t2,t);
        if(ans<t2)
        {
            ans2 = t;
            ans = t2;
        }
        else if(ans==t2 && t<ans2)
        {
            ans2 = t;
            ans = t2;
        }
        if(last!=a[t])
        {
            last = a[t];
            t = trac[a[t]];
        }
        else
        {
            last = b[t];
            t = trac[b[t]];
        }
    }
    printf("%d",ans2);
}
/*
3 3
1 2 1
2 3 1
1 3 5
1

5 7
1 2 2
1 3 3
2 3 5
2 4 1
2 5 1
3 4 4
4 5 2
1

4 4
1 2 1
1 3 2
2 4 100
3 4 3

5 7
1 2 3
2 4 6
3 4 5
1 4 2
4 2 3
3 5 1
5 1 10
*/
