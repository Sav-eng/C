#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int b[1000001];
int vis[1000001];
bool color[1000001];
vector<int>from[100001];
void f(int x,bool now)
{
    int i;
    vis[x] = 1;
    color[x] = now;
    for(i=0;i<from[x].size();i++)
    {
        bool next = !now;
        if(!vis[from[x][i]])f(from[x][i],next);
    }
}
main()
{
    int n,m,i;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&a[i],&b[i]);
        from[a[i]].push_back(b[i]);
        from[b[i]].push_back(a[i]);
    }
    for(i=0;i<n;i++)
    {
        if(!vis[i])
        {
            f(i,0);
        }
        //printf("color[%d] = %d\n",i,color[i]);
    }
    for(i=0;i<m;i++)
    {
        if(color[a[i]]==color[b[i]])
        {
            printf("Gay found!\n");
            return 0;
        }
    }
    printf("Gay not found!");
}
