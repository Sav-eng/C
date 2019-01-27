#include<bits/stdc++.h>
using namespace std;
bool hole[1000001];
main()
{
    int n,m,k,a,x,y,now,i;
    bool check=0;
    now = 1;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<m;i++){scanf("%d",&a);hole[a] = 1;}
    for(i=0;i<k;i++)
    {
        scanf("%d%d",&x,&y);
        if(hole[now]==1)check=1;
        if(now==x && !check)now = y;
        else if(now==y && !check)now = x;
    }
    printf("%d",now);
}
