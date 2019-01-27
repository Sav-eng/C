#include<bits/stdc++.h>
#define maxn 500+3
#define maxm 100+3
using namespace std;
int mem[maxn][maxm];
int tab[maxn][maxm];
int trac[maxn][maxm];
int n;
map<int,string>mp;
int dp(int x,int y)
{
    int i;
    if(x==n)return 0;
    else if(!mem[x][y])
    {
        mem[x][y] = dp(x+1,y);
        for(i=0;i<6;i++)
        {
            if(tab[x][i]==y)
            {
                if(i%2==0)
                {
                    if(mem[x][y]<=dp(x+1,tab[x][i+1])+1)
                    {
                        mem[x][y] = dp(x+1,tab[x][i+1])+1;
                        trac[x][y] = tab[x][i+1];
                        //printf("trac[%d][%d] = %d\n",x,y,tab[x][i+1]);
                    }
                    //mem[x][y] = max(mem[x][y],dp(x+1,tab[x][i+1])+1);
                }
                else
                {
                    if(mem[x][y]<=dp(x+1,tab[x][i-1])+1)
                    {
                        mem[x][y] = dp(x+1,tab[x][i-1])+1;
                        trac[x][y] = tab[x][i-1];
                        //printf("trac[%d][%d] = %d\n",x,y,tab[x][i-1]);
                    }
                    //mem[x][y] = max(mem[x][y],dp(x+1,tab[x][i-1])+1);
                }
            }
        }
    }
    //printf("mem[%d][%d] = %d\n",x,y,mem[x][y]);
    return mem[x][y];
}
main()
{
    int ans=0,time=0,s,t;
    mp[0] = "front"; mp[1] = "back"; mp[2] = "left"; mp[3] = "right";mp[4] = "top";mp[5] = "bottom";
    while(scanf("%d",&n) && n)
    {
        memset(trac,0,sizeof(trac));
        memset(mem,0,sizeof(mem));
        int i,j;
        for(i=0;i<n;i++)
        {
            for(j=0;j<6;j++)
            {
                scanf("%d",&tab[i][j]);
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<6;j++)
            {
                if(ans<=dp(i+1,tab[i][j])+1)
                {
                    ans = dp(i+1,tab[i][j])+1;
                    trac[i][tab[i][j]] = tab[i][j];
                    //printf("trac[%d][%d] = %d\n",i,tab[i][j],trac[i][tab[i][j]]);
                    t = tab[i][j];
                    s = i;
                }
                //ans = max(dp(i+1,tab[i][j]),ans);
                //printf("\n");
            }
        }
        if(time)printf("\n");
        printf("Case #%d\n",++time);
        printf("%d\n",ans);
        int t2=0;
        int check=0;
        for(i=s;i<n;i++)
        {
            while(trac[i][t]==0 && i+1<n)i++;
            check++;
            t2=0;
            for(j=0;j<6;j++)
            {
                if(tab[i][j]==t && j%2==0 && (tab[i][j+1]==trac[i][t] || i==s)){t2=j;break;}
                else if(tab[i][j]==t && j%2!=0 && (tab[i][j-1]==trac[i][t] || i==s)){t2=j;break;}
            }
            if(i==s && j%2==0)t2++;
            else if(i==s && j%2!=0)t2--;
            printf("%d ",i+1);
            cout << mp[t2] << endl;
            //printf("%d\n",trac[i][t]);
            t = trac[i][t];
            //printf("check = %d\n",check);
            if(check==ans)break;
        }

    }
}
/*
3
1 2 2 2 1 2
3 3 3 3 3 3
3 2 1 1 1 1
10
1 5 10 3 6 5
2 6 7 3 6 9
5 7 3 2 1 9
1 3 3 5 8 10
6 6 2 2 4 4
1 2 3 4 5 6
10 9 8 7 6 5
6 1 2 3 4 7
1 2 3 3 2 1
3 2 1 1 2 3
0


*/
