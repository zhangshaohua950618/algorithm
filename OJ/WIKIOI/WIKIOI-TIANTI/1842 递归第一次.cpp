#include<iostream>
using namespace std ;
int num ;
int f(int num){
	if(num >= 0)
	return 5 ;
	return f(num + 1)+f(num + 2)+1 ; 
}
int main(){
	cin >> num ;
	cout << f(num) << endl ;
	return 0 ;
}
