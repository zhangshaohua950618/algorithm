#include<iostream>
#include<string>
using namespace std ;
const int MAXN = 1000000 + 10 ;
int fib[MAXN] , num  ;
string  result ;
int main(){
	fib[0] = 1 ;
	fib[1] = 2 ;
	while( cin >> num ){
		for( int  i = 2 ; i <= num ; i++ )
		fib[i] = (fib[i - 1] + fib[i - 2]) % 3 ;
		result = fib[num] ? "no" : "yes" ;
		cout << result << endl ;
	}
	return 0 ;
	
}
