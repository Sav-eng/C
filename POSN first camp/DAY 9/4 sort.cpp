#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
main()
{
    int a[50],i,j,min=99999,max=-99999,n=50,temp;
    int *mi,*ma;
    srand(time(NULL));
    for(i=0;i<n;i++)
    {
        a[i] = rand()%100+1;
        //printf("%d \n",a[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(min>a[j])
            {
                min = a[j];
                mi = &a[j];
            }
            if(max<a[j])
            {
                max = a[j];
                ma = &a[j];
            }
        }
        temp = *ma;
        *ma = a[n-1];
        a[n-1] = temp;
        temp = *mi;
        *mi = a[i];
        a[i] = temp;
        n--;
        max = -1;
        min = 101;
    }
    for(i=0;i<50;i++)
    {
        printf("%d\n",a[i]);
    }
}
