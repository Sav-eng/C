#include<stdio.h>
main()
{
    int n,i,a[100]={},max=0;
    char c;
    scanf("%d %c",&n,&c);
    for(i=0;i<n;i++)
    {
        printf("%c",c);
        a[c]++;
        if(c=='Z')c='A'-1;
        c++;
    }
    c ='A';
    for(i=0;i<26;i++)
    {
        printf("\n%c = %d",c+i,a[c+i]);
        if(max<a[c+i])max = a[c+i];
    }
    printf("\n");
    for(i=0;i<26;i++)
    {
        if(a[c+i]==max)printf("%c",c+i);
    }
}
