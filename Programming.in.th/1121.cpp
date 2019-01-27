#include<bits/stdc++.h>
using namespace std;
char s[1000002];
stack<char>ST;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T,i,n;
    cin >> T;
    while(T--)
    {
        cin >> s;
        n = strlen(s);
        for(i=0;i<n;i++)
        {
            if(s[i]=='[' || s[i] == '{' || s[i] == '(')ST.push(s[i]);
            else
            {
                if(!ST.empty())
                {
                    if( (ST.top()=='[' && s[i] == ']') || (ST.top()== '{' && s[i] == '}') || (ST.top()== '(' && s[i] == ')') )ST.pop();
                    else ST.push(s[i]);
                }
                else ST.push(s[i]);
            }
        }
        if(!ST.empty())
        {
            cout << "no" << endl;
            while(!ST.empty())ST.pop();
        }
        else cout << "yes" << endl;
    }
}
/*

5
(([[[[]]]]{[[]]}))[{({})}]
([[[[]]]]{[[]]})[{({})}]
(([[]]{[[]]}))[{({})}]
(([[[[]]{[[]]}))[{({})}]
(([[[[]]]]{[]}))[{({})}]





*/
