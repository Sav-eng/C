#include<stdio.h>
#include<algorithm>
#include<string.h>
#define inf 1e9
using namespace std;
int mem[20005][2];
int b[20005];
int a[20005];
int m,k;
/*int f(int x,int y)
{

    // x cut off // y people //
    if((x==m+1 && y <k) || (x<m+1 && y==k))return -inf;
    else if(x==m+1 && y==k)return 0;
    else
    {
        int i;
        if(mem[x][y]!=0)return mem[x][y];
        mem[x][y] = max(f(x+1,y),f(x+1,y+1)) + b[y]*(a[x+1]-a[x]);
        //printf("mem[%d][%d]=  %d\n",x,y,mem[x][y]);
        return mem[x][y];
    }
}*/
main()
{
    int i,n,j,x,y,ans=0;
    bool flag;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=m;i++)
    {
        scanf("%d",&a[i]);
    }
    a[m+1] = n;
    for(i=0;i<k;i++)
    {
        scanf("%d",&b[i]);
    }
    for(y=0;y<k;y++)
    {
        for(x=1;x<=m+1;x++)
        {
            mem[x][flag] = 0;
            if(x-1<y)continue;
            mem[x][flag] = max(mem[x-1][flag],mem[x-1][!flag]) + b[y]*(a[x]-a[x-1]);
        }
        flag = !flag;
    }
    printf("%d",mem[x-1][!flag]);

}
/*

10 5 3
1 3 5 8 9
4 2 2

36

10 5 3
2 4 6 8 9
4 3 9

68

*/
