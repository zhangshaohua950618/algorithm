#include<iostream>
using namespace std ;
int T , t , num , ans ;
int main(){	
	cin >> T ;
	for(t = 0 ; t < T ; t++){
		ans = 0 ;
		cin >> num ;
		while(num != 1){
			ans++ ;
			if(num % 2)
			num = num * 3 + 1 ;
			else
			num /= 2 ;
			
		}
		cout << ans << endl ;
	}
	return 0 ;
}
