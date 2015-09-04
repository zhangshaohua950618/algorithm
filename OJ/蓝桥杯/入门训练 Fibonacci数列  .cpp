#include<iostream>
using namespace std ;
const int MAXN = 1000000 + 10 ;
const int MOD = 10007 ;
int f[MAXN]  , N ;
int main(){
	int i ;
	cin >> N ;
	f[1] = f[2] = 1 ;
	for(i = 3 ; i <= N ; i++)
	f[i] = (f[i - 1] + f[i - 2]) % 	MOD ;
	cout << f[N] << endl ;
	return  0 ; 
}
