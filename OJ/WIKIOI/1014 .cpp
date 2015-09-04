#include<iostream>
#include<string.h>
#define MAX(a , b) ((a) > (b) ? (a) : (b))
using namespace std ;
const int MAXN = 20000 + 10 ;
int f[MAXN] ;
int v , c , n , max ;
int main(){
	int i ,j ;
	cin >> v ;
	cin >> n ;
	for( i = 0 ;i < n ; i++ ){
		cin >> c ;
		for( j = v ; j >= c ; j-- )
		f[j] = MAX( f[j - c] + c  , f[j]) ;
	}
	cout << v - f[v] << endl ;
	return 0 ;
}
