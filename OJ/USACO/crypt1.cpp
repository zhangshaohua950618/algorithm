/*
ID: zhangsh35
PROG: crypt1 
LANG: C++
*/
#include<fstream>
using namespace std ;
ifstream cin("crypt1.in") ;
ofstream cout("crypt1.out") ;
const int MAXN = 10 + 20 ;
int totNumber , ok ;
bool isNumber[MAXN] ;
int number[MAXN] ;
bool JudgeResultIndex( int num ){
	if( num < 100 || num > 999 )
	return false ;
	int temp ;
	while(num){
		temp = num % 10 ;
		if(!isNumber[temp])
		return false ;
		num /= 10 ;
	}
	return true ;
	
}
bool JudgeResultFinal( int num){
	if( num < 1000 || num > 9999 )
	return false ;
	int temp ;
	while(num){
		temp = num % 10 ;
		if(!isNumber[temp])
		return false ;
		num /= 10 ;
	}
	return true ;
}
int main(){
	int i  , j  , k , l , m  , resultIndex1 , resultIndex2 , resultFinal;
	cin >> totNumber ;
	for(i = 1 ; i <= totNumber ; i++ ){
		cin >> number[i] ;
		isNumber[number[i]] = true ;
	}
	for( i = 1  ; i <= totNumber ; i++ )
	for( j = 1  ; j <= totNumber ; j++ )
	for( k = 1  ; k <= totNumber ; k++ )
	for( l = 1  ; l <= totNumber ; l++ )
	for( m = 1  ; m <= totNumber ; m++ ){
		resultIndex1 = ( number[i] * 100 + number[j] * 10 + number[k] ) * number[m] ;
		resultIndex2 = ( number[i] * 100 + number[j] * 10 + number[k] ) * number[l] ;
		resultFinal = resultIndex1 * 10 + resultIndex2 ;
		if( JudgeResultIndex(resultIndex1) && JudgeResultIndex(resultIndex2) && JudgeResultFinal(resultFinal)){
			ok++ ;
			/*cout << ( number[i] * 100 + number[j] * 10 + number[k] ) << endl ;
			cout << resultIndex1 << " " << resultIndex2 << " " << resultFinal << endl ; */
		}
	}
	cout << ok << endl ;
}
