/*
ID: zhangsh35
PROG: nuggets 
LANG: C++
*/
#include<fstream>
using namespace std ;
ifstream cin("nuggets.in") ;
ofstream cout("nuggets.out") ;
const int MAXN = 256 + 10 ;
int maxNuggets , count = 1 , amount ;
int  minNuggets = ( 1 << 30 ) , totNuggets , nuggets[ 10 + 10 ];
bool boxs[ MAXN * MAXN ] ;
bool Decide( int count ){
	for( int i = 0 ; i < totNuggets ; i++ ){
			if( count - nuggets[i] >= 0  ){
				if( boxs[ count - nuggets[i] ]){
					boxs[ count ] = true ;
					return true ;
				}
			}
		}
	return false ;
}
int main(){
	cin >> totNuggets ;
	for( int i = 0 ; i < totNuggets ; i++ ){
		cin >> nuggets[i] ;
		if( nuggets[i] < minNuggets )
		minNuggets = nuggets[i] ;		
	}
	boxs[0] = true ; 
	while( true  ){
		boxs[count] = Decide(count) ;
		if( boxs[count] ){
			amount++ ;
			if( amount == minNuggets  )
				break ;
		}
		else{
			maxNuggets = count ;
			amount = 0 ;
		}
		count++ ;
		if( count >= MAXN * MAXN - 1 ){
				cout << "0" << endl ;
				return 0 ;
			}
		}
	
	cout << maxNuggets << endl ;
}
