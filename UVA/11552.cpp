#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
int tab[1001][31];
int mem[1001][31];
int n,m,k;
int f(int x,int y)
{
    if(x==m)return 0;
    else if(mem[x][y]==-1)
    {
        //printf("%d %d\n",x,y);
        mem[x][y] = inf;
        int i,j,have=0;
        for(i=0;i<26;i++)
        {
            if(tab[x][i]>0)have++;
        }
        //printf("have = %d x= %d\n",have,x);
        int add=0;
        for(i=0;i<26;i++)
        {
            if(tab[x][i]==0)continue;
            add = have;
            if(i==y)add--;
            for(j=0;j<26;j++)
            {
                if(tab[x][j]==0)continue;
                mem[x][y] = min(mem[x][y],f(x+1,j)+ add + (i==j && have>1 ? 1:0));
            }
        }
        //printf("mem[%d][%d] = %d\n",x,y,mem[x][y]);
    }
    return mem[x][y];
}
main()
{
    //freopen("out.txt","w",stdout);
    int T;
    string s;
    scanf("%d",&T);
    while(T--)
    {
        memset(mem,-1,sizeof(mem));
        memset(tab,0,sizeof(tab));
        int i,j,cnt=0;
        scanf("%d",&k);
        cin >> s;
        n = s.size();
        m = n/k;
        for(i=0;i<n;i+=k)
        {
            for(j=i;j<i+k;j++)
            {
                tab[cnt][s[j]-'a']++;
            }
            cnt++;
        }
        printf("%d\n",f(0,26));
    }
}
