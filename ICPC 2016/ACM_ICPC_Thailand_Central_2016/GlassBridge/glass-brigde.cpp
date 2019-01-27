#include <stdio.h>
#include <string.h>

long long merge(int* a, int la, int *b, int lb, int* r) {
	int i = 0, j = 0, t = 0;
	long long inv = 0;

	while (i < la && j < lb) {
		if (a[i] <= b[j]) {
			r[t++] = a[i++];
		} else {
			r[t++] = b[j++];
			inv += la-i;
		}
	}

	while (i < la) {
		r[t++] = a[i++];
	}
	while (j < lb) {
		r[t++] = b[j++];
	}

	return inv;
}

long long msort(int *a, int *t, int l) {
	if (l == 0) return 0;
	if (l == 1) {
		t[0] = a[0];
		return 0;
	}
	int s = l/2;
	long long inv = 0;
	inv += msort(a, t, s);
	inv += msort(a+s, t+s, l-s);
	inv += merge(a, s, a+s, l-s, t);
	memcpy(a,t,l*sizeof(int));
	return inv;
}
int a1[100100],a2[100100];

int proc() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a1[i]);
	}
	long long inv = msort(a1,a2,n);
	printf("%lld\n",inv);
	return 0;
}

int main() {
	int t;
	scanf("%d",&t);
	for (; t > 0; t--)
		proc();
}
