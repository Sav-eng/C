#include<stdio.h>
#include<string.h>
char x[500];
main()
{
    int nowa=0,nowb=0,nowc=0;
    int n,i;
    int first,last,mid;
    scanf("%d ",&n);
    gets(x);
    first = n/100;
    last = n%10;
    mid = (n/10)%10;
    int check,ch;
    int _a=first,_b=mid,_c=last;
    //printf("%d %d %d ",_a,_b,_c);
    check = strlen(x);
    for(i=0;i<check;i++)
    {
        ch =(int)x[i]-'1';
        nowa = _a+ch;
        if(nowa>9)nowa-=9;
        nowb = nowa+_b-1;
        if(nowb>9)nowb-=9;
        nowc = nowb+_c-1;
        if(nowc>9)nowc-=9;
        _a+=first;
        if(_a>9)_a-=9;
        _b--;
        if(_b==0)_b=9;
        _c+=last;
        if(_c>9)_c-=9;
        printf("%d",nowc);
    }
}
/*
486
59

ans :26

486
26

ans :83

382
33687493

ans :48636775

949
321456987562596
*/
