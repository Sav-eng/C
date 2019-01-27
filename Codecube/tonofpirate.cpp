#include<bits/stdc++.h>
#define MAXN 100002
using namespace std;
string s[3];
int mem[] = {0,1,2,1,2,1};
int a[MAXN];
int x[MAXN];
int y[MAXN];
int tab[2*MAXN];
int tree[2*MAXN];
map<int,int>mp;
int n;
int check;
void update(int x,int val)
{
    while(x<=check)
    {
        tree[x] +=val;
        x+=x&-x;
    }
}
int freq(int x)
{
    int sum=0;
    while(x>0)
    {
        sum+=tree[x];
        x-=x&-x;
    }
    return sum;
}
main()
{
    int T,m,i;
    s[0] = "sleep";
    s[1] = "eat";
    s[2] = "work";
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d",&a[i]);
        if(a[i])
        {
            scanf("%d%d",&x[i],&y[i]);
            tab[check++] = x[i];
            y[i]++;
            tab[check++] = y[i];
        }
        else
        {
            scanf("%d",&x[i]);
            tab[check++]=x[i];
        }
    }
    sort(&tab[0],&tab[check]);
    int cnt=1;
    for(i=0;i<check;i++)
    {
        if(mp.find(tab[i])==mp.end())
        {
            mp[tab[i]] = cnt++;
        }
    }
    for(i=0;i<m;i++)
    {
        if(a[i])
        {
            update(mp[x[i]],1);
            update(mp[y[i]],-1);
        }
        else
        {
            cout << s[mem[freq(mp[x[i]])%6]] << endl;
        }
    }

}
