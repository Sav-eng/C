/*
TASK: Cocktail Shaker Sort
LANG: C++
AUTHOR: PeaTT~
*/

#include <stdio.h>
#include <string.h>

#define MAX 100000
int n,numbers[MAX+1],position[MAX+1];

struct fenwick {
   int a[MAX+1];
   fenwick() {
      memset( a, 0, sizeof a );
   }
   int query( int X ) {
      int sum = 0;
      for( int x = X; x > 0; x -= x&-x )
         sum += a[x];
      return sum;
   }
   int sum( int lo, int hi ) {
      return query( hi ) - query( lo-1 );
   }
   void add( int X, int val ) {
      for( int x = X; x <= n; x += x&-x )
         a[x] += val;
   }
} fe;

int main( void ) {
   int i,t;
   scanf("%d",&t);
   while(t--){
	   scanf( "%d", &n );
	   for( i = 1; i <= n; ++i ) {
		  scanf( "%d", &numbers[i] );
		  position[numbers[i]] = i;
		  fe.add( i, 1 );
	   }
	   int mini = 1, maxi = n;
	   for( i = 1; i <= n; ++i ) {
		  if( i%2 == 1 ) {
			 fe.add( position[mini], -1 );
			 printf((i!=n)?"%d " : "%d\n", fe.sum( 1, position[mini] ) );
			 ++mini;
		  } else {
			 fe.add( position[maxi], -1 );
			 printf( (i!=n)?"%d " : "%d\n", fe.sum( position[maxi], n ) );
			 --maxi;
		  }
	   }
   }
   return 0;
}
