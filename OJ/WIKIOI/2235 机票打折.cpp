#include<iostream>
using namespace std ;
int price ;
double  cou ; 
int main(){
	cin >> price >> cou ;
	price = price * cou / 10  ;
	if(price % 10 >= 5)
		price = price - price % 10 + 10 ;
	else
        price =  price - price % 10 ;
	cout << price << endl ;
	return 0 ;
}
