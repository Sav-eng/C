#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x,y,time,check;
	node(int _x = 0,int _y  = 0,int _time = 0,int _check =0)
	{
	    x = _x; y = _y; time = _time; check = _check;
	}
};
int n,m;
int mem[205][205][7][130];
char a[205][205];
queue<node>q;
int cx[] = {0,0,1,-1};
int cy[] = {1,-1,0,0};
int mp[205][205];
int tab[130];
int tab2[130][10];
int nxt[10];
int p[10];
bool stay(int X,int Y,int gem)
{
    if(a[X][Y] >= '1' && a[X][Y] <='6')
    {
        if(gem>=a[X][Y]-'0')return 1;
        return 0;
    }
    return 1;
}
main()
{
	int i,j,cnt=0,temp;
	node s;
	scanf("%d%d",&n,&m);
	for(i=0;i<5;i++)nxt[i] = i+1;
	nxt[5]=0;
	p[0]=1;
	for(i=1;i<7;i++)p[i]=p[i-1]*2;
	for(i=0;i<(1<<7);i++)
	{
		for(j=0;j<7;j++)
		{
		    //printf("%d ",p[j]);
			if(i&p[j])tab[i]++;
			tab2[i][j] = i|p[j];
		}
	}
	for(i=0;i<n;i++)
	{
	    scanf(" %s",a[i]);
		for(j=0;j<m;j++)
		{
			if(a[i][j]=='S')s.x = i,s.y = j;
			if(a[i][j]=='G')mp[i][j] = cnt++;
		}
	}
	q.push(node(s.x,s.y,0,0));
	int have;
	node t;
	int X,Y,val;
	int x,y,time,check;
	while(!q.empty())
	{
		t = q.front(); q.pop();
		x= t.x; y=t.y; time=t.time; check=t.check;
		have = tab[check];
		if(have==7)
        {
            printf("%d",mem[x][y][time][check]);
            return 0;
        }
        val = mem[x][y][time][check]+1;
		if(!mem[x][y][nxt[time]][check])
        {
            if((a[x][y] >= '1' && a[x][y] <='6' && have>=a[x][y]-'0') || a[x][y]=='G' || a[x][y]=='.' || a[x][y]=='S')
            {
                mem[x][y][nxt[time]][check] = val;
                q.push(node(x,y,nxt[time],check));
            }

        }
		for(i=0;i<4;i++)
        {
            X = x+cx[i]; Y = y+cy[i];
            if(X>=0 && Y>=0 && X<n && Y<m && a[X][Y] !='#')
            {
                if(a[X][Y] =='.' || a[X][Y] == 'S')
                {
                    if(!mem[X][Y][nxt[time]][check])
                    {
                        mem[X][Y][nxt[time]][check] = val;
                        q.push(node(X,Y,nxt[time],check));
                    }
                }
                if(a[X][Y] >='1' && a[X][Y] <= '6')
                {
                    if(nxt[time] == a[X][Y]-'1' || have>=a[X][Y]-'0')
                    {
                        if(!mem[X][Y][nxt[time]][check])
                        {
                            mem[X][Y][nxt[time]][check] = val;
                            q.push(node(X,Y,nxt[time],check));
                        }
                    }
                }
                if(a[X][Y] == 'G')
                {
                    if(!mem[X][Y][nxt[time]][tab2[check][mp[X][Y]]])
                    {
                        mem[X][Y][nxt[time]][tab2[check][mp[X][Y]]] = val;
                        q.push(node(X,Y,nxt[time],tab2[check][mp[X][Y]]));
                    }
                }
            }

        }
		//printf("mem[%d][%d][%d][%d] = %d\n",x,y,time,check,mem[x][y][time][check]);
	}
	printf("-1");
}
/*
2 6
S##GGG
G6GG.G

2 6
S#GGGG
.61GGG
*/
