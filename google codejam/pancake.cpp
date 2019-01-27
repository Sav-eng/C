#include<bits/stdc++.h>
using namespace std;
string x;
string s,t,t2;
queue<string>q;
map<string,int>mem;
string a;
main()
{
    //freopen("A-small-attempt3.in","r",stdin);
    //freopen("Asmall3.txt","w",stdout);
    int n,m,time,pos,i,j,check=0,check2;
    scanf("%d",&time);
    getline(cin,a);
    while(time--)
    {
        mem.clear();
        getline(cin,a);
        pos = a.find(" ");
        //printf("%d",pos);
        x = a.substr(0,pos);
        m = a[pos+1]-'0';
        n = pos;
        s.clear();
        for(i=0;i<n;i++)s+='+';
        while(!q.empty())q.pop();
        q.push(x);
        check2=0;
        while(!q.empty())
        {
            //cout << a;
            t = q.front(); q.pop();
            //cout << t<< endl;
            //cout << s << endl;
            if(t==s)
            {
                printf("Case #%d: %d\n",++check,mem[t]);
                check2=1;
                break;
            }
            for(i=0;i<=n-m;i++)
            {
                t2 = t;
                for(j=i;j<i+m;j++)
                {
                    if(t2[j]=='+')t2[j]='-';
                    else t2[j]='+';
                }
                if(!mem[t2])
                {
                    mem[t2] = mem[t]+1;
                    q.push(t2);
                }
            }
        }
        if(!check2)printf("Case #%d: IMPOSSIBLE\n",++check);
    }
}
/*
1
+-+-+-+-+ 3

*/
