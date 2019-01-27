#include<stdio.h>
int tab[3005][3005];
struct node
{
    int i;
    int j;
    bool operator == (node x)const
    {
        if(x.i!=i && x.j!=j)return 0;
        return 1;
    }
};
node A,B,C,D;
node ind[5];
main()
{
    int a,b,i,j,k;
    char x;
    bool check;
    node t;
    scanf("%d %d",&a,&b);
    ind[0].i=0;
    ind[0].j=a-1;
    ind[1].i=a-1;
    ind[2].j=a-1;
    ind[3].i=a-1;
    ind[3].j=0;
    ind[4].i=0;
    ind[4].j=0;
    tab[0][0]=4;
    tab[0][a-1]=1;
    tab[a-1][0]=3;
    tab[a-1][a-1]=2;
    for(i=0;i<b;i++)
    {
        for(j=0;j<4;j++)
        {
            check = 0;
            scanf(" %c",&x);
            if(x=='S')
            {
                t.i = i+1;
                t.j = j;
                for(k=0;k<4;k++)
                {
                    if(ind[k]==t)check = 1;
                }
                if(check!=1)
                {
                    tab[ind[i].i][ind[i].j] = i+1;
                    ind[j].i = i+1;
                }
            }
            if(x=='N')
            {
                t.i = i-1;
                t.j = j;
                for(k=0;k<4;k++)
                {
                    if(ind[k]==t)check = 1;
                }
                if(check!=1)
                {
                    tab[ind[i].i][ind[i].j] = i+1;
                    ind[j].i = i-1;
                }
            }
            if(x=='W')
            {
                t.i = i;
                t.j = j-1;
                for(k=0;k<4;k++)
                {
                    if(ind[k]==t)check = 1;
                }

                if(check!=1)
                {
                    tab[ind[i].i][ind[i].j] = i+1;
                    ind[j].j=j-1;
                }
            }
            if(x=='E')
            {
                t.i = i;
                t.j = j-1;
                for(k=0;k<4;k++)
                {
                    if(ind[k]==t)check = 1;
                }
                if(check!=1)
                {
                    tab[ind[i].i][ind[i].j] = i+1;
                    ind[j].j=j+1;
                }
            }
        }
    }
    for(i=0;i<a;i++)
    {
        for(j=0;j<a;j++)
        {
            printf("%d",tab[i][j]);
        }
        printf("\n");
    }
}
