#include<stdio.h>
int power(int n,int m)
{
    int ans = 1,i;
    for(i=0;i<m;i++)
    {
        ans = ans * n;
    }
    return ans;
}
main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    printf("%d",power(n,m));
}
