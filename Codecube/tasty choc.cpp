#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n;
int mem[1005][3005];
int a[1005];
int f(int x,int y)
{
	if(x==n)
	{
		return 0;
	}
	if(mem[x][y]) return mem[x][y];
	mem[x][y] = 10000;
	if(y+1<=3000) mem[x][y] = min(mem[x][y],f(x+1,y+1)+1);
	if(a[x]>y) mem[x][y] = min(mem[x][y],f(x+1,a[x]));
	return mem[x][y];
}
main()
{
	int i,j;
	//printf("%d",mem[10][10]);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("%d",f(0,0));
}
