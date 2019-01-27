#include<stdio.h>
#include<limits.h>
int tree[500005];
int h;
void add(int x,int y)
{
        while(x<=h)
        {
                tree[x]+=y;
                x+=(x&-x);
        }
}
int sum(int x)
{
        int s = 0;
        while(x>0)
        {
                s += tree[x];
                x-=(x&-x);
        }
        return s;
}
main()
{
        int i,j,x,n,min = INT_MAX,count = 0;
        scanf("%d%d",&n,&h);
        for(i=0;i<n;i++)
        {
                scanf("%d",&x);
                if(i%2==0)
                {
                        add(1,1);
                        add(x+1,-1);
                }
                else add(h-x+1,1);
        }
        for(j=1;j<=h;j++)
        {
                if(sum(j)<min)
                {
                        min = sum(j);
                        count = 1;
                }
                else if(sum(j)==min) count++;
                //printf("height = %d -> %d\n",j,sum(j));
        }
        printf("%d %d",min,count);
}
