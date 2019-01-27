#include<stdio.h>
#include<string.h>
char x;
char check[100];
char ans;
main()
{
    int n,i;
    int j=0;
    int pn = 0;
    for(i=0;i<26;i++)
    {
        check[i] = 'A'+i;
    }
    while(scanf("%c",&x)!=EOF)
    {
        //if(x>= 'A' && x<= 'z');
        //rintf("%c",x);
        if(x == ',')
        {
            //printf("1");
            pn *= 8;
        }
        else if(x == '.')
        {
            ans = check[pn];
            //printf("%d",pn);
            printf("%c",ans);
            j++;
            pn =0;
        }
        else if(x == 32)
        {
            pn++;
        }

    }

}
