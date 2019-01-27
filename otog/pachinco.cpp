/*#include<bits/stdc++.h>
using namespace std;
char direction[1000001];
char ans[1000001];
int L[1000001];
int R[1000001];
/*struct node
{
    int x,ball;
};
int Count;
int topo[1000001];
int vis[1000001];
void dfs2(int x)
{
    if(x==0)return ;
    if(vis[x])return ;
    vis[x] = 1;
    if(!vis[L[x]])dfs2(L[x]);
    if(!vis[R[x]])dfs2(R[x]);
    topo[Count--] = x;
}
void dfs(int x,int ball)
{
    if(x==0)return ;
    int goleft,goright;
    goleft = ball/2;
    goright = ball/2;
    if(ball%2==1)
    {
        if(direction[x]=='L')goleft++,ans[x]='R',direction[x] = 'R';
        else goright++,ans[x]='L',direction[x] = 'L';
    }
    else
    {
        ans[x] = (direction[x]=='L')?'L':'R';
    }
    //printf("x = %d goleft = %d goright =%d ans = %c\n",x,goleft,goright,ans[x]);
    dfs(L[x],goleft);
    dfs(R[x],goright);
}
//queue<node>q;
int Ball[100001];
main()
{
    int n,m,i;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf(" %c%d%d",&direction[i],&L[i],&R[i]);
    }
    Count = m;
    dfs2(1);
    Ball[1] =  n;
    int goleft,goright;
    for(i=1;i<=m;i++)
    {
        int x = topo[i];
        //printf("%d ",topo[i]);
        int ball = Ball[x];
        goleft = goright = ball/2;
        if(ball%2==1)
        {
            if(direction[x]=='L')
            {
                goleft++;
                direction[x] = 'R';
                ans[x] = 'R';
            }
            else
            {
                goright++;
                direction[x] = 'L';
                ans[x] = 'L';
            }
        }
        else
        {
            ans[x] = direction[x]=='L'?'L':'R';
        }
        Ball[L[x]]+=goleft;
        Ball[R[x]]+=goright;
    }
    /*
    q.push({1,n});
    while(!q.empty())
    {
        node t = q.front(); q.pop();
        if(t.x==0)continue;
        int ball = t.ball;
        int x = t.x;
        int goleft,goright;
        goleft = ball/2;
        goright = ball/2;
        if(ball%2==1)
        {
            if(direction[x]=='L')goleft++,ans[x]='R',direction[x] = 'R';
            else goright++,ans[x]='L',direction[x] = 'L';
        }
        else
        {
            ans[x] = (direction[x]=='L')?'L':'R';
        }
        //printf("x = %d goleft = %d goright =%d ans = %c\n",x,goleft,goright,ans[x]);
        q.push({L[x],goleft});
        q.push({R[x],goright});
    }
    //dfs(1,n);
    //printf("END");
    for(i=1;i<=m;i++)printf("%c",ans[i]);
}*/
#include<bits/stdc++.h>
using namespace std;
char x[500010];
int l[500010];
int r[500010];
long long ball[500010];
int deg[500010];
int topo[500010];
char ans[500010];
queue<int>q;
stack<int>st;
main()
{
    int m,i;
    long long n;
    scanf("%lld%d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf(" %c%d%d",&x[i],&l[i],&r[i]);
        deg[l[i]]++;
        deg[r[i]]++;
        ans[i] = x[i];
    }
    int check=0;
    for(i=1;i<=m;i++)
    {
        if(!deg[i])st.push(i);
    }
    long long goleft,goright;
    ball[1]=n;
    //printf("%d",check);
    while(!st.empty())
    //for(i=0;i<check;i++)
    {
        int X = st.top();
        st.pop();
        if(X==0)continue;
        long long Ball = ball[X];
        if(!--deg[l[X]])st.push(l[X]);
        if(!--deg[r[X]])st.push(r[X]);
        if(Ball==0)continue;
        goright = goleft = (long long)Ball/2;
        if(Ball&1)//ball[x]&2==1
        {
            if(x[X]=='L')
            {
                ans[X] = 'R';
                goleft++;
            }
            else
            {
                ans[X] = 'L';
                goright++;
            }
        }
        else
        {
            ans[X] = x[X];
        }
        ball[l[X]] += (long long)goleft;
        ball[r[X]] += (long long)goright;
        //printf("deg[%d] = %d [%d] = %d\n",l[X],deg[l[X]],r[X],deg[r[X]]);

        //printf("topo[%d] =%d check = %d\n",i,X,check);
    }
    for(i=1;i<=m;i++)printf("%c",ans[i]);
}
/*

100000000000000 3
L 2 3
R 0 3
L 0 0


*/
