#include<stdio.h>
main()
{
    int x,y,check=0,i[10]={0,0,0,0,0,0,0,0,0,0},a,j,j1;
    scanf("%d %d",&x,&y);
    for(j=x;j<=y;j++)
    {
        j1 = j;
        while(j1!=0)
        {
            a = j1%10;
            j1 = j1/10;
            switch(a)
            {
            case 1:
                i[1]+=1;
                break;
            case 2:
                i[2]+=1;
                break;
            case 3:
                i[3]+=1;
                break;
            case 4:
                i[4]+=1;
                break;
            case 5:
                i[5]+=1;
                break;
            case 6:
                i[6]+=1;
                break;
            case 7:
                i[7]+=1;
                break;
            case 8:
                i[8]+=1;
                break;
            case 9:
                i[9]+=1;
                break;
            case 0:
                i[0]+=1;
                break;
            }
        }
    }

    for(j=0;j<10;j++)
    {
        printf("%d is a %d \n",j,i[j]);
    }
}

