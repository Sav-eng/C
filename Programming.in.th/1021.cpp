#include<stdio.h>
#include<queue>
using namespace std;
priority_queue<int>x;
main()
{
    int n,i,t;
    char a;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf(" %c",&a);
        if(a=='P')
        {
            scanf("%d",&t);
            x.push(t);
        }
        else
        {
            if(x.empty())printf("-1\n");
            else
            {
                printf("%d\n",x.top());
                x.pop();
            }
        }
    }

}
