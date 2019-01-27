#include<bits/stdc++.h>
using namespace std;

#define maxn 30005

int N,M;
int P[maxn];
int A[maxn];

void init(int x) {
    char iname[15] = "input??.txt";
    char oname[15] = "output??.txt";
    iname[5] = oname[6] = x/10 + '0';
    iname[6] = oname[7] = x%10 + '0';
    freopen(iname,"w",stdout);
}

void gen(int n,int m) {
    N = n; M = m;
    for(int i=0;i<N;i++) {
        P[i] = rand()%90000 + ((rand()&1) ? 100000 : 10000000);
    }
    for(int i=0;i<M;i++) A[i] = rand()%100 + 50;
}

void write() {
    printf("%d %d\n",N,M);
    for(int i=0;i<N;i++) printf("%d ",P[i]);
    printf("\n");
    for(int i=0;i<M;i++) printf("%d ",A[i]);
}

void recheck() {
}

main() {
    srand(time(NULL));
    for(int cnum=0;cnum<3;cnum++) {
        init(cnum);
        gen(5000,5000);
        write();
        recheck();
    }
    for(int cnum=3;cnum<10;cnum++) {
        init(cnum);
        gen(30000,30000);
        write();
        recheck();
    }
}
