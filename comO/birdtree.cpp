#include<bits/stdc++.h>
using namespace std;
string ans;
void f(int x,int y)
{
    if(x==1 && y==1)return ;
    else
    {
        //printf("%d %d\n",x,y);
        if(x>y)
        {
            ans += 'R';
            f(y,x-y);
        }
        else
        {
            ans += 'L';
            f(y-x,x);
        }

    }
}
main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int T;
    cin >> T;
    int a,b;
    while(T--)
    {
        ans.clear();
        char c;
        //cin >> a >> c >>b;
        cin >> a;
        cin.ignore();
        cin >> b;
        //cout << a << b;
        f(a,b);
        cout << ans << endl;
    }
}
