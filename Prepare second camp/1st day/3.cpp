#include<stdio.h>
int a[1000];
int k;
int maxa;
int mina;
void max(int l,int r)
{
    int n=(l+r)/2;
    if(l-r==1)maxa=a[n];
    if(k>a[n])max(n+1,r);
    else max(l,n);
}
main()
{
    int n,i;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    //min(0,n-1);
    max(0,n-1);
    printf("%d",maxa);
}
