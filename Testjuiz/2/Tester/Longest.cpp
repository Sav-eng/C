#include<stdio.h>
#include<queue>
using namespace std;
struct node
{
    int x,val;
    node(int _x = 0,int _val = 0)
    {
        x = _x; val = _val;
    }
};
int n,k;
int p[1000005];
deque<node> a;
deque<node> b;
bool check(int x)
{
    int i;
    while(!a.empty()) a.pop_back();
    while(!b.empty()) b.pop_back();
    for(i=0;i<x;i++)
    {
        while(!a.empty() && a.back().val<p[i]) a.pop_back();
        while(!b.empty() && b.back().val>p[i]) b.pop_back();
        a.push_back(node(i,p[i]));
        b.push_back(node(i,p[i]));
    }
    if(a.front().val-b.front().val<=k) return true;
    for(i=x;i<n;i++)
    {
        while(a.front().x<=i-x) a.pop_front();
        while(b.front().x<=i-x) b.pop_front();
        while(!a.empty() && a.back().val<p[i]) a.pop_back();
        while(!b.empty() && b.back().val>p[i]) b.pop_back();
        a.push_back(node(i,p[i]));
        b.push_back(node(i,p[i]));
        if(a.front().val-b.front().val <= k) return true;
    }
    return false;
}
main()
{
    int time,i,l,ans,x,y;
    while(time--)
    {
        scanf("%d%d",&n,&k);
        for(i=0;i<n;i++) scanf("%d",&p[i]);
        while(!a.empty()) a.pop_back();
        while(!b.empty()) b.pop_back();
        l = -1; ans = 0;
        for(i=0;i<n;i++)
        {
            while(!a.empty() && a.front().x<=l) a.pop_front();
            while(!b.empty() && b.front().x<=l) b.pop_front();
            while(!a.empty() && a.back().val<=p[i]) a.pop_back();
            while(!b.empty() && b.back().val>=p[i]) b.pop_back();
            x = y = 0;
            if(a.empty()) x = 1;
            if(b.empty()) y = 1;
            a.push_back(node(i,p[i]));
            b.push_back(node(i,p[i]));
            if(x==y) continue;
            if(x==1)
            {
                while(b.front().val-a.front().val > k)
                {
                    l = max(l,b.front().x);
                    b.pop_front();
                }
            }
            if(y==1)
            {
                while(b.front().val-a.front().val > k)
                {
                    l = max(l,a.front().x);
                    a.pop_front();
                }
            }
            ans = max(ans,i-l);
        }
        printf("%d\n",ans);
    }
}
