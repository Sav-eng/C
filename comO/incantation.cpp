#include<bits/stdc++.h>
using namespace std;
int mem[10001][300];
int a[1001];
int n,m;
int f(int x,int bit)
{
    if(x==n)return 0;
    else if(!mem[x][bit])
    {
        if(x<m-1)
        {
            mem[x][bit] = max(f(x+1,bit<<1|1),f(x+1,bit<<1));
        }
        else
        {
            mem[x][bit] = a[bit];
            int nbit =  bit-(1<<(m-1)&bit);
            mem[x][bit] += max(f(x+1,nbit<<1|1),f(x+1,nbit<<1));
        }
        //printf("mem[%d][%d]= %d\n",x,bit,mem[x][bit]);
    }
    return mem[x][bit];
}
main()
{
    int i;
    scanf("%d%d",&n,&m);
    for(i=0;i<1<<m;i++)
    {
        scanf("%d",&a[i]);//in mean 0 ort mean 1
    }
    printf("%d",max(f(0,0),f(0,1)));
}
/*

12 3
1
5
4
1
4
3
7
5




*/
