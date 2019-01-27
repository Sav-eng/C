#include<bits/stdc++.h>
using namespace std;
queue<int>q;
main()
{
    int n,m,i,check;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)q.push(i+1);
    check=0;
    while(!q.empty())
    {
        check++;
        if(check==m){check=0;printf("%d ",q.front());}
        else q.push(q.front());
        q.pop();
    }
}
