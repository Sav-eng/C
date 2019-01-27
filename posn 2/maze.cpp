#include<stdio.h>
#include<algorithm>
#include<limits.h>
#include<queue>
#include<string.h>
using namespace std;
struct node
{
    int x,y,val;
    node(int _x = 0,int _y = 0,int _val =0)
    {
        x = _x;
        y = _y;
        val = _val;
    }
};
queue<node>q;
node start,en;
int cx[]={0,0,-1,1};
int cy[]={1,-1,0,0};
int x[200][200];
bool visit[200][200];
int checkwalk[200][200],checkwalk2[200][200];
bool checkwalls[200][200],checkwalle[200][200];
main()
{
    FILE *fp=fopen("deb.txt","w");
    int m,n;
    int i,j;
    scanf("%d%d",&m,&n);
    scanf("%d%d%d%d",&start.x,&start.y,&en.x,&en.y);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&x[i][j]);
        }
    }
    start.x--;
    start.y--;
    visit[start.x][start.y]=1;
    en.x--;
    en.y--;
    start.val =1;
    en.val =1;
    q.push(start);
    node t;

    while(!q.empty())
    {
        //printf("%d %d",t.x,t.y);
        t = q.front();
        q.pop();
        for(i=0;i<4;i++)
        {
            if(x[t.x + cx[i]][t.y + cy[i]] == 1)
            {
                if(t.x + cx[i] >= 0 && t.x + cx[i] < m && t.y + cy[i] >= 0 && t.y + cy[i] < n && visit[t.x + cx[i]][t.y + cy[i]]==0)
                {
                    visit[t.x + cx[i]][t.y + cy[i]]=1;
                    checkwalk[t.x + cx[i]][t.y + cy[i]] = t.val+1;
                    q.push(node(t.x + cx[i],t.y + cy[i],t.val+1));
                }
            }
            else if(x[t.x + cx[i]][t.y + cy[i]] == 0)
            {
                checkwalk[t.x + cx[i]][t.y + cy[i]] = t.val+1;
                checkwalls[t.x + cx[i]][t.y + cy[i]] =1;
            }

        }
    }
    q.push(en);
    memset(visit,0,sizeof(visit));
    int ans = INT_MAX;
    visit[en.x][en.y]=1;
    while(!q.empty())
    {
        //printf("%d %d",t.x,t.y);
        t = q.front();
        q.pop();
        for(i=0;i<4;i++)
        {
            if(x[t.x + cx[i]][t.y + cy[i]] == 1)
            {
                if(t.x + cx[i] >= 0 && t.x + cx[i] < m && t.y + cy[i] >= 0 && t.y + cy[i] < n && visit[t.x + cx[i]][t.y + cy[i]]==0)
                {
                    visit[t.x + cx[i]][t.y + cy[i]]=1;
                    checkwalk2[t.x + cx[i]][t.y + cy[i]] = t.val+1;
                    q.push(node(t.x + cx[i],t.y + cy[i],t.val+1));
                }
            }
            else if(x[t.x + cx[i]][t.y + cy[i]] == 0)
            {
                checkwalk2[t.x + cx[i]][t.y + cy[i]] = t.val+1;
                checkwalle[t.x + cx[i]][t.y + cy[i]] =1;
            }
        }
    }
    int check=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(checkwalle[i][j] == 1 && checkwalls[i][j] == 1 && x[i][j] == 0)
            {
                check++;
                ans = min(ans,checkwalk[i][j]+checkwalk2[i][j]);
            }//printf("*%d* %d",checkwalk[i][j]+checkwalk2[i][j],ans);
        }
    }
    //printf("%d",ans);
    printf("-------------------------------------\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",checkwalls[i][j]);
        }
        printf("\n");
    }
    printf("-------------------------------------\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",checkwalle[i][j]);
        }
        printf("\n");
    }
     printf("-------------------------------------\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",checkwalk[i][j]);
        }
        printf("\n");
    }
    printf("-------------------------------------\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",checkwalk2[i][j]);
        }
        printf("\n");
    }
    printf("%d\n%d",check,ans-1);
}
/*
5 8
4 5
2 8
0 0 1 1 0 0 0 0
1 0 1 1 0 1 1 1
1 0 1 1 1 0 0 1
1 1 0 0 1 0 0 1
0 0 1 1 0 1 1 1

*/
