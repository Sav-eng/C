#include<stdio.h>
#include<conio.h>
main()
{
    int i,j,n,k,check=0;
    char c='A',ch[100];
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(j<n-i)printf(" ");
            else
            {
                //printf("%d",j);
                ch[j] = c;
                c++;
                if(c>'Z')c='A';
                check++;
            }
        }
        //printf("%d",check);

        for(j=n-1;j>=0;j--)
        {
            printf("%c",ch[j]);
        }
        check = 0;
        printf("\n");
    }
    getch();
}
