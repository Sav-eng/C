#include<stdio.h>
#include<string.h>
main()
{
    int n;
    char a[100][100];
    char t[100];
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(strcmp(a[i],a[j])<0)
            {
                strcpy(t,a[i]);
                strcpy(a[i],a[j]);
                strcpy(a[j],t);
            }
        }
    }
    for(i=0;i<n;i++)printf("%s\n",a[i]);
}
