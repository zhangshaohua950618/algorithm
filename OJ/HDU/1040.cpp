#include<iostream>
#include<algorithm>
using namespace std ;
const int MAXN = 1000  + 10 ;
int  n , num[MAXN] , totNum ;
bool cmp( int a, int b){
	return a < b ;
}
int main(){
	int i ;
	cin >> n ;
	while(n--){
		cin >> totNum ;
		for(  i = 0 ; i < totNum ; i++ )
		cin >> num[i] ;
		sort(num , num + totNum , cmp) ;
		for(  i = 0 ; i < totNum - 1 ; i++ )
		cout << num[i] << " " ;
		cout << num[i] << endl ;
	}
	
} 
