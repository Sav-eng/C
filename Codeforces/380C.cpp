#include<bits/stdc++.h>
using namespace std;
string s;
struct node
{
    int x,y,ind;
    bool operator <(node a)const
    {
        return a.y>y;
    }
};
node a[100001];
bool cmp(node x,node y)
{
    return x.y<y.y;
}
int n,m;
int tree[1000001];
void add(int x,int val)
{
    while(x<=m)
    {
        //printf("Update %d\n",x);
        tree[x]+=val;
        x+=x&-x;
    }
}
int sum(int x)
{
    int ans = 0;
    while(x>0)
    {
        //printf("%d ",x);
        ans += tree[x];
        x-=x&-x;
    }
    return ans;
}
struct node2
{
    char x;
    int y;
};
stack<node2>ST;
int Ans[100001];
main()
{
    int i,j;
    cin >> s;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&a[i].x,&a[i].y);
        a[i].ind = i;
    }
    sort(a,a+n);
    m = s.size();
    node2 t;
    j = 0;
    //for(i=0;i<n;i++)printf("%d %d\n",a[i].x,a[i].y);
    for(i=0;i<m;i++)
    {
        if(ST.size()==0)ST.push({s[i],i+1});
        else
        {
            t = ST.top();
            //cout << t.x << " " << s[i] << endl;
            if(t.x=='(' && s[i]== ')')
            {
                ST.pop();
                add(t.y,1);
            }
            else ST.push({s[i],i+1});
        }
        while(a[j].y==i+1 && j<n)
        {
            //printf("%d--%d",a[j].x,a[j].y);
            Ans[a[j].ind] = (sum(a[j].y)-sum(a[j].x-1))*2;
            //printf("\t%d\n",(sum(a[j].y)-sum(a[j].x-1))*2);
            j++;
        }
    }
    for(i=0;i<n;i++)printf("%d\n",Ans[i]);

}

/*

())(())(())(
7
1 1
2 3
1 2
1 12
8 12
5 11
2 10

*/
