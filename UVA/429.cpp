#include<bits/stdc++.h>
using namespace std;
map<int,string>mp;
map<string,int>mp2;
string a,s,e;
vector<int>from[205];
int mem[205];
queue<int>q;
main()
{
    //freopen("out.txt","w",stdout);
    int time,i,j,k,check,n,t;
    scanf("%d",&time);
    while(time--)
    {
        check =0;
        while(cin >> a && a!="*")
        {
            mp[check] = a;
            mp2[a] = check++;
            //printf("check = %d\n",check);
        }
        n=check;

        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
//
                if(i!=j && mp[i].size() == mp[j].size())
                {

                    check =0;
                    for(k=0;k<mp[i].size();k++)
                    {
                        if(mp[i][k] != mp[j][k])check++;
                    }
                    //printf("mp[%d] = %d,mp[%d] = %d",i,mp[i].size(),j,mp[j].size());
                    //printf(" check = %d %d\n",check,check==1);
                    if(check==1)from[i].push_back(j);
                }
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<from[i].size();j++)
            {
                //printf("%d-->%d\n",i,from[i][j]);
            }
        }
        i=0;
        getline(cin,a);
        getline(cin,a);
        int pos;
        while(a!="")
        {
            memset(mem,0,sizeof(mem));
            pos = a.find(" ");
            s = a.substr(0,pos);
            e = a.substr(pos+1,a.size());
            if(s==e)cout << s << " " << e << " " << "0" <<endl;
            else
            {
                q.push(mp2[s]);
                while(!q.empty())
                {
                    t = q.front();
                    q.pop();
                    for(i=0;i<from[t].size();i++)
                    {
                        if(!mem[from[t][i]])
                        {
                            //printf("a");
                            mem[from[t][i]] = mem[t]+1;
                            q.push(from[t][i]);
                        }
                    }
                    //printf("a");
                }
                cout << s << " " << e << " " << mem[mp2[e]] <<endl;
            }

            if(!getline(cin,a))break;
        }
        if(time)printf("\n");
        mp.clear();
        mp2.clear();
        for(i=0;i<n;i++)from[i].clear();
    }
}
