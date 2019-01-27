#include<stdio.h>
using namespace std;
int a[200005];
int killed[200005];
main()
{
    int n,i,j,cd=0,cr=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf(" %c",&a[i]);
        if(a[i]=='D')cd++;
        else cr++;
    }
    while(1)
    {

        if(i==n)i=0;

        while(killed[i])
        {
            i++;
            if(i==n)i=0;
        }
        printf("i= %d cd =%d cr =%d",i,cd,cr,a[i]);
        if(cr==0)
        {
            printf("D");
            return 0;
        }
        else if(cd==0)
        {
            printf("R");
            return 0;
        }
        if(a[i]=='D')
        {
            printf("D\n");
            j=i;
            while(a[j]=='D')
            {
                while(a[j]=='R' && killed[j])
                {
                   j++;
                    if(j==n)j=0;
                }
                j++;
                if(j==n)j=0;
            }
            killed[j]=1;
            cr--;
        }
        else
        {
            printf("R\n");
            j=i;
            while(a[j]!='R' && (a[j]=='R' && killed[j]))
            {
                while(a[j]=='R' && killed[j])
                {
                   j++;
                    if(j==n)j=0;
                }
                j++;
                if(j==n)j=0;
            }
            killed[j]=1;
            cd--;
        }
        i++;
    }

}
