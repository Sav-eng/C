#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
int mem[101][101];
int mem2[101][101];
string s;
stringstream ss;
main()
{
    //freopen("out.txt","w",stdout);
    int n,i,j,k,a,b,now,temp,check;
    while(scanf("%d",&n)&&n)
    {
        getline(cin,s);
        for(i=1;i<=n;i++)for(j=1;j<=n;j++)mem[i][j] = mem2[i][j] = inf;
        for(i = 0; i < n; i++)
        {
          getline(cin, s);
          ss.str(s);
          ss >> j;
          while (ss >> k)
            mem[j][k] = 1;
          ss.clear();
        }
        for(i = 0; i < n; i++)
        {
          getline(cin, s);
          ss.str(s);
          ss >> j;
          while (ss >> k)
            mem2[j][k] = 1;
          ss.clear();
        }
        /*for(i=1;i<=n;i++)
        {
            s.clear();
            getline(cin,s);
            if(i<=9)now=2;
            else if(i<99)now = 3;
            else now = 4;
            for(j=now+1;j<=s.size();j++)
            {
                if(s[j]==' ' || j==s.size())
                {
                    //printf("%d-->%d\n",now,j);
                    temp = 0;
                    for(k=now;k<j;k++)
                    {
                        temp*=10;
                        temp+=s[k]-'0';
                    }
                    now = j+1;
                }
                mem[i][temp]=1;
            }
        }
        for(i=1;i<=n;i++)
        {
            s.clear();
            getline(cin,s);
            if(i<=9) now = 2;
            else if(i<=99)now = 3;
            else now = 4;
            for(j=now+1;j<=s.size();j++)
            {
                if(s[j]==' ' || j==s.size())
                {
                    //printf("%d-->%d\n",now,j);
                    temp = 0;
                    for(k=now;k<j;k++)
                    {
                        temp*=10;
                        temp+=s[k]-'0';
                    }
                    mem2[i][temp]=1;
                    now = j+1;
                }

            }
        }*/
        /*for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)printf("%d ",mem2[i][j]);
            printf("\n");
        }*/
        scanf("%d%d",&a,&b);
        check = 0;
        for(k=1;k<=n;k++)for(i=1;i<=n;i++)for(j=1;j<=n;j++)mem[i][j] = min(mem[i][j],mem[i][k]+mem[k][j]);
        for(k=1;k<=n;k++)for(i=1;i<=n;i++)for(j=1;j<=n;j++)mem2[i][j] = min(mem2[i][j],mem2[i][k]+mem2[k][j]);
        for(i=1;i<=n;i++)for(j=1;j<=n;j++)
            if(i!=j)
                if(mem[i][j]!=inf)
                    if(mem2[i][j] ==inf || mem2[i][j] > (mem[i][j]*a)+b)check=1;

        printf("%s\n",(!check)?"Yes":"No");
    }
}
