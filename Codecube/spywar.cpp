#include<stdio.h>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
queue<int>q;
priority_queue<long long>heap;
vector<int>from[200005];
vector<int>from2[200005];
int a[200005];
int mem[200005];
long long ans=0;
main()
{
	int n,m,k,i,x,y,t,_max=0,j;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		from[x].push_back(y);
		from[y].push_back(x);
	}
	q.push(k);
	for(i=1;i<=n;i++)mem[i]=-1;
	mem[k]=0;
	while(!q.empty())
	{
		t = q.front(); q.pop();
		for(i=0;i<from[t].size();i++)
		{
			if(mem[from[t][i]]==-1)
			{
				mem[from[t][i]] = mem[t]+1;
				q.push(from[t][i]);
				from2[mem[from[t][i]]].push_back(from[t][i]);
				_max = max(mem[from[t][i]],_max);
				//printf("mem[%d] = %d\n",from[t][i],mem[from[t][i]]);
			}
		}
		//if(t==k)mem[t] = -1;
	}
	//printf("%d",_max);
	for(i=1;i<=n;i++)if(mem[i]==-1 && a[i]>0)ans+=a[i];
	for(i=n;i>0;i--)
	{
		//printf("a");
		for(j=0;j<from2[i].size();j++)
		{
			//printf("%d ",a[from2[i][j]]);
			if(a[from2[i][j]]>0)
			{
				heap.push(a[from2[i][j]]);
			}
		}
		if(!heap.empty())
		{
			ans += heap.top();
			heap.pop();
		}
	}
	printf("%lld",ans);

}
/*
5 5 3
5 8 2 10 7
2 1
4 2
3 1
4 1
5 4

5 8 4
1 10 1 10 10
1 5
1 4
1 2
5 2
5 4
4 3
2 3
5 3

*/
