#include<stdio.h>
#include<algorithm>
using namespace std;
main()
{
int n,p,i,mina=10000000,maxa=-10000000;
int a,b;
	scanf("%d %d",&n,&p);
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&a,&b);
		if(a>b)swap(a,b);
		if(mina>b)mina = b;
		if(maxa<a)maxa = a;
	}
	if(mina-maxa<0)printf("-1");
	else printf("%d",max(p-mina,maxa-p));
}
