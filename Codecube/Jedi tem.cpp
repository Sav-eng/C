#include<stdio.h>
void swap(int *x,int*y)
{
    int t;
    t = *x;
    *x = *y;
    *y = t;
}
int x[10000];
int a[100000];
int b[100000];
main()
{
    int n,j,m,i,k,f,g;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%d",&x[i]);
    for(i=0;i<m;i++)scanf("%d%d",&a[i],&b[i]);
    for(i=0;i<m;i++)
    {
        for(j=a[i]-1;j<(a[i]+((b[i]+1)/2))-1;j++)
        {
            f =j;
            if(f>=n)f%=n;
            g = a[i]+b[i]-2-j+a[i]-1;
            if(g>=n)g%=n;
            swap(&x[f],&x[g]);
            //printf("%d %d\n",x[f],x[g]);
        }
    }
    for(k=0;k<n;k++)printf("%d ",x[k]);

}
/*
5 2
5 4 3 2 1
1 5
3 5
*/
