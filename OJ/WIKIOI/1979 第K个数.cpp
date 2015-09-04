#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std ;
const int MAXN = 10000 + 10 ;
long N , K , num[MAXN] ;
bool  prime(long num){
	if(num <= 1)
	return false ;
	for(int i = 2 ;i <= sqrt(num) ; i++)
	if(num % i == 0)
	return false ;
	return true ;
}
int main(){
	cin >> N >> K ;
	for(int i =  0 ; i < N ; i++)
	cin >> num[i] ;
	sort(num , num + N) ;
	if(prime(num[N - K] - num[K - 1]))
	cout << "YES" << endl ;
	else
	cout << "NO" << endl ;
	cout << num[N - K] - num[K - 1]  << endl ;
	return 0 ;
}
