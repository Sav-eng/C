#include<stdio.h>
#include<queue>
using namespace std;
queue<int>x;
vector<int>tab[100];
main()
{
    int n,m,start,i,j;
    int a,b,y;
    bool bo[100];
    scanf("%d %d %d",&n,&m,&start);
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&a,&b);
        tab[a].push_back(b);
    }
    x.push(start);
    while(!x.empty())
    {
        y = x.front();
        if(bo[y]!=1)
        {
            printf("%d",x.front());
            bo[y] = 1;
        }
        x.pop();
        for(i=0;i<tab[y].size();i++)
        {
            x.push(tab[y][i]);
        }
    }
}
