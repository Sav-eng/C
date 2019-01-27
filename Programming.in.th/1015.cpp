#include<stdio.h>
int cx[] ={0,0,1,-1};
int cy[] = {1,-1,0,0};
int sumg;
int n;
int a[120][120];
int normali,normalj,checki,checkj;
void f(int x,int y,int z)
{
    //a[x][y]=0;
    if(normali!=x)checki=1;
    if(normalj!=y)checkj=1;
    if(x<0 || x>=n || y >=n || y< 0)return;
    int i;
    for(i=0;i<4;i++)
    {
        if(a[x+cx[i]][y+cy[i]]==z && a[x+cx[i]][y+cy[i]]!=0)
        {
            //printf("a");
            sumg++;
            a[x][y]=0;
            f(x+cx[i],y+cy[i],z);
        }
    }
    return ;
}
main()
{
    scanf("%d",&n);
    int i,j,sum=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {

        for(j=0;j<n;j++)
        {
            if(a[i][j]!=0)
            {
                sumg=1;
                normali = i;
                normalj = j;
                checkj=0;
                checki=0;
                f(i,j,a[i][j]);
                //a[i][j] =0;
                //printf("%d %d\n",i,j);
                if(checki==0 || checkj==0)sumg = 0;
                if(sumg==3)sum++;
            }

        }
    }
    printf("%d",sum);
}
/*
5
3 3 6 6 0
3 5 5 6 8
2 2 5 8 8
2 1 7 7 7
1 1 4 4 4
*/
