/*
ID: zhangsh35
PROG: dualpal 
LANG: C++
*/
#include<fstream>
using namespace std ;
ifstream cin("dualpal.in") ;
ofstream cout("dualpal.out") ;
int totNumber , minNumber  , cnt ;
int digit[100000 + 10] ;
bool isPal( int digit[] , int len ){
	int i ;
	for( i = 0 ; i < len / 2 ; i++ ){
		if(digit[i] != digit[len - i - 1])
		return false ;
	}
	return true ;
}
bool Judge( int num ){
	int top , ok = 0 , radix , number , len ;
	for( radix = 2 ; radix <= 10 ; radix++ ){
		number = num ;
		len = 0 ;
		while(number){
			digit[len++] = number % radix ;
			number /= radix ;
		}
		if(isPal( digit , len ))
		ok++ ;
	}
	return (ok >= 2) ? true : false ;
}

int main(){
	int i  ;
	cin >> totNumber >> minNumber ;
	i = minNumber + 1 ;
	while(cnt < totNumber){
		if(Judge(i)){
			cout << i << endl ;
			cnt++ ;
		}
		i++ ;	
	}
	return 0 ;
	
}
