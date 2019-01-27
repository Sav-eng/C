#include<bits/stdc++.h>
using namespace std;
string s[5];
int pos[5][51][30];
int mem[51][51][51][51];
int f(int a,int b,int c,int d)
{
    if(a == -1 || b== -1 || c==-1 || d==-1)return 0;
    else if(!mem[a][b][c][d])
    {
        int i;
        mem[a][b][c][d] = 1;
        for(i='a';i<='z';i++)mem[a][b][c][d] += f(pos[0][a][i-'a'],pos[1][b][i-'a'],pos[2][c][i-'a'],pos[3][d][i-'a']);
        //printf("mem[%d][%d][%d][%d] = %d\n",a,b,c,d,mem[a][b][c][d]);
    }
    return mem[a][b][c][d];
}
int n[5];
main()
{
    int Q,p,q,i,j;
    scanf("%d",&Q);
    while(Q--)
    {
        cin >> s[0] >> s[1] >> s[2] >> s[3];
        n[0] = s[0].size();
        n[1] = s[1].size();
        n[2] = s[2].size();
        n[3] = s[3].size();
        for(p=0;p<4;p++)
        {
            for(i='a';i<='z';i++)
            {
                q = -1;
                for(j=0;j<=n[p];j++)
                {
                    pos[p][j][i-'a'] = q;
                    if(s[p][j]==(char)i)q=j;
                }
            }
        }
        int ans = 0;
        for(i='a';i<='z';i++)
        {
            ans += f(pos[0][n[0]][i-'a'],pos[1][n[1]][i-'a'],pos[2][n[2]][i-'a'],pos[3][n[3]][i-'a']);
        }
        printf("%d",ans);
    }
}
