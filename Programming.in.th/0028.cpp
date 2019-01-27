#include<stdio.h>
main()
{
    int i,j,c[100]={},b[100][100],s1[100]={},s2[100]={},sort[100];
    int max = -1,jmax=-1;
    int cop[100];
    int *p;
    char a[50][50];
    int tmp;
    for(i=0;i<4;i++)
    {
        scanf("%s",&a[i]);
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(i!=j)
            {
                if(b[i][j]>b[j][i])c[i]+=3;
                else if(b[i][j]==b[j][i])
                {
                    c[i]+=1;
                    c[j]+=1;
                }
                else c[j]+=3;
                s1[i]+=b[i][j]-b[j][i];
                s2[i]+=b[i][j];
            }
        }
    }
    for(i=0;i<4;i++)
    {
        c[i]/=2;
        cop[i]=c[i];
    }
    for(i=0;i<4;i++)
    {
        max = -2;
        for(j=0;j<4;j++)
        {
            if(max<cop[j])
            {
                max=cop[j];
                jmax = j;
                p = &cop[j];
            }
        }
            sort[i]=jmax;
            *p = -3;
    }
    for(i=0;i<4;i++)
    {
        if(c[sort[i]]==c[sort[i-1]]&&i!=0)
        {
            if(s1[sort[i]]>s1[sort[i-1]])
            {
                tmp = sort[i];
                sort[i] = sort[i-1];
                sort[i-1] = tmp;
            }
            else if(s1[sort[i]]==s1[sort[i-1]])
            {
                if(s2[sort[i]]>s2[sort[i-1]])
                {
                    tmp = sort[i];
                    sort[i] = sort[i-1];
                    sort[i-1] = tmp;
                }
            }
        }
    }
    for(i=0;i<4;i++)
    {
        printf("%s %d\n",a[sort[i]],c[sort[i]]);
    }
}
