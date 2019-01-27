#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
int a[50001];
int mem[1000001];
int check;
main()
{
    int i,n,j,l,r,mid,ans,k;
    while(scanf("%d",&a[0])&&a[0]!=-1)
    {
        i=1;
        while(scanf("%d",&a[i])&&a[i]!=-1)i++;
        n=i;
        j=0;
        ans =0;
        for(i=0;i<n;i++)
        {
            if(i==0)
            {
                mem[j++] = a[i];
            }
            else if(mem[j-1]>=a[i])
            {
                mem[j++]=a[i];
            }
            else
            {
                l =0; r = j-1;
                while(l<=r)
                {
                    mid = (l+r)/2;
                    //printf("%d---%d %d %d %d\n",l,r,mid,a[mid],a[i]);
                    if(mem[mid]>=a[i])
                    {
                        l = mid+1;
                    }
                    else
                    {
                        ans = mid;
                        r = mid-1;
                    }

                }
                mem[ans] = a[i];
            }
            //for(k=0;k<j;k++)printf("%d ",mem[k]);
            //printf("\n");
        }
        if(check)printf("\n");
        printf("Test #%d:\n",++check);
        printf("  maximum possible interceptions: %d\n",j);
        memset(mem,0,sizeof(mem));
    }
}
