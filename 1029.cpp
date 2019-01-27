#include<stdio.h>
#include<algorithm>
using namespace std;
int table[500005];
bool cmp(int x,int y)
{
    if(x<y) return 1;
    return 0;
}
int deleted(int m)
{
    int i,x = m;
    for(i = 0;i < m;i++)
    {
        if(table[i] == table[i+1])
        {
            table[i] = 2147483646;
            table[i+1] = 2147483646;
            x -= 2;
        }
    }
    return x;
}
main()
{
    int i,n,m,k,want,mid,l,r,a,b,t;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&a,&b);
        table[i*2] = a;
        table[i*2+1] = a+b;
    }
    m*=2;
    sort(&table[0],&table[m],cmp);
    t = deleted(m);
    sort(&table[0],&table[m],cmp);
    m = t;
    for(i=0;i<k;i++)
    {
        scanf("%d",&want);
        if(want<table[0])
        {
            printf("%d\n",table[0]-1);
        }
        else if(want>=table[m-1])
        {
            printf("%d\n",n-table[m-1]+1);
        }
        else
        {
            //r = bsearch(0,m-1,want);
            l = 0;
            r = m;
            while(l<r)
            {
                mid = (l+r)/2;
                if(table[mid]<want)
                {
                    l= mid+1;
                }
                else r = mid;
            }
            if(table[r]>want) r--;
            printf("%d\n",table[r+1]-table[r]);
        }
    }
}
