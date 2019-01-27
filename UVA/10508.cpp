#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
int visit[1000000];
int _max;
int mem[1000000];
vector<int>from[100000];
int go[1000000];
int start;
void dfs(int x)
{
    int i;
    if(!visit[x])
    {
        for(i=0;i<from[x].size();i++)
        {
                if(!visit[from[x][i]])mem[from[x][i]] = mem[x]+1;
                visit[x] = 1;
                if(_max<mem[from[x][i]])
                {
                    _max = mem[from[x][i]];
                    //start = from[x][i];8
                    go[x] = from[x][i];
                }
                dfs(from[x][i]);
        }
        //printf("mem[%d] = %d\n",x,mem[x]);
    }

    return ;
}
main()
{
    FILE *fp = fopen("10508.txt","w");
    int n,m,i,j,k,check;
    char x[1000][1000];
    char a;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(go,0,sizeof(go));
        memset(x,0,sizeof(x));
        for(i=0;i<n;i++)from[i].clear();
        //scanf(" %c",&a);
        for(i=0;i<n;i++)
        {
            printf("%d",i);
            scanf("%s",x[i]);
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i!=j)
                {
                    check = 0;
                    for(k=0;k<m;k++)
                    {
                        if(x[i][k] != x[j][k])check++;
                    }
                    if(check==1)
                    {
                        from[i].push_back(j);
                        //from[j].push_back(j);
                    }
                }
            }
        }
        /*for(i=0;i<n;i++)
        {
            printf("%d ",i);
            for(j=0;j<from[i].size();j++)
            {
                printf("%d ",from[i][j]);
            }
            printf("\n");
        }*/
        memset(visit,0,sizeof(visit));
        memset(mem,0,sizeof(mem));
        _max = 0;
        dfs(0);
        /*for(i=0;i<=n;i++)
        {
            printf("mem[%d] = %d\n",i,mem[i]);
        }*/
        int t;
        t = 0;
        for(i=0;i<n;i++)
        {
            printf("%s\n",x[t]);
            t = go[t];
        }

    }
}
