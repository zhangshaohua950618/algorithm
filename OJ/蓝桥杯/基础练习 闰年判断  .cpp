#include<iostream>
#include<string.h>
using namespace std ;
int year ;
string res ; 
int main(){
	cin >> year ;
	res = (year % 400 == 0 || year % 4 == 0 && year % 100 != 0) ? "yes" : "no" ;
	cout << res << endl ;
	return 0 ; 
	
	
}
