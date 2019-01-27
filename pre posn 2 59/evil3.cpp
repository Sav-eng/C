#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
struct node
{
    int x,y,val,order;
    bool operator <(node a)const
    {
        return a.val<val;
    }
};
priority_queue<node>heap;
set<int>myset;
int check;
int head[1001];
int findhead(int x)
{
    //printf("head[%d] = %d\n",x,head[x]);
    if(head[x]==x)return x;
    else return head[x] = findhead(head[x]);
}
int val;
int mem[10001];
void mst()
{
    node t;
    while(!heap.empty())
    {
        t = heap.top();heap.pop();
        //printf("%d----->%d\n",t.x,t.y);
        if(findhead(t.x)!=findhead(t.y))
        {
            mem[check++] = t.order;
            head[findhead(t.x)] = findhead(head[t.y]);
        }

    }
}
int mst1(int x)
{
    int val=0;
    node t;
    while(!heap.empty())
    {
        t = heap.top();heap.pop();
        if(findhead(t.x)!=findhead(t.y) && t.order !=x)
        {
            //printf("%d-----------%d\n",t.x,t.y);
            val+=t.val;
            check++;
            head[findhead(t.x)] = findhead(head[t.y]);
        }
    }
    return val;
}
int tab[10001];
int a[10001];
int b[10001];
int c[10001];
int main()
{
    int n,m,i,ans=inf,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
        heap.push({a[i],b[i],c[i],i});
    }
    check=0;
    for(i=1;i<=n;i++)head[i] = i;
    mst();
    //printf("check=============%d\n",check);
    int check2=0;
    int t2;
    int k;
    k = check;
    //for(i=0;i<k;i++)printf("mem[%d] = %d %d\n",i,mem[i]);
    for(i=0;i<k;i++)
    {
        for(j=1;j<=n;j++)head[j] = j;
        for(j=0;j<m;j++)
        {
            heap.push({a[j],b[j],c[j],j});
        }
        check = 0;
        t2 = mst1(mem[i]);
        //printf("check = %d t2 = %d k = %d\n",check,t2,k);
        if(check==k)tab[check2++] = t2;
        //printf("tab[%d] = %d\n",check2-1,tab[check2-1]);
    }
    sort(&tab[0],&tab[check2]);
    //for(i=0;i<check2;i++)printf("tab[%d] = %d\n",i,tab[i]);
    printf("%d",tab[1]);
}
/*
5 5
1 2 1000
2 3 1000
3 4 1000
4 5 1000
3 5 10000

*/
