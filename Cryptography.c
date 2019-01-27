#include<stdio.h>
long x,a[200000],Count=0,i,p,y[200000];
long prime[200000];
long ma = -1;
main()
{

    scanf("%ld",&x);
    for(i=0;i<x;i++)
    {
        scanf("%ld",&y[i]);
        if (y[i] > ma)
            ma = y[i];
    }
    for(i=1;i<=150000;i++)
        {
        a[i]=0;
        }
    Count = 0;
    p = 2;
    while (Count < ma) {
        prime[++Count] = p;
        i = 1;
        while (p*i <= 150000) {
            a[p*i] = 1;
            i++;
        }
        while (a[p] == 1)
            p++;
    }
    for (i=0; i<x; i++) {
        printf("%ld\n", prime[y[i]]);
    }
    return 0;
}
