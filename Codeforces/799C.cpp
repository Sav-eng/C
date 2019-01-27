#include<bits/stdc++.h>
#define inf 1e8
#define MAXN 100001
using namespace std;
int C[MAXN];
int D[MAXN];
int n;
int add(int tree[],int x,int val)
{
    while(x<=MAXN)
    {
        tree[x] = max(tree[x],val);
        x+=x&-x;
    }
}
int query(int tree[],int x)
{
    int ans = -inf;
    while(x>0)
    {
        ans = max(ans,tree[x]);
        x -= x&-x;
    }
    return ans;
}
main()
{
    int x,y,a,b;
    char c;
    int i;
    int ans= 0;
    int t;
    fill(C,C+MAXN,-inf);
    fill(D,D+MAXN,-inf);
    scanf("%d%d%d",&n,&x,&y);
    for(i=0;i<n;i++)
    {
        scanf("%d%d %c",&a,&b,&c);//b = cost a = val
        t = -inf;
        if(c=='C')
        {
            if(x-b<0)continue;
            t = max(query(C,x-b),query(D,y));
            add(C,b,a);
        }
        else
        {
            if(y-b<0)continue;
            t = max(query(C,x),query(D,y-b));
            add(D,b,a);
        }
        ans = max(ans,t+a);
        //printf("ans = %d t= %d a = %d\n",ans,t,a);
    }
    printf("%d",(ans>0)?ans:0);
}
