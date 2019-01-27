//O(N*log2(M))
#include<bits/stdc++.h>
using namespace std;

#define maxn 30005

int N,M;
int P[maxn], A[maxn];
long long sum[maxn];
int full[maxn];
long long ex[maxn];

int main() {
    int l,r,mid,pos;
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++) scanf("%d",&P[i]);
    for(int i=1;i<=M;i++) scanf("%d",&A[i]), sum[i] = sum[i-1] + A[i];
    for(int i=1;i<=N;i++) {
        l = 1; r = M; pos = M+1;
        while(l<=r) {
            mid = (l+r)/2;
            if(sum[mid]>P[i]) {
                pos = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        full[1]++; full[pos]--;
        ex[pos] += P[i]-sum[pos-1];
    }
    for(int i=1;i<=M;i++) {
        full[i] += full[i-1];
        printf("%lld\n",full[i]*A[i]+ex[i]);
    }
}
