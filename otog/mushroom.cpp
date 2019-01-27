#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
priority_queue<int>heap;
main()
{
    int n,i,j,a,x,y,m;
    long long l,h;
    double len;
    scanf("%d%lld%lld",&n,&l,&h);
    for(i=0;i<n;i++)
    {
        scanf("%d",&m);
        for(j=0;j<m;j++)
        {
            scanf("%d",&a);
            heap.push(a);
        }
        scanf("%d%d",&x,&y);
        double t = (double)h*x;
        len = max((t/y)+l,(double)0);
        while(!heap.empty() && heap.top()>=len)heap.pop();
        printf("%d\n",heap.size());
    }
}
/*

3 1000000000 1000000
0 -1 2
2 11 12 1 1
5 4 4 4 4 4 -1000000000 1000000

*/
