#include<bits/stdc++.h>
using namespace std;
string s,t;
unordered_map<string,int>check;
char a[100];
int tab[201];
int n;
void f(int x,int bit)
{
    if(x==n && check.find(t)==check.end())cout << t << endl,check[t]=1;
    else
    {
        int i;
        for(i=0;i<n;i++)
        {
            if(!((bit>>i)&1))
            {
                t+=s[i];
                f(x+1,bit|(1<<i));
                t.pop_back();
            }
        }
    }
}
main()
{
    int time,i;
    scanf("%d",&time);
    while(time--)
    {
        s.clear();
        t.clear();
        check.clear();
        memset(a,NULL,sizeof(a));
        scanf("%s",&a);
        n = strlen(a);
        for(i=0;i<n;i++)tab[a[i]]++;
        for(i='A';i<='Z';i++)
        {
            while(tab[i]>0)s+=i,tab[i]--;
            while(tab[i+'a'-'A']>0)s+=i+'a'-'A',tab[i+'a'-'A']--;
        }
        do
        {
            cout << s << endl;
        }while(next_permutation(s,s+n));
        //cout << s;
        //f(0,0);
    }
}
/*
3
aAb
abc
acba


*/
