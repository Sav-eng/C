#include<bits/stdc++.h>
using namespace std;
bool palinword(string s)
{
    int mem[256][256];
    int n = s.size(),l,r;
    int i,len,j;
    for(i=0;i<n-1;i++)mem[i][i+1] = (s[i]==s[i+1])?1:0;
    for(i=0;i<n;i++)mem[i][i] = 1;
    string t;
    for(len = 2;len<n;len++)
    {
        for(i=0;i+len<n;i++)
        {
            j = i+len;
            if(s[i]==s[j] && mem[i+1][j-1])
            {
                mem[i][j] = 1;
                //printf("%d--%d\n",i,j);
                if(t == "")
                {
                    //printf("%d--%d\n",i,j);
                    t = s.substr(i,len+1);
                    r = i;
                    l = j;
                }
                else if(i>r || j<l)
                {
                    if(s.substr(i,len+1).find(t)==string::npos)return 1;
                }
            }
            else mem[i][j] = 0;
        }
    }
    return 0;
}
main()
{
    string s;
    while(cin >> s)
    {
        if(palinword(s))cout << s << endl;
    }
}
