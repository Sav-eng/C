#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
struct node
{
    int x,val;
    bool operator < (node a)const
    {
        return a.val<val;
    }
};
char a[101][101];
char b[101][101];
int val[101];
int n,m;
bool check(int x,int i)
{
    int j;
    for(j=0;j<n;j++)
    {
        if(a[i][j]=='+'&& !(1 & (x>>(n-j-1))))return 0;
        else if(a[i][j]=='-' && (1&(x>>(n-j-1))))return 0;
    }
    return 1;
}
int make(int x,int i)
{
    int ans= 0,j;
    for(j=0;j<n;j++)
    {
        if(b[i][j]=='+')ans+=1;
        else if(b[i][j]=='0')ans += 1 &(x>>(n-j-1));
        ans <<= 1;
    }
    ans >>= 1;
    return ans;
}
priority_queue<node>heap;
vector<int>mem;
main()
{
    int i,j,time=0;
    mem.resize(1<<20,inf);
    while(scanf("%d%d",&n,&m)&&n)
    {
        for(i=0;i<m;i++)scanf("%d%s%s",&val[i],&a[i],&b[i]);
        heap.push({(1<<n)-1,0});
        for(i=0;i<(1<<n);i++)mem[i] = inf;
        mem[(1<<n)-1]=0;
        int t2;
        node t;
        while(!heap.empty())
        {
            t = heap.top(); heap.pop();
            //if(t.val == mem[t.x])
            {
                for(i=0;i<m;i++)
                {
                    if(check(t.x,i))
                    {
                        t2 = make(t.x,i);
                        //printf("%d---%d make-->%d[%d]\n",t.x,i,t2,val[i]);
                        if(mem[t2]>mem[t.x]+val[i])
                        {
                            mem[t2] = mem[t.x]+val[i];
                            heap.push({t2,mem[t2]});
                        }
                    }
                }
            }
        }
        //if(time)printf("\n");
        printf("Product %d\n",++time);
        if(mem[0]==inf)printf("Bugs cannot be fixed.\n\n");
        else printf("Fastest sequence takes %d seconds.\n\n",mem[0]);
    }
}
