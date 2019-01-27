#include<bits/stdc++.h>
using namespace std;
int m,k,n;
int a[62505];
int b[62505];
int mem[62505];
/*int f(int x,int y)
{
    if(x==m-1 || y==k-1)return 0;
    else if(!mem[x][y])
    {
        mem[x][y] = max(f(x+1,y),f(x,y+1));
        if(a[x] == b[y])mem[x][y] = max(mem[x][y],f(x+1,y+1)+1);
    }
    return mem[x][y];
}*/
main()
{
    //freopen("out.txt","w",stdout);
    int time,i,j,time2,t,o;
    int l,r,mid,ans;
    scanf("%d",&time);
    time2= time;
    while(time--)
    {
        memset(mem,0,sizeof(mem));
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        scanf("%d%d%d",&n,&m,&k);
        m++,k++;
        for(i=1;i<=m;i++)scanf("%d",&t),a[t] = i;
        for(i=1;i<=k;i++)scanf("%d",&t),b[i] = a[t];
        j=0;
        for(i=1;i<=k;i++)
        {
            if(b[i]!=0)
            {
                //printf("b[%d] = %d\n",i,b[i]);
                if(j==0)mem[j++]=b[i];
                else
                {
                    if(b[i]>mem[j-1])mem[j++]=b[i];
                    else
                    {
                        l=0,r=j-1;
                        while(l<=r)
                        {
                            mid = (l+r)/2;
                            if(mem[mid]>=b[i])
                            {
                                ans = mid;
                                r = mid-1;
                            }
                            else
                            {
                                l = mid+1;
                            }
                        }
                        mem[ans] = b[i];
                    }
                }
                //for(o=1;o<j;o++)printf("%d ",mem[o]);
                //printf("\n");
            }
        }
        printf("Case %d: %d\n",time2-time,j);
    }
}if save kak p'sea handsome

