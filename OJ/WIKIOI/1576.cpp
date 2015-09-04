#include<iostream>
#define MAX(a ,b) ((a) > (b) ? (a) : (b))
using namespace std ;
const int MAXN = 5000 + 10 ;
int  n  , num[MAXN] , dp[MAXN] , mark[MAXN] , ans , count , pos  ;
int main(){
	int i , j ;
	while(cin >> num[i]){
		pos = -1 ;
		 for( j = 0 ; j<  i ; j++ )
		 	if(num[j] > num[i] && dp[j] > dp[i] ){
		 		dp[i] = dp[j] ;
		 		pos = j ;
			 }
		 dp[i]++ ;
		 if(pos != -1)
			mark[pos]++ ;
		 	ans = MAX(ans , dp[i]) ; 
		 i++ ;
	}
	for(j = 0 ; j < i ; j++ ){
	//	cout << dp[j] << endl ;
			if(!mark[j])
			count++ ;
	}
	cout << ans << endl<< count << endl  ;
	return 0 ;
	
}
