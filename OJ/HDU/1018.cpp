#include<iostream>
#include<math.h>
using namespace std ;
const int MAXN = 1000 + 10 ;
int f[MAXN] ;
int n ,num ;
double sum ;
int main(){
		cin >> n ;
		while(n--){
			cin >> num ;
			sum = 0 ;
		for( int i = 1 ; i <= num ; i ++ )
			sum += log10((double)(i)) ;
		cout << (int)(sum) + 1 << endl ;
		}
	return 0 ;
} 
