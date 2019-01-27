#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5+1;
int a[MAXN];
int mem[MAXN];
int arr[MAXN];
main()
{
    int T,n,m,k,i,A,b,j;
    scanf("%d",&T);
    while(T--)
    {
        memset(a,0,sizeof(a));
        memset(mem,0,sizeof(mem));
        memset(arr,0,sizeof(arr));
        scanf("%d%d%d",&n,&m,&k);
        for(i=1;i<=m;i++)
        {
            scanf("%d",&A);
            a[A] = i;
        }
        for(i=1;i<=k;i++)
        {
            scanf("%d",&b);
            mem[i] = a[b];
            //printf("%d ",mem[i]);
        }
        //printf("\n");
        int check = 0;
        for(i=1;i<=k;i++)
        {
            if(!mem[i])continue;
            if(check==0)arr[check++] = mem[i];
            else
            {
                if(arr[check-1]<mem[i])arr[check++] = mem[i];
                else
                {
                    int l=0,r = check-1,ans = check-1;
                    while(l<=r)
                    {
                        int mid = l+r>>1;
                        if(arr[mid] >= mem[i])
                        {
                            ans = mid;
                            r = mid-1;
                        }
                        else
                        {
                            l = mid+1;
                        }
                    }
                    arr[ans] = mem[i];
                }
                /*for(j=0;j<check;j++)printf("%d ",arr[j]);
                printf("\n");*/
            }
        }
        printf("%d\n",check);
    }
}
/*
1
10 7 10
5 4 2 1 6 8 4
2 1 4 10 5 7 8 9 3 6


*/
