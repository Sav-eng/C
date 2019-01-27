#include<stdio.h>
#include<queue>
using namespace std;
queue<int>x;
main()
{
    int i,n,k;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)x.push(i);
    i=1;
    int t;
    while(!x.empty())
    {
        if(i==k)
        {
            printf("%d\n",x.front());
            x.pop();
            i=1;
        }
        else
        {
            t = x.front();
            x.pop();
            x.push(t);
            i++;
        }
    }
}
