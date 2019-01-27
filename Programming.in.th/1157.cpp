#include<stdio.h>
#include<queue>
using namespace std;
struct node
{
    int val,ind;
    bool operator < (node a)const
    {
        return a.val<val;
    }
};
priority_queue<node>heap;
node t;
int a[500005];
main()
{
    int n,k,i,ans;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    //heap.push({a[0],0});
    for(i=0;i<n;i++)
    {
        if(heap.empty())
        {
            heap.push({a[i],i});
            continue;
        }
        t = heap.top();
        while(i-t.ind>k)
        {
            heap.pop();
            t = heap.top();
        }
        heap.push(t);
        heap.push({t.val+a[i],i});
        if(i==n-1)ans = t.val+a[i];
        //printf("%d ",t.val+a[i]);
    }
    printf("%d",ans);
}
