#include<bits/stdc++.h>
#define mod 8
using namespace std;
string x;
string Template = "codecube";
main()
{
    int p=0;
    int ans = 0,i;
    cin >> x;
    int n = x.size();
    for(i=0;i<n;i++)
    {
        while(x[i]!=Template[p%8])
        {
            ans++;
            p++;
        }
        p++;
    }
    p%=8;
    p = (p==0)?8:p;
    while(p<8)p++,ans++;
    printf("%d",ans);
}
