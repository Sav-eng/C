#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,ind;
    bool operator <(node a)const
    {
        return a.x>x;
    }
};
main()
{
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        mem[i].x = a;
        mem[i].ind = i;
    }
    sort(mem,mem+n);
}
