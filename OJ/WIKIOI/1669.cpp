#include<iostream>
#define MAX(a ,b) ((a) > (b) ? (a) : (b))
using namespace std ;
const int MAXN = 1000 + 10 ;
int f[MAXN][MAXN] ;
int v , g , n , vv , gg , tt ;
int main(){
	int i , j , k ;
	cin >> v >> g ;
	cin >> n ;
	for( i = 0 ; i < n ; i++ ){
		cin >> tt >> vv >> gg ;
		for( j = v ; j >= vv ; j-- )
		for( k = g ; k >= gg ; k-- )
		f[j][k] = MAX(f[j][k] , f[j - vv][k - gg] + tt) ;
	}
	cout << f[v][g] << endl ;
}
