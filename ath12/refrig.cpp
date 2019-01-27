#include<bits/stdc++.h>
using namespace std;
struct node
{
    int val;
    bool operator <(node a)const
    {
        return a.val<val;
    }
};
priority_queue<node>heap;
main()
{
    int T,n,i,a;
    scanf("%d",&T);
    while(T--)
    {
        while(!heap.empty())heap.pop();
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a);
            heap.push({a});
        }
        int Time = 0;
        while(!heap.empty())
        {
            node t = heap.top(); heap.pop();
            if(t.val-Time<=0)
            {
                printf("%d\n",Time);
                break;
            }
            else heap.push({t.val+1});
            Time++;
        }
    }
}
/*

3
2
3 2
4
4 4 4 100
3
4 4 4

*/
