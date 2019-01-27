#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x,y,day;
};
char tab[301][301];
int mem[301][301][5];
bool attack[301][301][5][10];
bool tack[301][301][5];
int cx[]={0,1,0,-1};
int cy[]={1,0,-1,0};
int dx[]={-1,-1,0,1,1,1,0,-1};
int dy[]={0,1,1,1,0,-1,-1,-1};
queue<node>q;
node a[100001];
node e,s,t;
int n,m;
int check(int x,int y)
{
	if(x>=0 && x<n && y>=0 && y<m)return true;
	return false;
}
main()
{
	int i,j,k;
	int check2=0;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf(" %c",&tab[i][j]);
			if(tab[i][j] =='S')
			{
				s.x = i;s.y = j;
			}
			else if(tab[i][j] == 'E')
			{
				e.x = i;e.y = j;
			}
			else if(tab[i][j]=='|' || tab[i][j] == '/' || tab[i][j] == '\\' || tab[i][j] == '-')
			{
				a[check2].x=i;
				a[check2++].y=j;
			}
		}
	}
	int start,x,y;
	for(k=0;k<check2;k++)
	{
		if(tab[a[k].x][a[k].y]=='|')start=0;
		else if(tab[a[k].x][a[k].y]=='/')start=1;
		else if(tab[a[k].x][a[k].y]=='-')start=2;
		else if(tab[a[k].x][a[k].y]=='\\')start=3;
        x = a[k].x; y = a[k].y;
        for(i=0;i<4;i++)
        {
            j=1;
            while(tab[x+dx[(start+i)%8]*j][y+dy[(start+i)%8]*j]=='.' && !attack[x+dx[(start+i)%8]*j][y+dy[(start+i)%8]*j][i][(start+i)%8])
            {
                attack[x+dx[(start+i)%8]*j][y+dy[(start+i)%8]*j][i][(start+i)%8] = true;
                tack[x+dx[(start+i)%8]*j][y+dy[(start+i)%8]*j][i] = true;
                j++;
            }
            j=1;
            while(tab[x+dx[(start+i+4)%8]*j][y+dy[(start+i+4)%8]*j]=='.' && !attack[x+dx[(start+i+4)%8]*j][y+dy[(start+i+4)%8]*j][i][(start+i)%8])
            {
                attack[x+dx[(start+i+4)%8]*j][y+dy[(start+i+4)%8]*j][i][(start+i)%8] = true;
                tack[x+dx[(start+i+4)%8]*j][y+dy[(start+i+4)%8]*j][i] = true;
                j++;
            }
        }
	}
	bool check5=1;
	s.day = 0;
	q.push(s);
	while(!q.empty())
	{
		t = q.front();q.pop();
		if(t.x==e.x && t.y==e.y)
		{
			printf("%d",mem[t.x][t.y][t.day]);
			check5=0;
			break;
		}
		for(i=0;i<4;i++)
		{
			if(check(t.x+cx[i],t.y+cy[i]) && !mem[t.x+cx[i]][t.y+cy[i]][(t.day+1)%4] && (tab[t.x+cx[i]][t.y+cy[i]]=='.' ||tab[t.x+cx[i]][t.y+cy[i]]=='S'||tab[t.x+cx[i]][t.y+cy[i]]=='E')&& !tack[t.x+cx[i]][t.y+cy[i]][(t.day+1)%4])
			{
				mem[t.x+cx[i]][t.y+cy[i]][(t.day+1)%4]=mem[t.x][t.y][t.day]+1;
				q.push({t.x+cx[i],t.y+cy[i],(t.day+1)%4});
			}
		}
		//printf("mem[%d][%d][%d] = %d\n",t.x,t.y,t.day,mem[t.x][t.y][t.day]);
	}
	if(check5)printf("-1");

}
