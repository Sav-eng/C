#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+2;
struct node
{
    int val,l,r;
    bool operator <(node a)const
    {
        return a.l<l;
    }
};
multiset<int>S;
vector<int>from[MAXN];
int Size[MAXN];
map<int,priority_queue<node> >q;
vector<int> Next[MAXN];
bool check[MAXN];
priority_queue<pair<int,int> >heap;
main()
{
    int n,m,k,i,j,a,op,x,y;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&k);
        for(j=0;j<k;j++)
        {
            scanf("%d",&a);
            from[i].push_back(a);
        }
        Size[i] = from[i].size()-1;
        Next[i].push_back(i);

    }
    //printf("WTF\n");
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&op,&x,&y);
        if(op==1)//delete y in x
        {
            //printf("WTF1\n");
            q[x].push({y,0,Size[x]});
        }
        else//move y to x
        {
            //printf("WTF2\n");
            for(j=0;j<Next[y].size();j++)Next[x].push_back(Next[y][j]);
            while(!q[y].empty())
            {
                node t = q[y].top(); q[y].pop();
                q[x].push({t.val,Size[x]+1,Size[x]+Size[y]+1});
            }
            Size[x]+=Size[y];
            check[y] = 1;
            //printf("check[%d] = %d\n",y,check[y]);
        }
    }
    for(i=1;i<=n;i++)
    {
        //printf("Size[%d] = %d\n",i,Size[i]);
        if(!check[i])
        {
            x = i;
            S.clear();
            int L = 0;
            int X;
            for(x=0;x<Next[i].size();x++)
            {
                if(!x)X = Next[i][x];
                int now = Next[i][x];
                //printf("%d-->%d\n",X,Next[i][x+1]);
                for(j=0;j<from[now].size();j++,L++)
                {
                    int Check = 1;
                    while(!q[X].empty()&&Check)
                    {
                        Check = 0;
                        node t = q[X].top();
                        //printf("del %d l/r %d/%d L = %d\n",t.val,t.l,t.r,L);
                        if(t.l==L)
                        {
                            S.insert(t.val);
                            heap.push({t.r,t.val});
                            q[X].pop();
                            Check = 1;
                        }
                    }
                    Check = 1;
                    while(!heap.empty()&&Check)
                    {
                        Check = 0;
                        pair<int,int> t2 =  heap.top();
                        if(t2.first<L)
                        {
                            S.erase(t2.second);
                            heap.pop();
                            Check  = 1;
                        }
                    }
                    if(S.find(from[now][j])==S.end())printf("%d\n",from[now][j]);
                }
            }
        }
    }
}
/*
5 6
5
1 2 3 4 5
6
5 4 3 2 1 0
2
10 20
3
100 200 300
4
100 200 300 400
2 2 1
1 2 5
2 4 5
2 2 4
2 3 2
1 3 100



*/
