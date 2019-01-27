#include<stdio.h>
bool tab[1020][1020];
main()
{
	int n,m,a,b,x,y,z,u,j,k,i;
	int check;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		tab[a][b]=1;
	}
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		check=0;
		j=x-z;
		if(j<0)j=0;


		for(;j<=x+z;j++)
		{
			k=y-z;
			if(k<0)k=0;
			for(;k<=y+z;k++)
			{
				if(tab[j][k]==1)
				{
					check++;
					tab[j][k]=0;
				}
			}
		}
		printf("%d\n",check);
	}
}
