/*
ID:    zhangsh35
PROG:    ride
LANG:    C++
*/
#include<fstream>
#include<string.h>
using namespace std ;
string comet , group , output ;
int sum1 = 1, sum2 = 1;
ifstream cin("ride.in") ;
ofstream cout("ride.out") ;
int main(){
	int i ;
	cin >> comet >> group ;
	for( i = 0 ; i  < comet.length() ; i++ )
	sum1 *= comet[i] - 'A' + 1 ;
	for( i = 0 ; i  < group.length() ; i++ )
	sum2 *= group[i] - 'A' + 1 ;
	output = (sum1 % 47 )== (sum2 % 47) ? "GO" : "STAY" ;
	cout << output << endl ;
} 
