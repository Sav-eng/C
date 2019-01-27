#include<stdio.h>
int m = 0;
char s[15][5];
main()
{
    int i,j,k,c,st,time;
    int x = -1,y = -1;
    freopen("a2.in","r",stdin);
    freopen("A2.txt","w",stdout);
    scanf("%d",&time);
    while(time--)
    {
        for(i=0;i<10;i++) scanf(" %s",s[i]);
        for(i=0;i<10;i++)
        {
            for(j=0;j<10;j++)
            {
                if(i==j) continue;
                for(k=0;k<4;k++)
                {
                    c = 0;
                    while(k+c<4 && s[i][c]==s[j][k+c])
                    {
                        c++;
                    }
                    if(k+c>=4)
                    {
                        if(m<=c)
                        {
                            m = c;
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        //printf("%d %d  : %d\n",x,y,m);
        for(i=0;i<10;i++)
        {
            if(i!=x && i!=y) printf("%s",s[i]);
        }
        for(i=0;i<4-m;i++) printf("%c",s[y][i]);
        //printf("%s",s[x]);
        for(i=0;i<m+3;i++) printf("X");
        printf("\n");
    }
}
/*
2

TEST INTE RNET PROB ROBL OBLE BLEM SOLV VING TEST

AAAA AAAA AAAA AAAA AAAA AAAA AAAA AAAA AAAA AAAB
*/
