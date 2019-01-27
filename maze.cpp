#include<stdio.h>
#include<vector>
#include<queue>
#include<limits.h>
using namespace std;
int n,m;
int cx[5] = {0,0,1,-1};
int cy[5] = {1,-1,0,0};
int time[1005][1005];
int table[1005][1005];
int max(int x,int y)
{
        if(x>y) return x;
        return y;
}
int check(int x,int y)
{
        if(x<0||x>n||y<0||y>m) return 0;
        return 1;
}
struct node
{
        int x,y,sec;
        bool operator < (node a) const
        {
                return a.sec<sec;
        }
};
priority_queue<node> heap;
vector<node> flood[2005];
priority_queue<int> heapval;
main()
{
        node t;
        int i,j,maxtime=0;
        int x,y,sec,xx,yy;
        int ans = 0;
        scanf("%d%d",&n,&m);
        scanf("%d%d",&t.x,&t.y);
        for(i=0;i<n;i++)
        {
                for(j=0;j<m;j++)
                {
                        scanf("%d",&table[i][j]);
                        time[i][j] = INT_MAX;
                }
        }
        t.sec = 0;
        heap.push(t);
        time[t.x][t.y] = 0;
        while(!heap.empty())
        {
                x = heap.top().x;
                y = heap.top().y;
                sec = heap.top().sec;
                flood[sec].push_back(heap.top());
                //printf("%d %d %d\n",x,y,sec);
                heap.pop();
                for(i=0;i<4;i++)
                {
                        xx = x+cx[i];
                        yy = y+cy[i];
                        if(check(xx,yy)==1&&time[xx][yy]>sec+1&&table[xx][yy]!=-1)
                        {
                                time[xx][yy] = sec+1;
                                t.x = xx;
                                t.y = yy;
                                t.sec = sec+1;
                                heap.push(t);
                        }
                }
        }
        for(i=0;i<n;i++)
        {
                for(j=0;j<m;j++)
                {
                        //if(time[i][j]==INT_MAX) printf("X ");
                        //else printf("%d ",time[i][j]);
                        if(time[i][j]!=INT_MAX) maxtime = max(maxtime,time[i][j]);
                }
                //printf("\n");
        }
        for(i=maxtime;i>=0;i--)
        {
                //printf("Max time = %d\n",maxtime);
                for(j=0;j<flood[i].size();j++)
                {
                        //printf("Push %d\n",table[flood[i][j].x][flood[i][j].y]);
                        heapval.push(table[flood[i][j].x][flood[i][j].y]);
                }
                ans += heapval.top();
                //printf("GET %d\n",heapval.top());
                heapval.pop();
        }
        printf("%d",ans);
}
/*
5 7
0 3
-1 -1 -1  4 -1 -1 -1
-1  9  1 6  1  5  -1
-1 6 -1 -1  8 10 -1
-1  2  6 -1 2 -1 -1
-1 -1 -1 -1 -1 -1 -1
*/
