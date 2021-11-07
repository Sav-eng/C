#include<bits/stdc++.h>
using namespace std;
int a[102][102];
int check[102];
int main(){
	int Q,n,T=1;
	scanf("%d",&Q);
	while(Q--){
		int sum=0,ansR=0,ansC=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%d",&a[i][j]);
		for(int i=0;i<n;i++){
			memset(check,0,sizeof(check));
			int p = 0;
			for(int j=0;j<n;j++){
				if(check[a[i][j]]==0)check[a[i][j]] = 1;
				else p = 1;
			}
			ansR += p;
		}
		for(int j=0;j<n;j++){
			memset(check,0,sizeof(check));
			int p = 0;
			for(int i=0;i<n;i++){
				if(check[a[i][j]]==0)check[a[i][j]] = 1;
				else p = 1;
			}
			ansC += p;
		}
		for(int i=0;i<n;i++)sum+=a[i][i];
		printf("Case #%d: %d %d %d\n",T++,sum,ansR,ansC);
	}
}