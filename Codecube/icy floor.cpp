#include<stdio.h>
#include<queue>
using namespace std;
int n;
struct node
{
	int x,y,direc;
	node(int _x  = 0,int _y = 0,int _direc = 0)
	{
		x = _x;
		y = _y;
		direc = _direc;
	}
};
bool check(int x,int y)
{
	if(x >= 0 && y>= 0 && x < n && y < n)return 1;
	else return 0;
}
node t;
int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};
int mem[1050][1050][5];
int tab[1050][1050];
queue<node>q;
main()
{
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&tab[i][j]);
		}
	}
	q.push({0,0,1});
	q.push({0,0,2});
	mem[0][0][1] = mem[0][0][2] = 0;
	// direc  0 --> u || 1 --> r || 2 --> d || 3 -->l
	while(!q.empty())
	{
		t = q.front();
		q.pop();
		if(t.x==n-1 && t.y==n-1)
		{
			printf("%d",mem[t.x][t.y][t.direc]);
			return 0;
		}
		if(check(t.x+dx[t.direc],t.y+dy[t.direc]) && tab[t.x+dx[t.direc]][t.y+dy[t.direc]] == 0 && !mem[t.x+dx[t.direc]][t.y+dy[t.direc]][t.direc])
		{
			q.push({t.x+dx[t.direc],t.y+dy[t.direc],t.direc});
			mem[t.x+dx[t.direc]][t.y+dy[t.direc]][t.direc] = mem[t.x][t.y][t.direc] +1;
		}
		else
		{
			for(i=0;i<4;i++)
			{
				if(check(t.x+dx[i],t.y+dy[i]) && tab[t.x+dx[i]][t.y+dy[i]] == 0 && !mem[t.x+dx[i]][t.y+dy[i]][i])
				{
					q.push({t.x+dx[i],t.y+dy[i],i});
					mem[t.x+dx[i]][t.y+dy[i]][i] = mem[t.x][t.y][t.direc] +1;
				}
			}

		}
	}
}
