#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,y;
};
node a[1000001];
bool cmp(node x,node y)
{
    if(x.x==y.x)
    {
        return x.y<y.y;
    }
    else return y.x<x.x;
}
main()
{
    int n,i,range;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&a[i].x,&a[i].y);
    }
    sort(&a[0],&a[n],cmp);
    range = 0;
    for(i=0;i<n;i++)
    {
        if(range<=a[i].y)
        {
            printf("%d %d\n",a[i].x,a[i].y);
            range = a[i].y;
        }
    }
}


