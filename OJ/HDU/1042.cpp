#include<iostream>
#include<string.h>
using namespace std ;
const int MAXN = 3000 + 10 ;
int n , step , top , mul[MAXN] , res[MAXN] ;
void calulate( int num ){
	int i ,start = 0 , step  , number  ;
	while(num){
		step = 0 ;
		number = num % 10 ;
		num /= 10 ;
		start++ ;
		for( i = start ; i < top ; i++ ){
			mul[i] = mul[i] * number + step ;
			step = mul[i] / 10 ; 
			mul[i] %= 10 ;
		}
		if(step){
			mul[top] = step ;
			top++ ;
		}
		
	}
}
int main(){
	int i ;
	while( cin >> n ){ 
		memset( mul , 0 , sizeof(mul) ) ;
		memset( res , 0 , sizeof(res) ) ;
		mul[0] = top = 1 ;
		for( i = 1 ; i <= n ; i++ )
		calulate(i) ;
		for( i = top - 1 ; i >= 0 ; i-- )
		cout << mul[i] ;
		cout << endl ;
	}
	return 0 ;
	
}
