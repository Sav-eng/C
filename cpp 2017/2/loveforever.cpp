#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+1;
int m,k,n;
int a[MAXN];
int b[MAXN];
int mem[MAXN];
main()
{
    int time,i,j,time2,t,o;
    int l,r,mid,ans;
    //freopen("10.in","r",stdin);
    //freopen("10.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<m;i++)scanf("%d",&t),a[t] = i;
    for(i=0;i<k;i++)scanf("%d",&t),b[i] = a[t];
    j=0;
    for(i=0;i<k;i++)
    {
        if(b[i]!=0)
        {
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
        }
    }
    printf("%d\n",j+1);
}


