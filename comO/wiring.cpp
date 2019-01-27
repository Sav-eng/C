#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+1;
int a[MAXN];
int b[MAXN];
int mem[MAXN];
int check[MAXN];
vector<int>from;
int vis[MAXN];
int zet[MAXN];
main()
{
    int T,n,i,t,Time,j;
    bool C;
    scanf("%d",&Time);
    while(Time--)
    {
        memset(a,0,sizeof(a));
        memset(mem,0,sizeof(mem));
        scanf("%d",&n);
        for(i=0;i<n;i++)scanf("%d",&a[i]);
        for(i=0;i<n;i++)scanf("%d",&b[i]);
        for(i=0;i<n;i++)
        {
            mem[a[i]] = b[i];
            if(a[i]==b[i])a[i]=0,b[i]=0;
            //printf("%d ---> %d\n",a[i],b[i]);
        }
        int check = 0;
        memset(vis,0,sizeof(vis));
        for(i=1;i<=n;i++)zet[i] = i;
        for(i=0;i<n;i++)
        {
            t = a[i];
            from.clear();
            check = 0;
            while(t!=0 && !vis[t])
            {
                //printf("%d (%d)\n",t,zet[mem[t]]);
                vis[t] = 1;
                //int t2 = t;
                from.push_back(t);
                t = zet[mem[t]];
                if(vis[t] && t)check=1;

            }
            //printf("check = %d\n",check);
            if(check)
            {
                //printf("%d ",t);
                printf("NO\n");
                check = 1;
                break;
            }
            for(j=0;j<from.size();j++)mem[from[j]]=0,zet[from[j]] = 0;
        }
        if(!check)printf("YES\n");
        //if(!ans)printf("YES\n");
    }
}
/*

5
5
2 3 1 4 0
1 3 0 4 2
3
1 2 3
2 3 1
5
1 0 0 0 2
2 0 0 0 1
6
1 2 3 4 5 6
6 0 2 5 1 0



*/
