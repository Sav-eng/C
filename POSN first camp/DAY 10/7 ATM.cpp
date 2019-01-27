#include<stdio.h>
#include<conio.h>
main()
{
    int i,a[20]={},sum=0,temp;
    char ch[17];
    for(i=0;i<16;i++)
    {
        ch[i] = getche();
        a[i] = ch[i]-'0';
    }
    a[0]*=2;
    for(i=1;i<=8;i++)
    {
        a[2*i] = a[2*i]*2;

    }
    for(i=0;i<16;i++)
    {
        if(a[i]>9)
        {
            temp = a[i]%10;
            a[i] = a[i]/10;
            a[i] += temp;
        }
    }
    for(i=0;i<16;i++)
    {
        sum +=a[i];
    }
    if(sum%10==0)printf("\nYes");
    else printf("\nWrong!");

}
