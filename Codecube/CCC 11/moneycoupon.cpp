#include<bits/stdc++.h>
using namespace std;
main()
{
    bool check;
    int n,x,i;
    char c;
    long long sum=0,summinus=0,sumtime=1;
    scanf("%d",&n);
    check = 0;
    int tP = 0,tM = 0,tT = 0;
    for(i=0;i<n;i++)
    {
        scanf(" %c",&c);
        scanf("%d",&x);
        if(c=='+')
        {
            sum += x;
        }
        else if(c=='-')
        {
            summinus += x;
        }
        else
        {
            sumtime *= (x==0)?1:x;
            if(x==0)check++;
        }
    }
    if(check)summinus = 0;
    long long ans = sum*sumtime-summinus;
    printf("%lld",ans);


}
