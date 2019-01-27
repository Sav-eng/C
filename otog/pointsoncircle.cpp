#include<bits/stdc++.h>
using namespace std;
int n;
int rev(int x)
{
    if(x<0)return n+x;
    else if(x>=n)return x-n;
    else return x;
}
int mem[1001];
map<int,int>check;
main()
{
    int k,i,j,a;
    scanf("%d%d",&n,&k);
    for(i=0;i<k;i++)
    {
        for(j=0;j<k;j++)
        {
            scanf("%d",&a);
            if(i!=j)
            {
                if(min((int)fabs(mem[i]-mem[j]),n-max(mem[i],mem[j])+min(mem[i],mem[j]) ) != a)
                {
                    //printf("mem[%d] != mem[%d]\n",i,j);
                    if(!check[rev(mem[i]+a)])
                    {
                        //printf("%d---%d\n",mem[i],mem[j]);
                        if(mem[i]>=mem[j])
                        {
                            check[mem[j]] = 0;
                            mem[j] = rev(mem[i]+a);
                            check[mem[j]] = 1;
                        }

                    }
                    else if(!check[rev(mem[i]-a)])
                    {

                        if(mem[i]<=mem[j])
                        {
                            check[mem[j]] = 0;
                            mem[j] = rev(mem[i]-a);
                            check[mem[j]] = 1;
                        }

                    }
                }
            }
        }
        /*printf("\t");
        for(j=0;j<k;j++)printf("%d ",mem[j]);
        printf("\n");*/
    }
    for(i=0;i<k;i++)printf("%d\n",mem[i]);
}
