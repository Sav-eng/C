/*#include<stdio.h>
#include<iostream>
#include<map>
#include<algorithm>
#include<string>
#define inf 1e9
using namespace std;
map<string,int>mp;
map<int,string>mp2;
string a,ans;
int mem[1005];
main()
{
    //freopen("notlast.in","r",stdin);
    //freopen("notlast.out","w",stdout);
    int n,cnt,i,b,_min=inf,_min2=inf,cont,ct=0;
    scanf("%d",&n);
    cnt=0;
    for(i=0;i<n;i++)
    {
        cin >> a;
        scanf("%d",&b);
        if(mp.find(a)==mp.end())
        {
            mp[a] = cnt;
            mp2[cnt] = a;
            cnt++;
        }
        mem[mp[a]] += b;
    }
    for(i=0;i<cnt;i++)
    {
        //printf("%d ",mem[i]);
        _min = min(_min,mem[i]);
        if(_min==mem[i])
        {
            ans = mp2[i];
        }
    }
    //printf("%d",cnt);
    cont = 0;
    for(i=0;i<7;i++)
    {
        if(_min==mem[i])
        {
            cont++;
        }
    }
    //printf("%d",cont);
    if(7==cont)
    {
        printf("Tie\n");return 0;
    }
    if(cnt!=7)
    {
        cout << ans << "\n";
        return 0;
    }
    //printf("%d",_min);
    for(i=0;i<cnt;i++)
    {
        if(mem[i]>_min)
        {
            _min2 = min(_min2,mem[i]);
            if(_min2==mem[i])ans = mp2[i];
            ct++;
        }
    }
    cont = 0;
    for(i=0;i<cnt;i++)
    {
        if(_min2==mem[i])
        {
            cont++;
        }
    }
    //printf("%d",cont);
    if(ct==cont)
    {
        printf("Tie\n");return 0;
    }
    cout << ans << "\n";
}*/
/*

1
a 2

*/
#include<stdio.h>
#include<iostream>
#include<map>
#include<algorithm>
#include<string>
#define inf 1e9
using namespace std;
map<string,int>mp;
map<int,string>mp2;
string a,ans;
int mem[1005];
main()
{
    freopen("notlast.in","r",stdin);
    freopen("notlast.out","w",stdout);
    int n,cnt,i,b,_min=inf,_min2=inf,ct=0;
    scanf("%d",&n);
    cnt=0;
    for(i=0;i<n;i++)
    {
        cin >> a;
        scanf("%d",&b);
        if(mp.find(a)==mp.end())
        {
            mp[a] = cnt;
            mp2[cnt] = a;
            cnt++;
        }
        mem[mp[a]] += b;
    }
    for(i=0;i<7;i++)
    {
        //printf("%d ",mem[i]);
        _min = min(_min,mem[i]);
    }
    cnt = 0;
    for(i=0;i<7;i++)
    {
        if(_min==mem[i])
        {
            cnt++;
        }
    }
    if(cnt==7)
    {
        printf("Tie\n");return 0;
    }
    //printf("%d",_min);
    for(i=0;i<7;i++)
    {
        if(mem[i]>_min)
        {
            _min2 = min(_min2,mem[i]);
            if(_min2==mem[i])ans = mp2[i];
            ct++;
        }
    }
    cnt = 0;
    for(i=0;i<7;i++)
    {
        if(mem[i]==_min2)
        {
            cnt++;
        }
    }
    if(cnt==ct && ct >1)
    {
        printf("Tie\n");
        return 0;
    }
    cout << ans << "\n";
}
