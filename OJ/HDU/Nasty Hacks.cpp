#include<iostream>
using namespace std ;
int r ,e , c ,a ,n  ;
int main(){
	cin >> n ;
	while( n-- ){
		cin >> r >> e >> c ;
		a= r - e + c ;
		//cout << a << endl ;
		if( a > 0 )
		cout << "do not advertise" << endl ;
		else if(a == 0)
		cout << "does not matter" << endl ;
		else
		cout << "advertise" << endl ;
	}
	return 0 ;
}
