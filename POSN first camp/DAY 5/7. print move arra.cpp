#include<stdio.h>
main()
{
    int b,i=0,count = 0,n,l,r;
    char s[26],new1[26];
    char a;
    scanf("%d %d %d",&n,&l,&r);
    for(i=0;i<26;i++)
    {
        s[i] = 'A'+i;
    }
    i=0;
    if(n%2!=0)
    {
        while(i<26)
        {
            /*if(10-b+i>=10)printf("%d",s[i-b]);
            else printf("%d",s[10-b+i]);
            i++;*/
            if(26-n+i>=26)new1[i] =s[i-n];
            else new1[i] =s[10-n+i];
            i++;
        }
    }
    if(n%2==0)
    {
        while(i<26)
        {
            /*
            if(b+i>=10)
            {
                printf("%d",s[count]);
                count++;
            }
            else
            printf("%d",s[b+i]);
            i++;
            */
            if(n+i>=26)
            {
                new1[i] =s[count];
                count++;
            }
            else
            new1[i] = s[n+i];
            i++;
            printf("%d = %c\n",i,new1[i]);
        }
    }
    printf("%c %c",new1[l-1],new1[r-1]);
}
