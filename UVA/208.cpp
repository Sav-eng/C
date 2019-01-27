#include<bits/stdc++.h>
using namespace std;
int n,check;
vector<int>from[25];
int tab[25];
bool vis[25];
int mem[25];
int go[25][25];
void f(int x,int y)
{
    int i;
    if(x==n)
    {
        for(i=0;i<y;i++)if(i)printf(" %d",tab[i]);else printf("%d",tab[i]);
        printf("\n");
        check++;
    }
    else
    {
        vis[x] = 1;
        for(i=0;i<from[x].size();i++)if(!vis[from[x][i]] && go[from[x][i]][n])tab[y]=from[x][i],f(from[x][i],y+1);
        vis[x]=0;
    }
}
main()
{
    //freopen("out.txt","w",stdout);
    int a,b,i,check2=0;
    int _max=0;
    while(scanf("%d",&n)!=EOF)
    {
        memset(vis,0,sizeof(vis));
        memset(go,0,sizeof(go));
        for(i=1;i<=21;i++)from[i].clear(),go[i][i]=1;
        while(scanf("%d%d",&a,&b)&& a && b)
        {
            from[a].push_back(b),from[b].push_back(a);
            go[a][b] = 1; go[b][a] = 1;
        }
        for(i=1;i<=21;i++)sort(from[i].begin(),from[i].end());
        printf("CASE %d:\n",++check2);
        check=0;
        int k,j;
        for(k=1;k<=21;k++)
        {
            for(i=1;i<=21;i++)
            {
                for(j=1;j<=21;j++)
                {
                    go[i][j] |= go[i][k]&go[k][j];
                }
            }
        }
        /*for(i=1;i<=21;i++)
        {
            for(j=1;j<=21;j++)printf("%d ",go[i][j]);
            printf("\n");
        }*/
        if(go[1][n])
        {
            vis[1]=0;
            tab[0]=1;
            f(1,1);
        }
        printf("There are %d routes from the firestation to streetcorner %d.\n",check,n);

    }

}
/*
link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=144


#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>

#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<sstream>



#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) for(int i=0; i<n; i++)
#define getint(n) scanf("%d", &n)
#define pb(a) push_back(a)
#define ll long long
#define SZ(a) int(a.size())
#define read() freopen("input.txt", "r", stdin)
#define write() freopen("output.txt", "w", stdout)
#define mem(a, v) memset(a, v, sizeof(a))
#define all(v) v.begin(), v.end()
#define pi acos(-1.0)
#define INF 10000000000
#define mod abs
#define pf printf
#define sf scanf
#define MAXX 22


using namespace std;
int target;

vector<int>graph[MAXX];
int result[MAXX];
bool done[MAXX];
int cnt;


void rec(int pos)
{
    if(result[pos] == target)
    {
        cnt++;
        pf("1");
        pos++;
        FOR(i, 1, pos)
        {
            pf(" %d", result[i]);
        }
        pf("\n");
        return;
    }



    int u = result[pos];
    int len = SZ(graph[u]);
    pos++;
    int v;
    loop(i, len)
    {
        v = graph[u][i];
        if(!done[v])
        {
            result[pos] = v;
            done[v] = true;
            rec(pos);
            done[v] = false;
        }
    }


}





bool bfs(int u)
{
    bool visited[MAXX];
    mem(visited, 0);

    visited[1] = true;
    queue<int>Q;
    Q.push(u);
    while( !Q.empty() )
    {
        int u = Q.front(); Q.pop();
        int len = SZ(graph[u]);
        loop(i, len)
        {
            int v = graph[u][i];
            if(v == target)
            {
                return true;
            }
            if(!visited[v])
            {
                visited[v] = true;
                Q.push(v);
            }
        }
    }
    return false;

}

int main()
{
    int kaseno = 0;
    int p, q;
    while(getint(target) == 1)
    {
        loop(i, MAXX)
        {
            graph[i].clear();
        }
        while(true)
        {
            getint(p); getint(q);
            if(p == 0 && q == 0) break;

            graph[p].pb(q);
            graph[q].pb(p);
        }
        pf("CASE %d:\n", ++kaseno);

        if(bfs(1) == 0)
        {
            pf("There are 0 routes from the firestation to streetcorner %d.\n", target);
        }
        else
        {
            cnt = 0;
            loop(i, MAXX)
            {
                sort(all(graph[i]));
            }
            mem(done, 0);
            done[1] = true;
            result[0] = 1;
            rec(0);
            pf("There are %d routes from the firestation to streetcorner %d.\n", cnt, target);
        }



    }

    return 0;
}*/
