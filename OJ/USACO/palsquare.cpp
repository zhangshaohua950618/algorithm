/*
ID:    zhangsh35
PROG:    palsquare
LANG:    C++
*/
#include<iostream>
#include<fstream>
#include<map>
#include<stack>
using namespace std ;
stack<int> s ;
int radix , number ;
char symble = 'A' ;
map< int , char > m ;
int palsquare[300 + 10][300];
bool Judge( int num ){
	int cnt = 1 , square  = num * num  , i ;
	while(square){
		palsquare[num][cnt++] = square % radix ;
		square /= radix ;
	}
	palsquare[num][0]  = cnt ;
	for( i = 1 ; i <= ( cnt / 2 ) ; i++ ){
		if(palsquare[num][i] != palsquare[num][cnt - i])
		return false ;
	}
	return true ;
}
int main(){
	ifstream cin("palsquare.in") ;
	ofstream cout("palsquare.out") ;
	int i  , j  , number , digit ;
	for( i = 10 ; i <= 20; i++ )
	m[i] = symble++ ;
	cin >> radix ;
	for( i = 1 ; i  <= 300 ; i++ ){
		number = i ;
		if(Judge(number)){
			while(!s.empty())
			s.pop() ;
			while(number){
				 digit = number % radix ;
				 s.push(digit) ;
				 number /= radix ;
			}
			while(!s.empty()){
				digit = s.top() ;
				if(digit >= 10)
				cout << m[digit] ;
				else
				cout << digit ;
				s.pop() ;
			}
			cout << " " ;
			for( j = palsquare[i][0] - 1 ; j >=1 ; j--){
				if(palsquare[i][j] >= 10 )
					cout << m[palsquare[i][j]];
				else
				cout << palsquare[i][j] ;
			}
			cout << endl ;
		}
	}
	return 0 ;
	
	
}

