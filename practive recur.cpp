#include<stdio.h>
#include<string.h>
int b,check=-1;
void func(int i,char x[])
{
    if(i==check)
    {

    }
    else
    {
        printf("%c ",x[i]);
        func(i-1,x);
    }

}
main()
{
    char x[50];
    gets(x);
    b = strlen(x);
    func(b,x);
}
