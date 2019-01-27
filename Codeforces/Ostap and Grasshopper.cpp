#include<stdio.h>
char x[1005];
main()
{
    int i,n,k,start;
    bool check=0;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf(" %c",&x[i]);
        if(x[i] == 'G')
        {
            start = i;
        }
    }
    i = start;
    while(i>=0)
    {
        if(i-k>=0)
        {
            i-=k;
        }
        else break;
        if(x[i]=='#')
        {
            break;
        }
        else if(x[i]=='T')
        {
            check = 1;
            printf("YES");
            break;
        }
    }
    if(!check)
    {
        //printf("a");
        i = start;
        while(i<n)
        {
            if((i+k)<n)
            {
                i+=k;
            }
            else break;
            if(x[i]=='#')
            {
                break;
            }
            else if(x[i]=='T')
            {
                check = 1;
                printf("YES");
                break;
            }
        }
    }
    if(!check)printf("NO");
}
/*
7 6
G..#.#T



*/
