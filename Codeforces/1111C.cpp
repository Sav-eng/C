#include<bits/stdc++.h>
using namespace std;
long long a[100002];
vector<long long> s;
long long n,k,A,B;
long long f(long long l,long long r){

	long long itl = lower_bound(s.begin(),s.end(),l)-s.begin();
	long long itr = upper_bound(s.begin(),s.end(),r)-s.begin();
	long long diff=itr-itl;
	if(l==r){
		if(diff!=0){
			return B*diff;
		}
		else {
			return A;
		}
	} else {
		long long mid = (l+r)>>1;
		if(diff==0) return A;
		else {
			long long _min = f(l,mid)+f(mid+1,r);
			_min = min(_min,B*diff*(r-l+1));
			return _min;
		}
		// printf("%lld-%lld = %lld diff=%lld\n",l,r,_min,diff);
	}
}
int main(){
	scanf("%lld%lld%lld%lld",&n,&k,&A,&B);
	long long x;
	for(long long i=0;i<k;i++){
		scanf("%lld",&x);
		s.push_back(x-1);
	}
	sort(s.begin(),s.end());
	printf("%lld",f(0,(1<<n)-1));
	return 0;
}

/*

2 2 1 2
1 3

6

3 2 1 2
1 7

8

*/