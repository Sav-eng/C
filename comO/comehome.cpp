#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
map<char,vector< pair<char,int> > >from;
map<char,int>mem;
priority_queue<pair<char,int> >heap;
main()
{
    int n,a,b,val,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf(" %c %c%d",&a,&b,&val);
        //printf("%c---%c\n",a,b);
        from[a].push_back({b,-val});
        from[b].push_back({a,-val});
    }
    pair<char,int>t,ans={0,-inf};
    heap.push({'Z',0});
    while(!heap.empty())
    {
        t = heap.top(); heap.pop();
        if(t.first >= 'A' && t.first <= 'Z' && t.first != 'Z')
        {
            if(t.second>ans.second)
            {
                ans.second = t.second;
                ans.first =  t.first;
            }
        }
        for(i=0;i<from[t.first].size();i++)
        {
            if(mem.find(from[t.first][i].first)==mem.end())mem[from[t.first][i].first] = inf;
            if(mem[from[t.first][i].first] > -t.second-from[t.first][i].second)
            {
                mem[from[t.first][i].first] = -t.second-from[t.first][i].second;
                heap.push({from[t.first][i].first,-mem[from[t.first][i].first]});
            }
        }
        //printf("mem[%c] = %d\n",t.first,-t.second);
    }
    printf("%c %d",ans.first,-ans.second);
}
