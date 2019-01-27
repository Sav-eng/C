#include<stdio.h>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
long long max(long long x,long long y)
{
	if(x>y) return x;
	return y;
}
int n,k;
int node[100005];
int key[100005];
bool vis[100005];
struct edge
{
	int x,cost;
	edge(int a,int b)
	{
		x = a;
		cost = b;
	}
};
vector<edge> from[100005];
queue<int> q;
int bfs(int x,int l)
{
	int i;
	key[x] = l;
	vis[x] = true;
	for(i=0;i<from[x].size();i++)
	{
		if(!vis[from[x][i].x]) bfs(from[x][i].x,l+1);
	}
}
long long dfs(int x)
{
	int i;
	vis[x] = true;
	if(x==k) return 0;
	for(i=0;i<from[x].size();i++)
	{
		if(key[from[x][i].x]<key[x]) return from[x][i].cost + dfs(from[x][i].x);
	}
}
long long dfs2(int x)
{
	int i;
	long long t = 0;
	vis[x] = true;
	for(i=0;i<from[x].size();i++)
	{
		if(key[from[x][i].x]>key[x]&&!vis[from[x][i].x])
		{
			t += max(0,node[from[x][i].x]-2*from[x][i].cost+dfs2(from[x][i].x));
		}
	}
	return t;
}
main()
{
	int i,s,e,x,y,val;
	long long ans = 0;
	scanf("%d",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%d%d%d",&x,&y,&val);
		from[x].push_back(edge(y,val));
		from[y].push_back(edge(x,val));
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&node[i]);
	}
	scanf("%d%d%d",&s,&e,&k);
	bfs(k,0);
	vis[n] = 1;
	memset(vis,false,sizeof vis);
	ans -= dfs(s) + dfs(e);
	for(i=1;i<=n;i++)
	{
		if(vis[i]) ans += node[i];
	}
	for(i=1;i<=n;i++)
	{
		if(vis[i]) ans += dfs2(i);
	}
	printf("%lld",ans);

}
/*
8
1 2 1
2 3 1
3 4 1
3 5 1
3 6 1
2 7 1
6 8 1
1 1 1 3 3 3 1 3
1 7 3
ans = 4
*/
/*
4
1 2 4
1 3 5
2 4 2
7 5 6 4
3 4 2
ans = 11
*/
/*
4
1 2 2
2 3 7
2 4 1
10 7 4 5
1 4 3
ans = 9
*/
/*
10
1 2 1
2 3 1
3 4 1
3 5 1
3 6 1
2 7 1
6 8 1
8 9 10
9 10 0
1 1 1 3 3 3 1 3 0 10000
1 7 3
ans = 9984
*/
