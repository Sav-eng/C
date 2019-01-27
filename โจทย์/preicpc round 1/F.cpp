#include<bits/stdc++.h>
using namespace std;
map<int,string>mp;
map<string,int>mp2;
string s;
main()
{
    int n;
    mp[0] = "JAN";mp[1] = "FEB"; mp[2] = "MAR"; mp[3] = "APR"; mp[4]  ="MAY"; mp[5] = "JUN";
    mp[6] ="JUL"; mp[7] = "AUG"; mp[8] = "SEP"; mp[9] = "OCT"; mp[10] = "NOV"; mp[11] = "DEC";
    mp2["JAN"] = 0; mp2["FEB"] = 1; mp2["MAR"] = 2; mp2["APR"] = 3; mp2["MAY"] = 4; mp2["JUN"] = 5;
    mp2["JUL"]= 6;mp2["AUG"] = 7; mp2["SEP"] = 8; mp2["OCT"] = 9; mp2["NOV"] = 10; mp2["DEC"]=11;
    cin >> s;
    scanf("%d",&n);
    int x;
    if(n>=0)x=n%12;
    else x = 12-(-n%12);
    cout << mp[(mp2[s]+x)%12];

}
