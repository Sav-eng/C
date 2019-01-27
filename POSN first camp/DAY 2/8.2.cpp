#include<stdio.h>
main()
{
    int a,b,i,check=1,j,checkm=1,n;
    scanf("%d %d %d",&a,&b,&n);
    for(i=1;i<a;i++)
    {
        //printf("   ");
        check++;
    }
    for(i=0;i<=12*b-1;i++)
    {
        //if(i%b+1<10)printf(" ");
            if(i%b==0 && i!=0)
            {
               // printf("\n");
                checkm++;
                if(checkm==n)break;
                for(j=1;j<check;j++)
                {
                    //printf("   ");
                }
                //printf(" ");
            }
        //printf(" %d",i%b+1);
        check++;
        if(check==8)
        {
            check = 1;
            //printf("\n");
        }
    }
    for(i=1
        ;i<check;i++)
    {
        printf("   ");
    }
    //printf("  ");
    for(i=0;i<=b-1;i++)
    {
        if(i%b+1<10)printf(" ");
            if(i%b==0 && i!=0)
            {
                printf("\n");
                for(j=1;j<check;j++)
                {
                    printf("   ");
                }
                printf(" ");
            }
        printf(" %d",i%b+1);
        check++;
        if(check==8)
        {
            check = 1;
            printf("\n");
        }
    }

}
