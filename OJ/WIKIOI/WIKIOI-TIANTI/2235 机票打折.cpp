#include<iostream>
using namespace std ;
int oldPrice  , newPrice ;
double m ;
int main(){
	cin >> oldPrice >> m ;
	newPrice = oldPrice * m / 10  ;
	if((int)(newPrice) % 10 >= 5 ){
	newPrice = newPrice - newPrice % 10  ;
	newPrice ++ ;
	}
	else
	newPrice = newPrice - newPrice % 10  ;
	cout << newPrice << endl ;
	return 0 ;
		
}
