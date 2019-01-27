#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+1;
int tree[MAXN][3];
int check2[MAXN];
int check3[MAXN];
int n;
void update(int x,int val,int ind)
{
    while(x<=n)
    {
        tree[x][ind] += val;
        x+=x&-x;
    }
}
int query(int x,int ind)
{
    int ans=0;
    while(x>0)
    {
        ans += tree[x][ind];
        x-=x&-x;
    }
    return ans;
}
main()
{
    int T,op,x,y;
    scanf("%d%d",&n,&T);
    while(T--)
    {
        scanf("%d%d%d",&op,&x,&y);
        if(op==1)
        {
            if(query(y+1,1)-query(y,1)==1)update(y+1,-1,2);
            if(query(x-1,1)-query(x,1)==1)update(x,-1,3);
            if(query(y+1,1)==query(y,1))update(y+1,1,3);
            if(query(x,1)==query(x-1,1))update(x,1,2);
            update(x,1,1);
            update(y+1,-1,1);
        }
        else if(op==2)
        {
            printf("%d %d\n",query(x,1),query(y,1));
        }
        else
        {
            printf("%d %d %d %d\n",query(x,1),query(y,1),query(y,2)-query(x,2),query(y,3)-query(x,3));
        }
    }
}
/*

10 9
1 1 5
1 1 1
1 3 3
1 5 5
1 5 5
3 2 5






*/
