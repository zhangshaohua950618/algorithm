#include<iostream>
#include<math.h>
using namespace std ;
int num ;
bool isPrime(int num){
	int i ;
	for(i = 2 ; i <= sqrt(num) ; i++)
	if(num % i == 0)
	return false ;
	return true ;
}
int main(){
	cin >> num ;
	if(isPrime(num))
	cout << "\\t" << endl ;
	else
	cout << "\\n" << endl ;
	return 0 ;
}
