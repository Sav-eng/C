#include<stdio.h>
int a[10000];
int mem[1000][1000] = {};
int n,k;
int min = 99999;
int sum(int i,int j)
{
    int suma;
    for(i=i;i<j;i++)
    {
        suma+=a[i];
    }
    return suma;
}
int f(int x,int y)
{
    if(x==n || y == k)return 0;
    else
    {
        int i,j;
        for(i=0;i<n;i++)
        {
            for(j=0;j<k;j++)
            {
                mem[i][j] = f(i,j) + a[i];
            }
        }

    }
}
main()
{
    int i;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    f(0,0);
    printf("%d",min);
}
