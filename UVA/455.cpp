#include<bits/stdc++.h>
using namespace std;
char a[101];
char t[101];
char s[101];
main()
{
    //freopen("out.txt","w",stdout);
    int time,n,i,j,k,check,check2=0;
    int check3=0;
    scanf("%d",&time);
    while(time--)
    {
        memset(a,NULL,sizeof(a));
        scanf(" %s",&a);
        n = strlen(a);
        //printf("%d",n);
        for(i=1;i<=n;i++)
        {
            check = i;
            memset(s,NULL,sizeof(s));
            for(j=0;j<i;j++)s[j]=a[j];
            //printf("%s\n",s);
            check2=0;
            for(j=2*i;j<=n+i-1;j+=i)
            {
                k=0;
                memset(t,NULL,sizeof(t));
                while(check<j)t[k++] = a[check++];
                if(strcmp(t,s)!=0)check2=1;
                //printf("\t%s %d\n",t,check2);
            }
            if(!check2)break;
        }
        if(check3++)printf("\n");
        if(!check2 && i!=(n/2)+1)printf("%d\n",i);
        else printf("%d\n",n);
    }
}
/*
5

abcdefghijk

abcdabcd

abababababababbababababab

amanamanamanaman

bbabb



*/
