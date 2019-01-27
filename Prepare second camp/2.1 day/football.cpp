#include<stdio.h>
#include<algorithm>
using namespace std;
main()
{
    int i,j;
    char a[1000][1000];
    int x[5][5];
    int score[1000]={};
    for(i=0;i<4;i++)scanf("%s",a[i]);
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            scanf("%d",&x[i][j]);
        }
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(i!=j)
            {
                if(x[i][j]>x[j][i]) score[i]+=3;
                else if(x[i][j]=x[j][i])
                {
                    score[i]+=1;
                    score[j]+=1;
                }
            }
        }
    }
    for(i=0;i<4;i++)
    {
        //score[i]/=2;
        printf("%s %d\n",a[i],score[i]);
    }


}
