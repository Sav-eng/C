#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
string line;
stringstream ss;
struct node
{
    int x,val;
    bool operator <(node a)const
    {
        return a.val<val;
    }
};
int abs(int x)
{
    if(x<0)return  -x;
    else return x;
}
vector<node>from[105];
priority_queue<node>heap;
int tab[105];
int a[105];
int mem[105];
main()
{
    int n,k,i,j,ind,e;
    while(scanf("%d%d",&n,&e)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        getline(cin,line);
        for(i=0;i<n;i++)
        {
            getline(cin,line);
            ss.clear();
            ss << line;
            ind = 0;
            while(ss >> tab[ind++]);
            ind--;
            for(j=0;j<ind;j++)
            {
                for(k=0;k<ind;k++)
                {
                    if(k!=j)
                    {
                        from[tab[j]].push_back({tab[k],(abs(tab[j]-tab[k])*a[i])+60});
                    }
                }
            }
        }
        heap.push({0,0});
        node t;
        for(i=0;i<100;i++)mem[i]=inf;
        mem[0]=0;
        //printf("%d ",e);
        while(!heap.empty())
        {
            t= heap.top(); heap.pop();
            if(t.x==e)
            {
                if(t.x!=0)
                {
                    printf("%d\n",mem[t.x]-60);
                }
                else printf("0\n");
                break;
            }
            for(i=0;i<from[t.x].size();i++)
            {
                if(mem[from[t.x][i].x] > mem[t.x]+from[t.x][i].val)
                {
                    mem[from[t.x][i].x] = mem[t.x]+from[t.x][i].val;
                    heap.push({from[t.x][i].x,mem[from[t.x][i].x]});
                }
            }
            //printf("%d\n",t.x);
        }
        if(mem[e]==inf)printf("IMPOSSIBLE\n");
        while(!heap.empty())heap.pop();
        for(i=0;i<100;i++)from[i].clear();
        memset(tab,0,sizeof(tab));
        memset(a,0,sizeof(a));
    }
}
/*
while(scanf("%d%d",&n,&e)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        getline(cin,line);
        for(i=0;i<n;i++)
        {
            getline(cin,line);
            ss.clear();
            ss << line;
            ind = 0;
            while(ss >> tab[ind++]);
            ind--;
        }
    }
*/
