#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,open;
};
vector<int>from[1005];
vector<int>from2[1005];
queue<node>q;
int mem[15][2005];
int tracr[15][2005];
int traco[15][2005];
int mp2[4005];
int ptr[105];
int pto[105];
node t;
main()
{
    freopen("out.txt","w",stdout);
    int n,m,k,i,a,b,check=0,check2,ansbit;
    i=1;
    check=0;
    while(i<4000)
    {
        mp2[i] = check++;
        i = i*2;
    }
    check=0;
    while(scanf("%d%d%d",&n,&m,&k) &&(n||m||k))
    {
        printf("%d %d %d\n",n,m,k);
        for(i=0;i<1000;i++)
        {
            from[i].clear();
            from2[i].clear();
        }
        memset(pto,0,sizeof(pto));
        memset(ptr,0,sizeof(ptr));
        memset(traco,0,sizeof(traco));
        memset(tracr,0,sizeof(tracr));
        memset(mem,0,sizeof(mem));

        for(i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            printf("%d %d\n",a,b);
            from[a].push_back(b);
            from[b].push_back(a);
        }
        for(i=0;i<k;i++)
        {
            scanf("%d%d",&a,&b);
            printf("%d %d\n",a,b);
            from2[a].push_back(b);
            //from2[b].push_back(a);
        }
        q.push({1,1});
        while(!q.empty())
        {
            t = q.front(); q.pop();
            for(i=0;i<from[t.x].size();i++)
            {
                //printf("%d&%d = %d %d\n",1<<from[t.x][i]-1,t.open,1<<from[t.x][i]-1&t.open,!mem[from[t.x][i]][t.open]);
                if(((1<<from[t.x][i]-1)&t.open)!=0 && !mem[from[t.x][i]][t.open])
                {
                    //printf("a");
                    mem[from[t.x][i]][t.open] = mem[t.x][t.open]+1;
                    q.push({from[t.x][i],t.open});
                    tracr[from[t.x][i]][t.open] = t.x;
                    traco[from[t.x][i]][t.open] = t.open;
                }
            }
            for(i=0;i<from2[t.x].size();i++)
            {
                if(!mem[t.x][t.open^(1<<from2[t.x][i]-1)])
                {
                    mem[t.x][t.open^(1<<from2[t.x][i]-1)] = mem[t.x][t.open]+1;
                    q.push({t.x,t.open^(1<<from2[t.x][i]-1)});
                    tracr[t.x][t.open^(1<<from2[t.x][i]-1)] = t.x;
                    traco[t.x][t.open^(1<<from2[t.x][i]-1)] = t.open;
                }
            }
            //printf("mem[%d][%d] = %d\n",t.x,t.open,mem[t.x][t.open]);
        }
        check++;
        printf("Villa #%d\n",check);
        if(mem[n][1<<(n-1)]==0 && n!=1)printf("The problem cannot be solved.\n\n");
        else if(n==1)printf("The problem can be solved in 0 steps:\n\n");
        else
        {
            printf("The problem can be solved in %d steps:\n",mem[n][1<<(n-1)]);
            check2=0;
            t.x = n;
            t.open = 1<<(n-1);
            while(t.x!=1 || t.open != 1)
            {
                if(traco[t.x][t.open]==t.open)
                {
                    ptr[check2] = t.x;
                    pto[check2++] = t.open;
                    t.x = tracr[t.x][t.open];
                    //printf("[%d][%d]\n",t.x,t.open);
                }
                else
                {
                    ptr[check2] = t.x;
                    pto[check2++] = t.open;
                    t.open = traco[t.x][t.open];
                    //printf("[%d][%d]\n",t.x,t.open);
                }
            }
            for(i=check2-1;i>=0;i--)
            {
                if(t.x!=ptr[i])
                {
                    printf("- Move to room %d.\n",ptr[i]);
                    t.x = ptr[i];
                }
                else
                {
                    ansbit = t.open^pto[i];
                    if((ansbit&t.open)==0)printf("- Switch on light in room %d.\n",mp2[ansbit]+1);
                    else printf("- Switch off light in room %d.\n",mp2[ansbit]+1);
                    t.open = pto[i];
                }
            }
            printf("\n");
        }
    }

}
