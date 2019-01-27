#include<stdio.h>
int a[1000],b[1000];
void merge(int l,int r)
{
    int n=(l+r)/2;
    int j = n+1,k=l,i=l;
    while(i<=n && j <=r)
    {
        if(a[i]<a[j])b[k++]=a[i++];
        else b[k++]=a[j++];
    }
    while(i<=n)b[k++]=a[i++];
    while(j <=r)b[k++]=a[j++];
    for(i=l;i<=r;i++)a[i]=b[i];
}
void mergesort(int i,int j)
{
    if(j==i)return;
    int n;
    n = (i+j)/2;
    mergesort(i,n);
    mergesort(n+1,j);
    merge(i,j);
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
        printf("%d",a[i]);
    }
}
