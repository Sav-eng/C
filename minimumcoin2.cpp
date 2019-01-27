#include<stdio.h>
int coin[] = {1,2,5,10};
int cpy[50]={};
int check[50]={};
int checkc[50][50]={{}};
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
                   //checkc[x][tmp] = coin[tmp];
                }
                else
                {
                    tmp = 1 + mini(x-coin[i]);
                    //checkc[x][tmp] = coin[tmp];
                }
            }
            if(minc>tmp)
            {
                minc = tmp;
                //name[i]++;
            }
        }
        cpy[x] = minc;
        check[x] = 1;
        //if()
        return minc;
    }
}
main()
{
    int x,i;
    scanf("%d",&x);
    printf("%d",mini(x));
}
