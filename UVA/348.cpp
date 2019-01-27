#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
struct node
{
    int x,y;
};
int mem[1005][1005];
int trac[1005][1005];
node a[1005];
int f(int l,int r)
{
    int k,i;
    if(l==r)return 0;
    else if(r-l==1)return a[l].x*a[r].x*a[r].y;
    else if(mem[l][r]== inf)
    {
        for(k=l;k<r;k++)
        {
            if(mem[l][r] > f(l,k)+f(k+1,r)+(a[l].x*a[k].y*a[r].y))
            {
                mem[l][r] = f(l,k)+f(k+1,r)+(a[l].x*a[k].y*a[r].y);
                trac[l][r] = k;
            }
            //printf("l = %d r = %d k = %d\n",l,r,k);
        }
    }
    //printf("mem[%d][%d] = %d\n",l,r,mem[l][r]);
    return mem[l][r];
}
string track(int x,int y)
{
    string t;
    //printf("x = %d y = %d\n",x,y);
    if(x==y)
    {
        string t2,t3;
        int i;
        t += "A";
        x++;
        while(x!=0)
        {
            t2+=(x%10)+'0';
            x/=10;
        }
        for(i=0;i<t2.size();i++)
        {
            t3 += t2[t2.size()-i-1];
        }
        t+= t3;
        return t;
    }
    else if(y-x==1)
    {
        string t2,t3;
        int i;
        x++; y++;
        t += "(A";
        while(x!=0)
        {
            t2+=(x%10)+'0';
            x/=10;
        }
        for(i=0;i<t2.size();i++)
        {
            t3 += t2[t2.size()-i-1];
        }
        t += t3;
        t+= " x A";
        t2.clear();
        t3.clear();
        x=y;
        while(x!=0)
        {
            t2+=(x%10)+'0';
            x/=10;
        }
        for(i=0;i<t2.size();i++)
        {
            t3 += t2[t2.size()-i-1];
        }
        t += t3;
        t+= ")";
        return t;
    }
    else
    {
        t += "(";
        t += track(x,trac[x][y]);
        t+= " x ";
        t+= track(trac[x][y]+1,y);
        t+= ")";
    }
    //printf("%d %d",x,y);
}
main()
{
    int i,n,j;
    int check=0;
    while(scanf("%d",&n) && n)
    {
        check++;
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&a[i].x,&a[i].y);
        }
        for(i=0;i<n;i++)for(j=0;j<n;j++)mem[i][j] = inf;
        f(0,n-1);
        //printf("%d",trac[0][n-1]);
        cout << "Case " << check << ": " <<track(0,n-1) << endl;
        memset(trac,0,sizeof(trac));
    }

}
