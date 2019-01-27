#include<stdio.h>
int coin[] = {1,3,4,5};
int check[50]={};
int cpy[50]={};
int cc[50]={};
int coinuse;
int mini(int x)
{
    int i, tmp, minc = 10000000;
    if(x==0)
    {
        return 0;
    }
    else
    {
        for(i=0;i<4;i++)
        {
            if(x-coin[i]>=0)
            {
                if(check[x]==1)
                {
                   return cpy[x];
                }
                else
                {
                    tmp = 1 + mini(x-coin[i]);
                    if(minc>tmp)
                    {
                        minc = tmp;
                        coinuse = coin[i];
                    }

                }
            }

        }
        cpy[x] = minc;
        cc[x] =  coinuse;
        check[x] = 1;
        return minc;
    }
}
main()
{
    int x,i,ans;
    scanf("%d",&x);
    ans = mini(x);
    printf("%d\n",ans);
    while(x>0)
    {
        printf("%d ",cc[x]);
        x -= cc[x];
    }
}
