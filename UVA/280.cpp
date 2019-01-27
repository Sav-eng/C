#include<stdio.h>
#include<vector>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;
vector<int>from[5000];
queue<int>q;
int a[100000];
int mem[100000];
main()
{
    int n,x,y,m,i,j,t;
    int check;
    while(1)
    {
        memset(mem,0,sizeof(mem));
        memset(a,0,sizeof(a));
        scanf("%d",&n);
        for(i=0;i<n;i++)from[i].clear();
        if(n==0)break;
        while(1)
        {
            scanf("%d",&x);
            if(x==0)break;
            else
            {
                while(1)
                {
                    scanf("%d",&y);
                    if(y==0)break;
                    else
                    {
                        from[x].push_back(y);
                    }
                }
            }
        }
        scanf("%d",&m);
        //printf("m = %d",m);
        for(i=0;i<m;i++)
        {
            scanf("%d",&a[i]);
        }
        //scanf("%d",&t);
        for(i=0;i<m;i++)
        {
            memset(mem,0,sizeof(mem));
            q.push(a[i]);
            while(!q.empty())
            {
                //printf("a");
                x = q.front();
                q.pop();
                for(j=0;j<from[x].size();j++)
                {
                    if(mem[from[x][j]]==0)
                    {
                        q.push(from[x][j]);
                        mem[from[x][j]]=1;
                    }
                }
            }
            check = 0;
            for(j=1;j<=n;j++)
            {
                //printf("mem[%d] = %d\n",i,mem[i]);
                if(mem[j]==0)
                {
                    check++;
                }
            }
            printf("%d ",check);
            for(j=1;j<=n;j++)
            {
                if(mem[j]==0)printf("%d ",j);
            }
            printf("\n");
        }
    }


}
/*

3
1 2 0
2 2 0
3 1 2 0
0
2 1 2
0

*/
