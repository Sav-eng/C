#include<stdio.h>
int a[1000005];
int parent(int x)
{
    return x/2;
}
void swap(int *x,int *y)
{
    int t;
    t = *x;
    *x = *y;
    *y = t;
}
int left(int x)
{
    return x*2;
}
int right(int x)
{
    return x*2+1;
}
void perup(int i)
{
    if(i==1) return;
    if(a[i]>a[parent(i)])
    {
        swap(&a[i],&a[parent(i)]);
        perup(parent(i));
    }
}
void perdown(int i)
{
    if(a[i]>=a[left(i)] && a[i]>=a[right(i)]) return;
    if( a[left(i)] >= a[right(i)] )
    {
        swap(&a[i],&a[left(i)]);
        perdown(left(i));
    }
    else if (a[right(i)] > a[left(i)])
    {
        swap(&a[i],&a[right(i)]);
        perdown(right(i));
    }
}
main()
{
    int i,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        perup(i);
    }
    for(i=n;i>=1;i--)
    {
        printf("%d",a[1]);
        a[1] = 0;
        swap(&a[1],&a[i]);
        perdown(1);
    }
}
