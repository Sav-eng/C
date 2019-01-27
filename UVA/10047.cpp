#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
struct node
{
    int x,y,color,dir;
};
int cx[] ={-1,0,1,0};
int cy[] ={0,1,0,-1};
int mem[30][30][7][7];
int visit[30][30][7][7];
char a[30][30];
node s,e,t;
queue<node>q;
main()
{
    //freopen("out.txt","w",stdout);
    int n,m,i,j,check=0,k,l,ans,check2;
    while(scanf("%d%d",&n,&m) && (n || m))
    {
        memset(mem,0,sizeof(mem));
        memset(visit,0,sizeof(visit));
        memset(a,' ',sizeof(a));
        //for(i=0;i<n;i++)for(j=0;j<m;j++)for(k=0;k<5;k++)for(l=0;l<4;l++)mem[i][j][k][l] = inf;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf(" %c",&a[i][j]);
                if(a[i][j]=='S')
                {
                    s.x=i;
                    s.y=j;
                    s.color=0;
                    s.dir=0;
                }
                if(a[i][j]=='T')
                {
                    e.x=i;
                    e.y=j;
                    e.color=0;
                }
            }
        }
        //for(i=0;i<n;i++){for(j=0;j<m;j++)printf("%c",a[i][j]);printf("\n");}
        q.push(s);
        mem[s.x][s.y][0][0]=0;
        visit[s.x][s.y][0][0] = 1;
        while(!q.empty())
        {
            t = q.front();
            q.pop();
            //printf("visit[%d][%d][%d][%d] = %d %c ",t.x+cx[t.dir],t.y+cy[t.dir],(t.color+1)%5,t.dir,visit[t.x+cx[t.dir]][t.y+cy[t.dir]][(t.color+1)%5][t.dir],a[t.x+cx[t.dir]][t.y+cy[t.dir]]);
            //printf("%d ",(a[t.x+cx[t.dir]][t.y+cy[t.dir]] == '.' || a[t.x+cx[t.dir]][t.y+cy[t.dir]] == 'T' || a[t.x+cx[t.dir]][t.y+cy[t.dir]] == 'S') && !visit[t.x+cx[t.dir]][t.y+cy[t.dir]][(t.color+1)%5][t.dir]);
            if((a[t.x+cx[t.dir]][t.y+cy[t.dir]] == '.' || a[t.x+cx[t.dir]][t.y+cy[t.dir]] == 'T' || a[t.x+cx[t.dir]][t.y+cy[t.dir]] == 'S') && !visit[t.x+cx[t.dir]][t.y+cy[t.dir]][(t.color+1)%5][t.dir])
            {
                visit[t.x+cx[t.dir]][t.y+cy[t.dir]][(t.color+1)%5][t.dir]=1;
                mem[t.x+cx[t.dir]][t.y+cy[t.dir]][(t.color+1)%5][t.dir] = mem[t.x][t.y][t.color][t.dir]+1;
                q.push({t.x+cx[t.dir],t.y+cy[t.dir],(t.color+1)%5,t.dir});
            }
            if(!visit[t.x][t.y][t.color][(t.dir+1)%4])
            {
                visit[t.x][t.y][t.color][(t.dir+1)%4]=1;
                mem[t.x][t.y][t.color][(t.dir+1)%4]= mem[t.x][t.y][t.color][t.dir]+1;
                q.push({t.x,t.y,t.color,(t.dir+1)%4});
            }
            if(t.dir==0)
            {
                if(!visit[t.x][t.y][t.color][3])
                {
                    visit[t.x][t.y][t.color][3]=1;
                    mem[t.x][t.y][t.color][3]= mem[t.x][t.y][t.color][t.dir]+1;
                    q.push({t.x,t.y,t.color,3});
                }
            }
            else if(!visit[t.x][t.y][t.color][t.dir-1])
            {
                visit[t.x][t.y][t.color][t.dir-1]=1;
                mem[t.x][t.y][t.color][t.dir-1]= mem[t.x][t.y][t.color][t.dir]+1;
                q.push({t.x,t.y,t.color,t.dir-1});
            }
            //printf("mem[%d][%d][%d][%d] = %d %c\n",t.x,t.y,t.color,t.dir,mem[t.x][t.y][t.color][t.dir],a[t.x][t.y]);
        }
        /*for(i=0;i<4;i++)
        {
            for(j=0;j<5;j++)
            {
                for(k=0;k<n;k++)
                {
                    for(l=0;l<m;l++)
                    {
                        printf("%d ",mem[k][l][j][i]);
                    }
                    printf("\n");
                }
                printf("/////////////////////////////////////////\n");
            }
            printf("////////////////////////////////////////////\n");
        }*/
        ans = inf;
        check2=0;
        //printf("e.x = %d e.y = %d\n",e.x,e.y);
        for(i=0;i<4;i++)
        {
            ans = min(mem[e.x][e.y][0][i],ans);
            if(mem[e.x][e.y][0][i]==0)check2++;
            //printf("%d\n",mem[e.x][e.y][0][i]);
        }
        //for(i=0;i<4;i++)printf("%d\n",mem[e.x][e.y][0][i]);
        check++;
        if(check==1)printf("Case #%d\n",check);
        else printf("\nCase #%d\n",check);
        if(check2==4)printf("destination not reachable\n");
        else printf("minimum time = %d sec\n",ans);
    }
}
/*

4 7
##....T
##.###.
S..###.
##.....
*/
