#include<stdio.h>
#include<queue>
using namespace std;
struct node
{
    long long vn,vo;
    bool operator < (node a)const
    {
        return a.vn<vn;
    }
    node(int _vn=0,int _vo=0)
    {
        vn = _vn;
        vo = _vo;
    }
};
node a;
node t;
priority_queue<node>heap;
main()
{
    int m,n,i;

    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++)
    {
        scanf("%d",&a.vn);
        a.vo = a.vn;
        heap.push(a);
    }
    for(i=0;i<n;i++)
    {
        t = heap.top();
        heap.pop();
        heap.push(node(t.vn+t.vo,t.vo));
    }
    printf("%lld",t.vn);
}
