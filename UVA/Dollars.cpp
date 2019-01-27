#include<stdio.h>
#include<string.h>
int coin[]={10000,5000,2000,1000,500,200,100,50,20,10,5};
long long mem[30005][15];
long long ton(int x,int s)
{
    int i,temp=0;
    //if(x%5!=0)return 0;
    if(x==0)return 1;
    if(x<0 || s>=11)return 0;
    if(mem[x][s]!=0)return mem[x][s];
    mem[x][s] = ton(x,s+1);
	if(x-coin[s]>=0)
	{
		mem[x][s] += ton(x-coin[s],s);
    }
	//printf("mem[%d] = %d s= %d\n",x,mem[x],s);
    return mem[x][s];
}
main()
{
    double n;
    while(scanf("%lf",&n)!=EOF && n!=0)
    {
    	n*=100;
        //memset(mem,0,sizeof(mem));
        printf("%6.2lf%17lld\n",n/100,ton((int)n,0));
    }
}
