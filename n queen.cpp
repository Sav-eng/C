#include<stdio.h>
int tab[100]={};
int n;
int j;
int sum=0;
void f(int x)
{
	if(x==n)
	{
		int i;
		//for(i=0;i<n;i++)printf("tab[%d]=%d\n",i,tab[i]);
		sum++;
		return ;
	}
	int i,choose;
	for(i=0;i<n;i++)//check all tua
	{
		choose = 1;
		for(j=0;j<x;j++)//check place
		{
			if(tab[j]+j == x+i || tab[j]-j==i-x || tab[j]==i)
			{
				choose=0;
			}
		}
		if(choose)
		{
			//printf("A");
			tab[x] = i;
			f(x+1);
		}
	}
}
main()
{
	int i;
	scanf("%d",&n);
	f(0);
	printf("%d",sum);
}
