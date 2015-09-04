/*
ID: zhangsh35
PROG: clocks 
LANG: C++
*/
#include<fstream>
using namespace std ;
ifstream cin("clocks.in") ;
ofstream cout("clocks.out") ;
const int MAXN = 12 ;
int initial[MAXN] , current[MAXN] , result[20 + 10] ;
int initialTime , totTime  , num ;
int loop[MAXN] ;
void Transform( int num ){
	switch(num){
		case 1 : current[1] = ++current[1] % 4 ; current[2] = ++current[2] % 4 ; current[4] = ++current[4] % 4 ; current[5] = ++current[5]% 4 ; break ;
		case 2 : current[1] = ++current[1] % 4 ; current[2] = ++current[2] % 4 ; current[3] = ++current[3] % 4 ; break ;
		case 3 : current[2] = ++current[2] % 4 ; current[3] = ++current[3] % 4 ; current[5] = ++current[5] % 4 ; current[6] = ++current[6] % 4 ; break ;
		case 4 : current[1] = ++current[1] % 4 ; current[4] = ++current[4] % 4 ; current[7] = ++current[7] % 4 ; break ;
		case 5 : current[2] = ++current[2] % 4 ; current[4] = ++current[4] % 4 ; current[5] = ++current[5] % 4 ; current[6] = ++current[6] % 4 ; current[8] = ++current[8] % 4 ; break ;
		case 6 : current[3] = ++current[3] % 4 ; current[6] = ++current[6] % 4 ; current[9] = ++current[9] % 4 ; break ;
		case 7 : current[4] = ++current[4] % 4 ; current[5] = ++current[5] % 4 ; current[7] = ++current[7] % 4 ; current[8] = ++current[8] % 4 ; break ;
		case 8 : current[7] = ++current[7] % 4 ; current[8] = ++current[8] % 4 ; current[9] = ++current[9] % 4 ; break ;
		case 9 : current[5] = ++current[5] % 4 ; current[6] = ++current[6] % 4 ; current[8] = ++current[8] % 4 ; current[9] = ++current[9] % 4 ; break ;
	}
}
void Initial(){
	int i ;
	for( i = 1 ; i <= 9 ; i++ )
	current[i] = initial[i] ;
}
bool Judge(){
	int i ;
	for( i = 1 ; i <= 9 ; i++ ){
		if(current[i] != 0)
		return false ;
	}
	return true ;
}
int main(){
	int i ;
	for( i = 1 ; i <= 9 ; i++ ){
		cin >> initialTime ;
		initial[i] = ( initialTime / 3 ) % 4 ;
	}
	for( loop[1] = 0 ; loop[1] <= 3 ; loop[1]++ )
	for( loop[2] = 0 ; loop[2] <= 3 ; loop[2]++ )
	for( loop[3] = 0 ; loop[3] <= 3 ; loop[3]++ )
	for( loop[4] = 0 ; loop[4] <= 3 ; loop[4]++ )
	for( loop[5] = 0 ; loop[5] <= 3 ; loop[5]++ )
	for( loop[6] = 0 ; loop[6] <= 3 ; loop[6]++ )
	for( loop[7] = 0 ; loop[7] <= 3 ; loop[7]++ )
	for( loop[8] = 0 ; loop[8] <= 3 ; loop[8]++ )
	for( loop[9] = 0 ; loop[9] <= 3 ; loop[9]++ ){
		Initial() ;
		for( i = 1 ; i <= 9 ; i++ ){
			totTime = loop[i] ;
			while(totTime){
				Transform(i) ;
				totTime-- ;	
			}
		}
		if(Judge()){
			for( i = 1 ; i <= 9; i++){
				totTime = loop[i] ;
				while(totTime){
					result[num++] = i ;
					totTime-- ;
				}
			}
			for( i = 0 ; i  < num - 1 ; i++ )
			cout << result[i] << " " ;
			cout << result[i] << endl ; 
			exit(0) ;
		}
	}	
}
	

