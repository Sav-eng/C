#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
struct node
{
    int x[3];
    int val;
    bool operator <(node a)const
    {
        return a.val<val;
    }
};
priority_queue<node>heap;
int mem[201][201][201];
int a[3];
int temp[3];
int ans1,ans2;
main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T,n,i,temp5,j,del1,del2,k;
    node t;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d",&a[0],&a[1],&a[2],&n);
        heap.push({0,0,a[2],0});
        for(i=0;i<=200;i++)for(j=0;j<=200;j++)for(k=0;k<=200;k++)mem[i][j][k] = inf;
        mem[0][0][a[2]] = 0;
        ans1=0,ans2=0;
        node t;
        while(!heap.empty())
        {
            t = heap.top(); heap.pop();
            temp5 = 0;
            for(i=0;i<3;i++) if(t.x[i] <= n && t.x[i] > temp5)temp5 = t.x[i];
            if(temp5 <= n && temp5 > ans1)
            {
                ans1 = temp5;
                ans2 = t.val;
            }
            for(i=0;i<3;i++)
            {
                for(j=0;j<3;j++)
                {
                    if(i!=j)
                    {
                        del1 = a[i]-t.x[i];
                        del2 = a[j]-t.x[j];
                        //printf("%d %d t.x[%d] = %d t.x[%d] = %d\n",del1,del2,i,t.x[i],j,t.x[j]);
                        if(del1>t.x[j])//j-->i
                        {
                            for(k=0;k<3;k++)temp[k] = t.x[k];
                            temp[i] = t.x[i]+t.x[j];
                            temp[j] = 0;
                            if(mem[temp[0]][temp[1]][temp[2]] > t.val+t.x[j])
                            {
                                mem[temp[0]][temp[1]][temp[2]] = t.val+t.x[j];
                                heap.push({temp[0],temp[1],temp[2],t.val+t.x[j]});
                            }
                        }
                        else
                        {
                            for(k=0;k<3;k++)temp[k] = t.x[k];
                            temp[i] = a[i];
                            temp[j] = t.x[j]-del1;
                            if(mem[temp[0]][temp[1]][temp[2]] > t.val+del1)
                            {
                                mem[temp[0]][temp[1]][temp[2]] = t.val+del1;
                                heap.push({temp[0],temp[1],temp[2],t.val+del1});
                            }
                        }
                        if(del2>t.x[i])//i-->j
                        {
                            for(k=0;k<3;k++)temp[k] = t.x[k];
                            temp[i] = 0;
                            temp[j] = t.x[i]+t.x[j];
                            if(mem[temp[0]][temp[1]][temp[2]] > t.val+t.x[i])
                            {
                                mem[temp[0]][temp[1]][temp[2]] = t.val+t.x[i];
                                heap.push({temp[0],temp[1],temp[2],t.val+t.x[i]});
                            }
                        }
                        else
                        {
                            for(k=0;k<3;k++)temp[k] = t.x[k];
                            temp[i] = t.x[i]-del2;
                            temp[j] = a[j];
                            if(mem[temp[0]][temp[1]][temp[2]] > t.val+del2)
                            {
                                mem[temp[0]][temp[1]][temp[2]] = t.val+del2;
                                heap.push({temp[0],temp[1],temp[2],t.val+del2});
                            }
                        }
                    }
                }
            }
            //printf("mem[%d][%d][%d] = %d\n",t.x[0],t.x[1],t.x[2],mem[t.x[0]][t.x[1]][t.x[2]]);
        }
        printf("%d %d\n",ans2,ans1);
    }
}
