#include<bits/stdc++.h>
using namespace std;
int mem[1002][2500];
int n,k,m;
int a[1002];
int f(int x,int bit)
{
    if(x==n)return 0;
    else if(!mem[x][bit])
    {
        int i,check=0;
        mem[x][bit] = f(x+1,bit>>1);
        for(i=0;i<m;i++)if((bit&(1<<i))!=0)check++;
        if(check<k)mem[x][bit] = max(mem[x][bit],f(x+1,((bit>>1)|(1<<(m-2))))+a[x]);
        //printf("mem[%d][%d] = %d\n",x,bit,mem[x][bit]);
    }
    return mem[x][bit];
}
int main()
{
    int i;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        printf("i = %d\n",i);
    }
    printf("%d",f(0,0));
}
