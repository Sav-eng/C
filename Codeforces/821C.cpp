#include<bits/stdc++.h>
using namespace std;
stack<int>ST;
int ans = 0;
main()
{
    int n,i,a,j,t=1;
    string s;
    scanf("%d",&n);
    for(i=0;i<2*n;i++)
    {
        cin >> s;
        if(s=="remove")
        {
            if(!ST.empty())
            {
                if(ST.top()==t)ST.pop();
                else
                {
                    while(!ST.empty())ST.pop();
                    ans++;
                }
            }
            t++;
        }
        else
        {
            scanf("%d",&a);
            ST.push(a);
        }
    }
    printf("%d",ans);
}

