#include<stdio.h>
int a[1000],b[1000];
void merge(int l,int r)
{
    int n=(l+r)/2;
    int i=l,k=l,j=n+1;
    while(i<=n && j <= r)
    {
        if(a[i]>a[j])b[k++]=a[j++];
        else b[k++]=a[i++];
    }
    while(i<=n)b[k++]=a[i++];
    while(j<=r)b[k++]=a[j++];
    for(i=l;i<=r;i++)a[i]=b[i];
}
void mergesort(int l,int r)
{
    int n=(l+r)/2;
    if(l==r)return;
    mergesort(l,n);
    mergesort(n+1,r);
    merge(l,r);
}
main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    mergesort(0,n-1);
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
