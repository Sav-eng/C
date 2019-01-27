#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
struct node
{
	int x,val,boot;
	bool operator <(node a)const
	{
		return a.val<val;
	}
};
struct node2
{
	int x,y;
};
node2 tab[100001];
priority_queue<node>heap;
vector<node>from[100001];
long long mem[100001];
int boot[100001];
int p[100001];
int w[100001];
int n,T;
bool dijkstra(int x)
{
	int i;
	for(i=1;i<=n;i++)mem[i] = inf;
	heap.push({1,0,tab[x].y});
	node t;
	while(!heap.empty())
	{
		t = heap.top(); heap.pop();
		for(i=0;i<from[t.x].size();i++)
		{
			if(from[t.x][i].boot <= t.boot && mem[from[t.x][i].x] > (long long)t.val+from[t.x][i].val && (long long)t.val+from[t.x][i].val <= T)
			{
				mem[from[t.x][i].x] = t.val+from[t.x][i].val;
				heap.push({from[t.x][i].x,mem[from[t.x][i].x],t.boot});
			}
		}
	}
	//printf("x = %d,mem[n] = %d boot =%d\n",x,mem[n],tab[x].y);
	if(mem[n]==inf)return 0;
	return 1;
}
bool cmp(node2 x,node2 y)
{
	if(x.y==y.y)return x.x<y.x;
	return x.y<y.y;
}
main()
{
	int m,k,i,j,_min=-1,a,b,val,boot;
	scanf("%d%d%d%d",&n,&m,&k,&T);
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d%d",&a,&b,&boot,&val);
		from[a].push_back({b,val,boot});
		from[b].push_back({a,val,boot});
	}
	for(i=0;i<k;i++)
	{
		scanf("%d%d",&tab[i].x,&tab[i].y);
	}
	sort(&tab[0],&tab[k],cmp);
	int l=0,r=k,mid;
	bool d;
	int ans=inf;
	while(l<=r)
	{
		mid = (l+r)/2;
		d = dijkstra(mid);
		if(d)
		{
			_min = tab[mid].y;
			r = mid-1;
		}
		else l = mid+1;
		//printf("%d\n",ans);
	}
	//printf("%d",_min);
	if(_min==-1)
    {
        printf("-1");
        return 0;
    }
	for(i=0;i<k;i++)
    {
        if(_min<=tab[i].y)ans = min(ans,tab[i].x);
    }
	printf("%d",ans);
}
/*

2 2 3 50
1 2 50 100
1 2 100 50
40 115
30 50
70 100

*/
