#include<bits/stdc++.h>
#define MAXN 500002
using namespace std;
string s;
int next[MAXN];
int prev[MAXN];
int tab[MAXN];
int pos[MAXN];
main()
{
    int n,m,p;
    int i,t;
    scanf("%d%d%d",&n,&m,&p);
    cin >> s;
    s = '0'+s;
    next[0] = 1; prev[n+1] = n;
    t = 0;
    for(i=1;i<=n;i++)
    {
        next[i] = i+1;
        prev[i] = i-1;
        if(s[i]=='(')
        {
            tab[++t]=i;
        }
        else
        {
            pos[tab[t]] = i;
            pos[i]=tab[t];
            t--;
        }
    }
    char c;
    for(i=0;i<m;i++)
    {
        scanf(" %c",&c);
        if(c=='L')
        {
            p = prev[p];
            if(p==0)p++;
        }
        else if(c=='R')
        {
            p = next[p];
            if(p==n+1)p--;
        }
        else
        {
            int x,y;
            x = p; y = pos[p];
            if(x>y)swap(x,y);
            x = prev[x];
            y = next[y];
            next[x] = y;
            prev[y] = x;
            p = y;
            if(p==n+1)p = prev[p];
        }
    }
    t = 0;
    while(t<=n)
    {
        t = next[t];
        if(t<=n)printf("%c",s[t]);
    }
}
