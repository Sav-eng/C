#include<bits/stdc++.h>
using namespace std;
int a[100005];
int n;
int f(vector<int> &x,int bit){
	if(bit==0)return 0;
	bool have=false,nothave=false;
	vector<int> on,off;
	for(auto i:x){
		if(i&(1<<bit))on.push_back(i);
		else off.push_back(i);
		// printf("%d ",i);
	}
	if(on.size()==0)return f(off,bit-1);
	else if(off.size()==0)return f(on,bit-1);
	else return min(f(on,bit-1),f(off,bit-1))+(1<<bit);
}
int main(){
	scanf("%d",&n);
	vector<int> a;
	int x;
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		a.push_back(x);
	}
	printf("%d",f(a,30));
	return 0;
}

/*

3
1 2 3

*/