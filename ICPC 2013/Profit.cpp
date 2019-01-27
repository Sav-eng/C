#include<stdio.h>
int ans[1000][10];
main()
{
    freopen("profits_input.txt","r",stdin);
    freopen("profits_output.txt","w",stdout);
    bool mode;
    int n,i,_i,_max=0,_j,m,b,a,j,ii;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&m);
        b= 0;
        ii = 1;
        _j = 1;
        _i = 1;
        _max = 0;
        mode = 1;
        for(j=1;j<=m;j++)
        {
            scanf("%d",&a);
            b+= a;
            if(b<0)
            {
                b = 0;
                mode = 1;
            }
            if(mode && b > 0 && a!=0)
            {
                mode = 0;
                ii = j;
            }
            if(b>_max)
            {
                _max = b;
                _i = ii;
                _j = j;
            }
        }
        if(_max!=0)
        {
            ans[i][0] = _i;
            ans[i][1] = _j;
            ans[i][2] = _max;
            //printf("%d %d %d\n",_i+1,_j+1,_max);
        }
        else
        {
            ans[i][0] = 0;
            ans[i][1] = 0;
            ans[i][2] = 0;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }

}
/*
6
16 4 3 -10 3 -1 2 0 -3 5 7 -4 -8 -10 4 7 -30
6 -1 0 -3 -1 0 -1
10 -1 -4 -5 -9 -14 5 6 7 -10 10
3 -2 -3 -4
17 1 2 3 4 5 6 7 8 9 -10 -11 10 9 8 -7 -6 13
7 1 2 3 -10 3 2 1
*/
