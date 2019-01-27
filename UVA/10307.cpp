#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,y,val;
    bool operator <(node a)const
    {
        return a.val<val;
    }
};
struct node2
{
    int x,y;
};
int head[101];
int findhead(int x)
{
    if(x==head[x])return x;
    return head[x] = findhead(head[x]);
}
string line;
int tab[51][51];
bool path[101][101];
node2 start[101];
int a[51][51];
int mem[51][51];
priority_queue<node>heap;
queue<node2>q;
int cx[] = {0,0,-1,1};
int cy[] = {1,-1,0,0};
main()
{
    int T,n,m,i,j,check;
    scanf("%d",&T);
    while(T--)
    {
        memset(a,0,sizeof(a));
        scanf("%d%d",&m,&n);
        getline(cin,line);
        check=0;
        for(i=0;i<n;i++)
        {
            getline(cin,line);
            for(j=0;j<line.size();j++)
            {
                if(line[j]==' ')tab[i][j] = '.';
                else tab[i][j] = line[j];
                if(tab[i][j] == 'A'||tab[i][j]=='S')
                {
                    start[check] = {i,j};
                    //printf("%d %d[%d]\n",i,j,check);
                    a[i][j] = check++;
                }
            }
            while(j<m)tab[i][j++] = '.';
        }
        memset(path,0,sizeof(path));
        node2 t;
        //printf("check = %d\n",check);
        for(j=0;j<check;j++)
        {
            memset(mem,0,sizeof(mem));
            q.push({start[j].x,start[j].y});
            while(!q.empty())
            {
                t = q.front(); q.pop();
                for(i=0;i<4;i++)
                {

                    if(!mem[t.x+cx[i]][t.y+cy[i]] && tab[t.x+cx[i]][t.y+cy[i]]!='#')
                    {

                        mem[t.x+cx[i]][t.y+cy[i]] = mem[t.x][t.y]+1;
                        //printf("path[%d][%d] = %d\n",j,a[t.x+cx[i]][t.y+cy[i]],path[j][a[t.x+cx[i]][t.y+cy[i]]]);
                        if((tab[t.x+cx[i]][t.y+cy[i]]=='A' || tab[t.x+cx[i]][t.y+cy[i]]=='S') && !path[j][a[t.x+cx[i]][t.y+cy[i]]])
                        {
                            heap.push({j,a[t.x+cx[i]][t.y+cy[i]],mem[t.x+cx[i]][t.y+cy[i]]});
                            path[j][a[t.x+cx[i]][t.y+cy[i]]] = 1;
                            path[a[t.x+cx[i]][t.y+cy[i]]][j] = 1;
                        }
                        q.push({t.x+cx[i],t.y+cy[i]});
                    }
                }
            }
            head[j]=j;
        }
        int ans;
        ans = 0;
        node t2;
        while(!heap.empty())
        {
            //printf("a");
            t2 = heap.top(); heap.pop();
            if(findhead(head[t2.x])!=findhead(head[t2.y]))
            {
                ans += t2.val;
                //printf("%d %d %d\n",t2.x,t2.y,t2.val);
                head[findhead(t2.x)]= findhead(head[t2.y]);
            }
        }
        printf("%d\n",ans);

    }
}
/*

2
6 5
#####
#A#A##
# # A#
#S  ##
#####

2
6 5
#####
#A#A##
# # A#
#S  ##
#####
7 7
#####
#AAA###
#    A#
# S ###
#     #
#AAA###
#####


*/
