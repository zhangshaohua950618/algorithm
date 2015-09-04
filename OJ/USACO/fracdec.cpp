/*
ID:    zhangsh35
PROG:    fracdec
LANG:    C++
*/
#include<fstream>
using namespace std ;
ifstream cin("fracdec.in") ;
ofstream cout("fracdec.out") ;
const int MAXN = 50000 ;
int remain[MAXN] , result[MAXN] , cnt , start , count ,  isRemain[100001] ;
int N , D ;
void Count(){
	count++ ;
	if(count == 76){
		cout << endl ;
		count = 0 ; 
	}
}
void OutPut(){
	for( int i = 0 ;i <= cnt ; i++ ){
		cout << result[i] ;
		Count() ;
		if( i == 0 ){
			cout << "." ;
			Count() ;
		}
		if(i == start){
			cout << "(" ;
			Count() ;
		}
	}
	cout << ")" << endl ;
	exit(0) ;
}
int main(){
	cin >> N >> D ;
	int temp = N / D ;
	while(temp){
		count++ ;
		temp /= 10 ;
	}
	if(( N / D) == 0)
	count = 1 ;
	count-- ;
	int spare  = N % D ;
	result[cnt] = N / D ;
	remain[cnt] = spare ;
	isRemain[spare] = -1 ;
	cnt++ ;
	do{
		result[cnt] = ( spare * 10 ) / D ;
		spare = ( spare * 10 ) % D ;
		if(spare == 0 )
		break ;
		if(isRemain[spare]){
			start = isRemain[spare] ;
			if(start == -1)
			start = 0 ;
			OutPut() ;
		}
		remain[cnt] = spare ;
		isRemain[spare] = cnt ;
		cnt++ ;
		
	}while(spare) ;
	for( int i = 0 ;i <= cnt ; i++ ){
		cout << result[i] ;
		Count() ;
		if( i == 0){
			cout << "." ;
			Count() ;
		}
	}
	cout << endl ;
	return 0 ;
}
