#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
struct node
{
    int x,val,old;
    bool operator < (node a)const
    {
        return a.val<val;
    }
};
int vis[50];
int mem[50];
int mem2[50];
char mp2[50];
int mp[200];
int ans[200];
vector<node>from[202];
priority_queue<node>heap;
main()
{
    //freopen("out.txt","w",stdout);
    int n,i,check=0,chck;
    char a,b,c,d;
    int val;
    while(scanf("%d",&n)&&n)
    {
        for(i=1;i<=200;i++)from[i].clear();
        memset(mp,0,sizeof(mp));
        memset(mp2,NULL,sizeof(mp2));
        check=0;
        for(i=0;i<n;i++)
        {
            scanf(" %c %c %c %c%d",&a,&b,&c,&d,&val);
            if(mp[c]==0)
            {
                mp[c] = ++check;
                mp2[check]=c;
            }
            if(mp[d]==0)
            {
                mp[d] = ++check;
                mp2[check]=d;
            }
            if(a=='M')//old
            {
                //printf("%d--%d[%d]\n",mp[c],mp[d],val);
                from[mp[c]].push_back({mp[d],val,1});
                if(b=='B')from[mp[d]].push_back({mp[c],val,1});//undirec
            }
            else//young
            {
                from[mp[c]].push_back({mp[d],val,0});
                if(b=='B')from[mp[d]].push_back({mp[c],val,0});//undirec
            }
        }
        scanf(" %c %c",&a,&b);
        for(i=1;i<=check;i++)
        {
            mem[i] = inf;
            mem2[i] = inf;
        }
        heap.push({mp[a],0,0});
        mem[mp[a]]=0;
        mem2[mp[b]]=0;
        heap.push({mp[b],0,1});
        node t;
        memset(vis,0,sizeof(vis));
        chck=0;
        memset(ans,0,sizeof(ans));
        int _min = inf;
        while(!heap.empty())
        {
            t = heap.top(); heap.pop();
            if(vis[t.x] && mem[t.x]+mem2[t.x]<=_min)
            {
                _min = mem[t.x]+mem2[t.x];
                ans[mp2[t.x]]=1;
            }
            if(!vis[t.x])vis[t.x]=1;
            for(i=0;i<from[t.x].size();i++)
            {
                if(t.old==from[t.x][i].old && t.old)
                {
                    //printf("%d--->mem[%d] = %d(%d)\n",t.x,from[t.x][i].x,mem2[from[t.x][i].x],t.old);
                    if(mem2[from[t.x][i].x] > t.val+from[t.x][i].val)
                    {
                        mem2[from[t.x][i].x] = t.val+from[t.x][i].val;
                        heap.push({from[t.x][i].x,mem2[from[t.x][i].x],t.old});
                    }
                }
                else if(t.old==from[t.x][i].old && !t.old)
                {
                    //printf("a");
                    if(mem[from[t.x][i].x] > t.val+from[t.x][i].val)
                    {
                        mem[from[t.x][i].x] = t.val+from[t.x][i].val;
                        heap.push({from[t.x][i].x,mem[from[t.x][i].x],t.old});
                    }
                }
            }
            //printf("mem[%d] = %d[%d]\n",t.x,t.val,t.old);
        }
        check=0;
        for(i='A';i<='Z';i++)if(ans[i])check++;
        if(_min!=inf && check)
        {
            printf("%d",_min);
            for(i='A';i<='Z';i++)if(ans[i])printf(" %c",i);
            printf("\n");
        }
        else printf("You will never meet.\n");

    }
}
