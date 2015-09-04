#include<iostream>
#include<math.h>
using namespace std ;
const double eps = 1e-8 ;
double a , b ;
int main(){
	cin >> a >> b ;
	if( fabs(a - b) < eps )
	cout << "yes" << endl ;
	else
	cout << "no" << endl ;
	return 0 ;
}
