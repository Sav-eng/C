#include<stdio.h>
int arr[1000][1000];
int a,b;
int mem[1000][1000];
int max(int x,int y)
{
    if(x>y) return x;
    return y;
}
int fm(int i,int j)
{
    if(i>=a || j < 0 || j >=b)return 0;
    else
    {
        if(mem[i][j]==0)
        {
            mem[i][j]= max(fm(i+1,j),max(fm(i+1,j+1),fm(i+1,j-1)))+arr[i][j];
        }
        return mem[i][j];
    }
}
main()
{
    int n,i,j,k,jj,ans=0;
    scanf("%d",&n);
    for(k=0;k<n;k++)
    {
        ans = 0;
        scanf("%d %d",&a,&b);
         for(i=0;i<a;i++)
        {
            for(j=0;j<b;j++)
            {
                scanf("%d",&arr[i][j]);
                mem[i][j]=0;
            }
        }
        for(j=0;j<b;j++)
        {
           ans = max(ans,fm(0,j));
        }
        printf("%d ",ans);
    }
}
