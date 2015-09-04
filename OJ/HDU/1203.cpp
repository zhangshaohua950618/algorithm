#include<iostream>
#include<string.h>
#define MAX(a,b) ((a) > (b) ? (a) : (b))
using namespace std ;
const int MAXN = 10000 + 10 ;
int c , n , v  , w ;
double C , dp[MAXN]; 
int main(){
	int i , j ;
	while( cin >> c >> n && c ){
		memset(dp , 0, sizeof(dp)) ;
		for( i = 0 ; i < n ; i++ ){
			cin >> v >> C ;
			C = 1 - C ;
			for( j = c ; j >= v ; j-- )
			dp[j] = MAX( dp[j] , 1 - (1- dp[j - v]) * (1 - C)) ; 
		}
		cout << dp[c] * 100 << "%" << endl ;
	}
	return 0 ;
}
