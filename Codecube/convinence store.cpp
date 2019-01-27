#include<stdio.h>
#define mod 1000007
#include<algorithm>
using namespace std;
int n,k;
int mem[3][50005];
int a[505];
int f(int x,int y)
{
    if(x==n && (y > k || y < k))return 0;
    else if(x==n && y==k)return 1;
    else
    {
        int i;
        if(mem[x][y]!=0)return mem[x][y];
        mem[x][y] = f(x+1,y+a[x])+f(x+1,y);
        return mem[x][y];
    }
}
bool flag;
main()
{
    int i,j;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    mem[0][k] = 1;
    flag = 1;
    for(i=n-1;i>=0;i--)
    {
        for(j=k;j>=0;j--)
        {
            mem[flag][j] = (mem[!flag][j+a[i]]+mem[!flag][j]+mod)%mod;
            //printf("%d ",mem[i][j]);
        }
        flag = !flag;
        //printf("\n");
    }
    //printf("%d\n",f(0,0));
    printf("%d",mem[!flag][0]);

}
