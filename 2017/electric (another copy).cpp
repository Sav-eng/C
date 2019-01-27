#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,ind;
    bool operator <(node a)const
    {
        return a.x<x;
    }
};
priority_queue<node>heap;
int a[500001];
int mem[500001];
main()
{
    int n,m,i,k;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        if(heap.empty())
        {
            mem[i] = a[i];
        }
        else
        {
            while(i-heap.top().ind>k)heap.pop();
            mem[i] = heap.top().x+a[i];
        }
        heap.push({mem[i],i});
    }
    printf("%d",mem[n-1]);
}

