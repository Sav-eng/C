#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
vector<int>from[400001];
int mem[6][2][400001];
int k,l;
int start;
queue<int>q;
void link(int x,int y)
{
    if(y==k-1)return;
    int x2;
    x2 = x-start+1;
    //printf("a");
    from[x].push_back(x+x2);
    from[x+x2].push_back(x);
    from[x].push_back(x+x2+1);
    from[x+x2+1].push_back(x);
    //printf("%d-->%d start = %d\n",x,x+x2,start);

    link(x+x2+1,y+1);
    link(x+x2,y+1);
}
void pre()
{
    int limit = 1,i;
    for(i=0;i<k;i++)limit*=2;
    start = 1;
    //printf("limit =%d\n",limit);
    for(i=0;i<2;i++)
    {
        //printf("start = %d\n",start);
        link(start,0);
        start+=limit;
    }
}
int bfs(int x,int y,int s)
{
    q.push(s);
    mem[x][y][s] = 0;
    int t,i;
    while(!q.empty())
    {
        t = q.front();q.pop();
        for(i=0;i<from[t].size();i++)
        {
            if(mem[x][y][from[t][i]]==-1)mem[x][y][from[t][i]] = inf;
            if(mem[x][y][from[t][i]] > mem[x][y][t]+1)
            {
                mem[x][y][from[t][i]] = mem[x][y][t]+1;
                q.push(from[t][i]);
            }

        }
        //printf("mem[%d][%d] = %d\n",s,t,mem[s][t]);
    }
}
int len(int x,int y)
{
    if(x==y)return 0;
    else if(x>y)return len(x/2,y)+1;
    else return len(x,y/2)+1;
}
int a[10],b[10];
main()
{
    int i,time,j,ans;
    scanf("%d%d%d",&k,&l,&time);
    pre();
    for(i=0;i<l;i++)
    {
        scanf("%d%d",&a[i],&b[i]);
        if(a[i]>b[i])swap(a[i],b[i]);
        from[a[i]].push_back(b[i]);
        from[b[i]].push_back(a[i]);
    }
    memset(mem,-1,sizeof(mem));
    /*for(i=1;i<pow(2,k+1);i++)
    {
        printf("%d",i);
        for(j=0;j<from[i].size();j++)printf("--->%d",from[i][j]);
        printf("\n");
    }*/
    for(i=0;i<l;i++)
    {
        bfs(i,0,a[i]);
        bfs(i,1,b[i]);
    }
    //for(i=1;i<=15;i++)printf("mem[1][i] = %d\n",mem[1][i]);
    int s,e;
    while(time--)
    {
        ans = inf;
        scanf("%d%d",&s,&e);
        if(s>e)swap(s,e);
        if((s<(1<<k) && e<(1<<k)))ans = len(s,e);
        if(s>(1<<k) && e>(1<<k))ans = len(s-(1<<k),e-(1<<k));
        for(i=0;i<l;i++)
        {
            //printf("mem[%d][0][%d] = %d mem[%d][1][%d] = %d\n",i,e,mem[i][0][e],i,e,mem[i][1][e]);
            if(s<(1<<k))
            {
                ans = min(ans,len(s,a[i])+mem[i][0][e]);
            }
            else
            {
                ans = min(ans,len(s-(1<<k),b[i]-(1<<k))+mem[i][1][e]);
            }
        }
        printf("%d\n",ans);
    }
}
/*
4 2 3
1 18
15 20
9 6
7 21
15 1


*/
