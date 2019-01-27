#include<bits/stdc++.h>
using namespace std;
int head[100005];
int findhead(int x)
{
    if(head[x]==x)return x;
    else return head[x] = findhead(head[x]);
}
main()
{
    int a,b,check=0,i,_max=0;
    for(i=0;i<=100000;i++) head[i] = i;
    while(scanf("%d",&a)!=EOF)
    {
        //scanf("%d",a);
        if(a!=-1)
        {
            scanf("%d",&b);
            _max = max(_max,b);
            if(findhead(a)==findhead(b))check++;
            else head[findhead(a)] = findhead(b);
            //printf("a = %d\n",a);
        }
        else if(a==-1)
        {
            printf("%d\n",check);
            check = 0;
            for(i=0;i<=_max;i++) head[i] = i;
            _max = 0;
        }
    }
}
