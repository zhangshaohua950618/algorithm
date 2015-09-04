#include<iostream>
#include<string.h>
#include<vector>
#include<math.h>
using namespace std ;
const int MAXN = 100 + 10 ;
bool isPrime[MAXN] ;
vector<int> prime ;
int gcd , lcm , n , ans ;
void Euler(){
	int i , j ;
	memset(isPrime , true , sizeof(isPrime)) ;
	for(i = 2 ; i <= MAXN ; i++){
		if(isPrime[i])
		prime.push_back(i) ;
		for(j = 0 ; j < prime.size() ; j++){
			if(prime[j] * i > MAXN)
			break ;
			isPrime[prime[j] * i] = false ;
			if(i % prime[j] == 0)
			break ; 
		}
	}
}
int main(){
	int i ;
	Euler() ;
	cin >> gcd >> lcm ;
	if(lcm % gcd){
	cout << 0 << endl ;
	return 0 ;
	}
	n = lcm / gcd ;
	for(i = 0 ; n != 1 ; i++){
		if(n % prime[i] == 0)
		ans++ ;
		while(n % prime[i] == 0)
		n /= prime[i] ;
	}
	cout << pow(2 , ans) << endl ;
	return 0 ;
}
