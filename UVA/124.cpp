#include<bits/stdc++.h>
using namespace std;
string line;
string tab;
vector<vector<char> >from;
map<char,bool>vis;
bool cmp(char x,char y)
{
    return x<y;
}
int n;
bool check(char x)
{
    int i;
    for(i=0;i<from[x].size();i++)if(vis[from[x][i]])return false;
    return true;
}
void f(string ans)
{
    if(ans.size()==n)cout << ans << endl;
    else
    {
        int i;
        for(i=0;i<n;i++)
        {
            if(!vis[tab[i]])
            {
                vis[tab[i]] = 1;
                if(check(tab[i]))f(ans+tab[i]);
                vis[tab[i]] = 0;
            }
        }

    }
}
main()
{
    int T=0,i;
    while(1)
    {
        if(!getline(cin,line))break;
        if(T++)cout << endl;
        tab.clear();
        for(i=0;i<line.size();i+=2)tab +=line[i];
        n = tab.size();
        sort(tab.begin(),tab.end(),cmp);
        getline(cin,line);
        from.clear();
        from.resize(256);
        for(i=0;i<line.size();i+=4) from[line[i]].push_back(line[i+2]);
        f("");
    }
}
