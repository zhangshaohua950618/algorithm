#include<iostream>
using namespace std ;
int t , n , s , e , k , sum , Max , num ;
int main(){
	int i ,j ;
	cin >> t ;
	for(j = 1 ; j <= t; j++){
		cin >> n ;
		sum = 0 ;
		Max = -9999999 ;
		s = 1 ;
		e = 1 ;
		k = 1 ;
		for( i = 1 ;i <= n ; i++ ){
			cin >> num ;
			if(sum < 0 ){
				sum = 0 ;
				k = i  ;
			}
			sum += num ;
			if(sum > Max){
				Max = sum ;
				s = k ;
				e = i ;
			}
		}
		cout << "Case " << j << ":" << endl ;
		cout << Max << " " << s << " " << e << endl ;
		if( j != t )
		cout << endl ; 
	}
	return 0 ;
	
}
