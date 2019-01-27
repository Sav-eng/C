#include<stdio.h>
#include<string.h>
main()
{
    int i,j,sum=0;
    char a[]={'A','B','C','D','E','F'},b[]={'C','D','E','A','Z','Y'},c[]={'A','Z','Y','O','P','Q'};
    sum = 6;
    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
        {
            if(b[j]==a[i])
            {
                sum+=j;
                break;
            }
        }
        if(b[j]=a[i])break;
    }
    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
        {
            if(c[j]==b[i])
            {
                sum+=j;
                break;
            }
        }
        if(b[j]=a[i])break;
    }
    printf("%d",sum);
}
