#include<iostream>
#include<vector>
#include<string.h>
using namespace std ;
const int MAXN = 10000 ;
bool isprime[MAXN] ;
vector<int> v ;
void Euler(){
	int i , j ;
	memset(isprime , true , sizeof(isprime)) ;
	for(i = 2 ; i < MAXN ; i++){
		if(isprime[i])
		v.push_back(i) ;
		for(j = 0 ; j < v.size() ; j++){
			if(i * v[j] > MAXN)
			break ;
			isprime[i * v[j]] = false ;
			if(i % v[j] == 0)
			break ; 
		}
	}
}
int main(){
	Euler() ;
	for(int i = 0 ; i < v.size() ; i++)
	cout << v[i] << endl ;
	return 0 ;
	
}