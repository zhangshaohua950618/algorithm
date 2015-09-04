#include<iostream>
#include<vector>
#include<string.h>
using namespace std ; 
const int MAXN = 5000 ;
bool isPrime[MAXN] ;
vector<int> v ;
vector<int>::iterator it ;
void Euler(){
	memset( isPrime , true , sizeof(isPrime)) ;
	for( int i = 2 ; i <= MAXN ; i++ ){
		if(isPrime[i])
		v.push_back(i) ;
		for( it = v.begin() ; it != v.end() ; it++ ){
			if( (*it) * i > MAXN )
			break ;
			isPrime[(*it) * i] = false ;
			if(i % (*it) == 0 )
			break ;
		}
	}
}
int main(){
	Euler() ;
	for( it = v.begin() ; it != v.end() ; it++ )
	cout << (*it) << endl ;
}
