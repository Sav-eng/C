#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;
priority_queue<int>heap;
vector<int>from[2005];
main()
{
    int n,i,j,x;
    int t=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&x);
            from[i+j].push_back(x);
        }
    }
    for(i=(2*n)-2;i>0;i--)
    {
        for(j=0;j<from[i].size();j++)
        {
            heap.push(from[i][j]);
        }
        t += heap.top();
        heap.pop();
    }
    printf("%d",t);

}
