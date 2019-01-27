#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
struct node
{
    int weight,value,time;
    bool operator <(node a)const
    {
        return a.weight<weight;
    }
};
struct node2
{
    int time,weight,value;
    bool operator <(node2 a)const
    {
        return a.time<time;
    }
};
priority_queue<node>heap;
priority_queue<node2>heap2;
main()
{
    int i,n,m,operation,operation2,weight,weight2,time,value;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n+m;i++)
    {
        scanf("%d",&operation);
        switch(operation)
        {
        case 1:
            scanf("%d",&operation2);
            scanf("%d%d",&weight,&value);
            switch(operation2)
            {
            case 1:
                heap.push({weight,value,inf});
                break;
            case 2:
                scanf("%d",&time);
                heap.push({weight,value,time});
                break;
            case 3:
                scanf("%d%d",&time,&weight2);
                heap.push({weight,value,time});
                heap2.push({time,weight2,value});
                break;
            }
            break;
        case 2:
            if(heap.empty())
            {
                printf("\t0\n");
                continue;
            }
            while(!heap2.empty() && heap2.top().time<=i)
            {
                node2 t2 = heap2.top();
                heap.push({t2.weight,t2.value,inf});
                heap2.pop();
            }
            node t = heap.top();
            while(t.time<=i)
            {
                heap.pop();
                if(!heap.empty())t = heap.top();
                else break;
            }
            if(!heap.empty())printf("\t%d\n",t.value);
            else printf("0\n");
            heap.pop();
            break;
        }
    }
}
/*

5 4
1 3 10 20 3 1
1 3 30 10 3 5
2
2
1 3 40 20 7 5
1 1 30 30
1 2 25 50 7
2
2

*/
