#include<bits/stdc++.h>
using namespace std;
queue<int>q;
int tab[101];
main()
{
    int n,k,i,a,t,check,j,t2;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)q.push(i);
    for(i=1;i<=k;i++)
    {
        scanf("%d",&a);
        tab[i] = a;
    }
    check=1;
    for(j=1;j<=k;j++)
    {
            t = q.front();
            t2 = tab[j]%(n-j+1);
            //printf("t2 = %d",t2);
            for(i=0;i<t2;i++)
            {
                //printf("%d ",q.front());
                q.push(q.front());q.pop();
            }
            check++;
            printf("%d ",q.front());
            q.pop();
    }
}
