#include<iostream>
#include<algorithm>
using namespace std ;
int n , a[3];
int main(){
	int i , j ;
	cin >> n ;
	while( n-- ){
		for( i = 0 ; i < 3 ; i++ )
		cin >> a[i] ;
		sort( a , a + 3 ) ;
		if(a[0] * a[0]  + a[1] * a[1]== a[2] * a[2] )
		cout << "good" << endl ;
		else if(a[0] == a[1] || a[1] == a[2])
		cout << "perfect" << endl ;
		else
		cout << "just a triangle" << endl ;
	}
	
}
