#include<stdio.h>

int main() {
    long long t,n;
    scanf("%lld",&t);
    for(int i=0;i<t;i++) {
        scanf("%lld",&n);
        long long j;
        for(j=0;3*j*(j+1)/2+1<=n;j++);
        n-=3*j*(j-1)/2;
        if(n<=j) {
            if(j==1)
                printf("1 dolphin\n");
            else
                printf("%d dolphins\n",j);
        }
        else if(n>2*j)
            printf("splash\n");
        else {
            if(j==1)
                printf("1 jump\n");
            else
                printf("%d jumps\n",j);
        }
    }
    return 0;
}
