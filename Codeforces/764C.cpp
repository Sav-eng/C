#include<stdio.h>
main()
{
    scanf("%d",&n);
    for(i=0;i<n-1;i++)
    {
        scanf("%d",&a,&b);
        from[a].push_back(b);
        eat[b] = 1;
    }
    for(i=0;i<n-1;i++)if(eat[i]==0)s = i;
    queue.push(s);
    while(!q.empty())
    {

    }
}
