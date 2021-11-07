#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
int n,m;
int a[300005][10];
int b[300]; 
int ind[300];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	int l=0,r=inf;
	int ans1=0,ans2=0;
	while(l<=r){
		int mid=(l+r)>>1;
		memset(b,0,sizeof(b));
		memset(ind,0,sizeof(ind));
		for(int i=0;i<n;i++){
			int t=0;
			for(int j=0;j<m;j++){
				if(a[i][j]<=mid)t+= 0;
				else t += (1<<j);
			}
			b[t] = 1;
			ind[t] = i;
			// printf("%d\n",t);
		}
		bool p = false;

		for(int i=0;i<(1<<m);i++){
			for(int j=0;j<(1<<m);j++){
				if(b[i] && b[j] && (i|j)==((1<<m)-1)){
					// printf("\n",(1<<m)-1);
					// printf("%d %d %d %d\n",(1<<m)-1,i|j,i,j);
					ans1 = ind[i];
					ans2 = ind[j];
					p = true;
				}
			}
			// printf("%d\n",b[i]);
		}
		if(!p) r = mid-1;
		else l = mid+1;
		// printf("mid = %d\n",mid);
	}
	printf("%d %d",ans1+1,ans2+1);
	return 0;
}

/*

6 5
5 0 3 1 2
1 8 9 1 3
1 2 3 4 5
9 1 0 3 7
2 3 0 6 3
6 4 1 7 0

*/