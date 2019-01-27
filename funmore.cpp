#include<stdio.h>
int n,m;
int f[5000]={};
int cc = 0;
int ans[5000] = {};
void func(int a,int i)
{
    int j,k,check;
    if(i>=m)
    {
        for(j=0;j<m;j++)
        {
            ans[cc]*=10;
            ans[cc]+=f[j];

        }
        cc++;
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
    int nn,k,a[50000];
    n = 9;
    for(m=1;m<10;m++)
    func(0,0);
    scanf("%d",&nn);
    for(k=0;k<nn;k++)
    {
        scanf("%d",&a[k]);
    }
    for(k=0;k<nn;k++)
    {
        if(a[k]>510)printf("-1");
        else printf("%d\n",ans[a[k]-1]);
    }


}
