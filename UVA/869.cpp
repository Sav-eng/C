#include<bits/stdc++.h>
using namespace std;
int mem[101][101];
int mem2[101][101];
int mp[200];
main()
{
    //freopen("out.txt","w",stdout);
    int T,check,m,i,j,k,n,time=0;
    char a,b;
    scanf("%d",&T);
    while(T--)
    {
        memset(mem,0,sizeof(mem));
        memset(mem2,0,sizeof(mem2));
        memset(mp,0,sizeof(mp));
        check = 0;
        n = 0;
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf(" %c %c",&a,&b);
            if(mp[a]==0)mp[a]=++check;
            if(mp[b]==0)mp[b]=++check;
            mem[mp[a]][mp[b]] = 1;
            mem[mp[b]][mp[a]] = 1;
            n = max(n,max(mp[a],mp[b]));
        }
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf(" %c %c",&a,&b);
            if(mp[a]==0)mp[a]=++check;
            if(mp[b]==0)mp[b]=++check;
            mem2[mp[a]][mp[b]] = 1;
            mem2[mp[b]][mp[a]] = 1;
            n = max(n,max(mp[a],mp[b]));
        }
        for(k=1;k<=n;k++)for(i=1;i<=n;i++)for(j=1;j<=n;j++)mem[i][j] |= mem[i][k]&mem[k][j];
        for(k=1;k<=n;k++)for(i=1;i<=n;i++)for(j=1;j<=n;j++)mem2[i][j] |= mem2[i][k]&mem2[k][j];
        check=0;
        if(time++)printf("\n");
        for(i=1;i<=n;i++)for(j=1;j<=n;j++)
        {
            if(mem2[i][j] != mem[i][j] && !check)
            {
                printf("NO\n");
                check=1;
            }
        }
        if(!check)printf("YES\n");
    }
}
