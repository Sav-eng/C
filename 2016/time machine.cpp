#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<string.h>
#define inf 1e9
using namespace std;
int a[15];
int b[15];
int c[15];
int k;
int n;
int mem[5000][15];
int go[15][15];
int tsp(int x,int bit)
{
    if(x==k+1)return 0;
    else
    {
        int i;
        if(mem[bit][x]==0)
        {
            mem[bit][x] = inf;
            for(i=0;i<k+2;i++)
            {
                int check;
                check = (1<<i);
                if((check & bit)==0)
                {
                    //bit = bit|check;
                    mem[bit][x] = min(mem[bit][x],go[x][i]+tsp(i,bit|check));
                }
            }
            //printf("mem %d %d = %d\n",bit,x,mem[bit][x]);
        }
        return mem[bit][x];
    }
}
main()
{
    int m,i,ans,check,j;
    ans = INT_MAX;
    scanf("%d%d%d",&n,&m,&k);
    //memset(mem,conf,sizeof(mem));
    for(i=1;i<k+1;i++)
    {
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
    }
    a[0] = 0; b[0] = 0; c[0] = 0;
    a[k+1] = n-1; b[k+1] = m-1; c[k+1] = 0;
    for(i=0;i<k+2;i++)
    {
        for(j=0;j<k+2;j++)
        {
            go[i][j] = (int)ceil(sqrt(((a[i]-a[j])*(a[i]-a[j]))+((b[i]-b[j])*(b[i]-b[j]))))-c[j];
        }
    }
    printf("%d",tsp(0,1));
}
