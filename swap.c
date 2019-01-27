#include<stdio.h>
void swap(int* a,int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}
main()
{
    int a,b;
    a = 2;
    b = 3;
    swap(&a,&b);
    printf("%d %d",a,b);
}
