#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
int n,a,b,k;
int ka[20005];
int kb[20005];
int ex[20005];
int mem[2][101][101][11][2];
int f(int w,int x,int y,int z,bool check)
{
    if(x>=a || y>=b || z>k)return -inf;
    else if(w==n)return 0;
    else if(!mem[w][x][y][z][check])
    {
        mem[w][x][y][z][check] = f(w+1,x,y,z,check);
        if(check==0)
        {
            mem[w][x][y][z][check] = max(mem[w][x][y][z][check],f(w+1,x+ka[w],y,z+1,check)+ex[w]);
            if(z==0)
            {
                mem[w][x][y][z][check] = max(mem[w][x][y][z][check],f(w+1,x,y+kb[w],1,!check)+ex[w]);
            }
            else
            {
                mem[w][x][y][z][check] = max(mem[w][x][y][z][check],f(w+1,x,y+kb[w],z-1,check)+ex[w]);
            }
        }
        else
        {
            mem[w][x][y][z][check] = max(mem[w][x][y][z][check],f(w+1,x,y+kb[w],z+1,check)+ex[w]);
            if(z==0)
            {
                mem[w][x][y][z][check] = max(mem[w][x][y][z][check],f(w+1,x+ka[w],y,1,!check)+ex[w]);
            }
            else
            {
                mem[w][x][y][z][check] = max(mem[w][x][y][z][check],f(w+1,x+ka[w],y,z-1,check)+ex[w]);
            }
        }
    }
    //printf("mem[%d][%d][%d][%d][%d] = %d\n",w,x,y,z,check,mem[w][x][y][z][check]);
    return mem[w][x][y][z][check];
}
main()
{
    int time,i;
    printf("%d",sizeof(mem));
    scanf("%d",&time);
    while(time--)
    {
        memset(mem,0,sizeof(mem));

        scanf("%d%d%d%d",&n,&a,&b,&k);
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d",&ka[i],&kb[i],&ex[i]);
        }
        printf("%d",f(0,0,0,0,0));
    }
}
