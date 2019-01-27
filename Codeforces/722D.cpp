#include<bits/stdc++.h>
using namespace std;
set<int>S;
priority_queue<int>heap;
main()
{
    int n,i,a,t,t2;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        heap.push({a});
        S.insert(a);
    }
    while(!heap.empty())
    {
        t = heap.top(); heap.pop();
        t2 = t/2;
        while(S.find(t2)!=S.end() && t2!=0)t2 /=2;
        if(t2==0)
        {
            printf("%d ",t);
            while(!heap.empty())
            {
                t = heap.top(),heap.pop();
                printf("%d ",t);
            }
        }
        else
        {
            heap.push(t2);
            S.insert(t2);
        }
    }
}
