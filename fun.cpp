#include<stdio.h>
int n,m;
int f[500]={};
void func(int a,int i)
{
    int j,k,check;
    if(i>=m)
    {
        for(j=0;j<m;j++)
        {
            printf("%d ",f[j]);
        }
        printf("\n");
    }
    else
    {
        for(j=1;j<=n;j++)
        {
            check=1;
            if(j<=a)
            {
                check = 0;
            }
            if(check==1)
            {
                f[i] = j;
                func(j,i+1);
            }
        }
    }
}
main()
{
    scanf("%d %d",&n,&m);
    func(0,0);
}
