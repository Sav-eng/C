#include<stdio.h>
#include<algorithm>
#include<limits.h>
using namespace std;
int a[1000050];
int b[1000050];
int c[1000050];
//bool cmode[10000050];
bool mode;
main()
{
    int n,i,_max,check,checkans;
    scanf("%d",&n);
    _max = INT_MIN;
    mode =0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        _max = max(_max,a[i]);
        b[i] = _max;
    }
    for(i=0;i<n;i++)
    {
        c[i] = b[i]-a[i];
    }
    for(i=n-1;i>0;i--)
    {
        if(c[i]==0)
        {
            if(b[i-1]==_max)
            {
                mode = 1;
                a[i] = _max;
                check = c[i];
                checkans = a[i];
            }
            else a[i] = a[i-1];
        }
        else if(c[i]>c[i-1])
        {
            a[i] = b[i]-c[i];
        }
        else if(c[i]<c[i-1] && !mode)
        {
            mode = 1;
            check = c[i];
            a[i] = b[i]-c[i];
            checkans = a[i];
        }
        //printf("a");
        if(mode)
        {
            if(check<c[i])a[i] = checkans;
            else mode = 0;
        }
        //cmode[i]=mode;
    }
    /*for(i=0;i<n;i++)
    {
        printf("%d ",cmode[i]);
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",b[i]);
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",c[i]);
    }
    printf("\n");*/
    for(i=1;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
/*
5
1 4 0 5 5
*/
