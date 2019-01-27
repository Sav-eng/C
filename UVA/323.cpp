#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
int n,m;
int a[201];
int b[201];
int mem[201][25][1501];
int mem2[201][25][1501];
bool trac[201][25][1501];
bool trac2[201][25][1501];
bool check=0,check2;
int f(int x,int y,int sum)
{
    if(x==n && y==m && 400-sum==0){check = 1;return 0;}
    else if(x==n && (y!=m || sum!=0))return -inf;
    else if(mem[x][y][sum]==-1)
    {
        if(y+1<=m)
        {
            if((f(x+1,y,sum)<f(x+1,y+1,sum+a[x]-b[x])+a[x]+b[x]))
            {
                mem[x][y][sum] = f(x+1,y+1,sum+a[x]-b[x])+a[x]+b[x];
                trac[x][y][sum] = 1;
            }
            else mem[x][y][sum] = f(x+1,y,sum);
        }
        else mem[x][y][sum] = f(x+1,y,sum);
    }
    //printf("mem[%d][%d][%d] = %d\n",x,y,sum,mem[x][y][sum]);
    return mem[x][y][sum];
}
int f2(int x,int y,int sum)
{
    if(x==n && y==m && 400-sum==0){check2 = 1;return 0;}
    else if(x==n)return -inf;
    else if(mem2[x][y][sum]==-1)
    {
        if(y+1>=m)
        {
            if((f2(x+1,y,sum)<f2(x+1,y+1,sum-a[x]+b[x])+a[x]+b[x]))
            {
                mem2[x][y][sum] = f2(x+1,y+1,sum-a[x]+b[x])+a[x]+b[x];
                trac2[x][y][sum] = 1;
            }
            else
            {
                mem2[x][y][sum] = f2(x+1,y,sum);
            }
        }
        else mem[x][y][sum] = f2(x+1,y,sum);

    }
    //printf("mem2[%d][%d][%d] = %d\n",x,y,sum,mem2[x][y][sum]);
    return mem2[x][y][sum];
}
int alld,allp,k;
int tab[201];
void track1(int z)
{
    int x,sum=400+z,y=0,check=0;
    for(x=0;x<n;x++)
    {
        if(trac[x][y][sum]==1)
        {
            tab[check++]=x;
            sum = sum+a[x]-b[x];
            alld +=a[x];
            allp +=b[x];
            y++;
        }
    }
    k = check;
}
void track2(int z)
{
    int x,sum=400+z,y=0,check=0;
    for(x=0;x<n;x++)
    {
        if(trac2[x][y][sum]==1)
        {
            tab[check++] = x;
            //printf("trac2[%d][%d][%d] = %d\n",x,y,sum,trac2[x][y][sum]);
            sum = sum-a[x]+b[x];
            alld +=a[x];
            allp +=b[x];
            y++;
        }
    }
    k=check;
}
main()
{
    int i,t,t2,time=0;
    while(scanf("%d%d",&n,&m) && n && m)
    {
        memset(trac,0,sizeof(trac));
        memset(mem,-1,sizeof(mem));
        memset(mem2,-1,sizeof(mem2));
        memset(trac2,0,sizeof(trac2));
        memset(tab,0,sizeof(tab));
        check=0; check2=0;
        alld =0; allp=0;
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&a[i],&b[i]);
            //printf("i = %d\n",i);
        }
        for(i=0;i<=400;i++)
        {
            t = f(0,0,400+i);
            t2 = f2(0,0,400+i);
            if(check || check2)break;
            //printf("\n");
        }
        if(time)printf("\n");
        printf("Jury #%d\n",++time);
        if(check && !check2)//f
        {
            track1(i);
        }
        else if(check2 && !check)//f2
        {
            track2(i);
        }
        else if(check && check2)// f && f2
        {
            if(t>t2) track1(i);
            else track2(i);
        }
        printf("Best jury has value %d for prosecution and value %d for defence:\n",alld,allp);
        printf("k = %d\n",k);
        for(i=0;i<k;i++)printf(" %d",tab[i]+1);
    }
}

/*

200 20
0 20
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
20 0

*/
