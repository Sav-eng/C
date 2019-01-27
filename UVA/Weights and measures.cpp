#include"stdio.h"
bool cmp(node x,node y)
{
    if(x.b-x.a>y.b-y.a)return 0;
    if(x.b-x.a=y.b-y.a)
    {
        return x.a>y.b;
    }
}
main()
{
    while(scanf("%d%d",&node[i].a,node[i].b)!=EOF)
    {
        i++;
    }
    sort(&a[0],a[i],cmp);
}
