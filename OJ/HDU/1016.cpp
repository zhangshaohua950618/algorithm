#include<iostream>
#include<vector>
#include<string.h>
using namespace std ;
const int MAXN = 40 ;
bool isPrime[MAXN] , used[MAXN] ;
vector<int> prime ;
int ring[MAXN] ,maxNum , caseNum = 1 ;
void Euler(){
	memset( isPrime , true , sizeof(isPrime)) ;
	for( int  i = 2 ; i <= MAXN ; i++ ){
		if(isPrime[i])
		prime.push_back(i) ;
		for( int j = 0 ; j < prime.size() ; j++ ){
			if( i * prime[j] > MAXN )			
			break ;
			isPrime[i * prime[j]] = false ;
			if( i % prime[j] == 0)
			break ;
		}
	}
	ring[0] = 1 ;
}
void dfs(int step){
	if( (step == maxNum) &&( isPrime[ring[maxNum - 1] + 1]) ){
		int i ;
		for(  i = 0 ; i < maxNum - 1 ; i++ )
		cout << ring[i] << " " ;
		cout << ring[i] << endl ;
	}
	else{
		for( int  i = 2 ; i <= maxNum ; i++ ){
			if( !used[i] && isPrime[ i + ring[step - 1]]){
				used[i] = true ;
				ring[step] = i ;
				dfs(step + 1) ;
				used[i] = false ;
			}
		}
	}
} 
int main(){
	Euler() ;
	while( cin >> maxNum ){
		cout << "Case " << caseNum << ":" << endl ;
		caseNum++ ;
		dfs(1) ;
		cout << endl ;
	}
	return 0 ;
}
