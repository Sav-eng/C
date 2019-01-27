#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define inf 1e9
int n,m;
int a[200005];
int mem[2][105];
int t1[105];
int t2[105];
main()
{
	int i,x,y,ans;
	bool flag;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&m);
	flag = 1;
	for(i=1;i<=100;i++) mem[0][i] = inf;
	for(i=a[1];i<=100;i++) mem[0][i] = (i-a[1])*(i-a[1]);
	for(i=2;i<=n;i++)
	{
		//Reset
		for(x=0;x<=101;x++) mem[flag][x] = t1[x] = t2[x] = inf;

		//Case1: x>=y
		for(x=1;x<=100;x++)
		{
			t1[x] = min(t1[x-1]+m,mem[!flag][x]);
			printf("t1[%d] = %d\n",x,t1[x]);
		}
		//Case2: x<y
		for(x=100;x>=1;x--)
		{
			t2[x] = min(t2[x+1]+m,mem[!flag][x]);
			if(t2[x]==mem[!flag][x])printf("At2[%d] = %d\n",x,t2[x]);
			else printf("Bt2[%d] = %d\n",x,t2[x]);
		}
		for(x=a[i];x<=100;x++)
		{
            mem[flag][x] = (x-a[i])*(x-a[i]) + min(t1[x],t2[x]);
            printf("mem[%d][%d] = %d\n",flag,x,mem[flag][x]);
		}
		printf("\n");
		flag = !flag;
	}
	ans = inf;
	for(i=a[n];i<=100;i++)
    {
        ans = min(ans,mem[!flag][i]);
        //printf("%d ",mem[!flag][i]);
    }
	printf("%d",ans);
}
