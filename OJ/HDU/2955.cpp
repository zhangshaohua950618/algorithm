#include<iostream>
#include<string.h>
#define MAX(a,b) ((a) > (b) ? (a) : (b))  
using namespace std ;
//ifstream cin("1.in") ;
//ofstream cout("1.out") ;
const int MAXN = 10000 + 10 ;
struct P{
	int w ;
	int c ;
} ;
int  n , w , c , t , dp[MAXN]  ;
double C ;
P p[MAXN] ; 
int main(){
	int i , j ;
	cin >> t ;
	while( cin >> C >> n && t--  ){
		memset(dp , 0 , sizeof(dp)) ;
		c = C *  100 ;
		for( i = 0 ; i < n ; i++){
			cin >> p[i].w >> C ;
			p[i].c = C * 100 ;
			for( j = p[i].c ; j <= c ; j++)
			dp[j] = MAX( dp[j] , dp[ j - p[i].c] + p[i].w ) ;
		}
			cout << dp[c] << endl ;
	}
	
}
