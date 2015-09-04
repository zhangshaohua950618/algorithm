#include<fstream>
#include<map>
#include<set>
#include<string.h>
using namespace std ;
ifstream cin("lgame.in") ;
ifstream fin("lgame.dict") ;
ofstream cout("lgame.out") ;
map< char , int > a ;
typedef pair< string , string > stringPair ;
set<stringPair> s ;
string dict[40000 + 10] ,  str  ;
int totDict  , totLength , count ;
int standard[200] ;
int temp[200] ;
void Initial(){
	a['q'] = 7 ;
	a['w'] = 6 ;
	a['e'] = 1 ;
	a['r'] = 2 ;
	a['t'] = 2 ;
	a['y'] = 5 ;
	a['u'] = 4 ;
	a['i'] = 1 ;
	a['o'] = 3 ;
	a['p'] = 5 ;
	a['a'] = 2 ;
	a['s'] = 1 ;
	a['d'] = 4 ;
	a['f'] = 6 ;
	a['g'] = 5 ;
	a['h'] = 5 ;
	a['j'] = 7 ;
	a['k'] = 6 ;
	a['l'] = 3 ;
	a['z'] = 7 ;
	a['x'] = 7 ;
	a['c'] = 4 ;
	a['v'] = 6 ;
	a['b'] = 5 ;
	a['n'] = 2 ;
	a['m'] = 5 ;
	for( int i = 0 ; i < str.length() ; i++ )
	standard[str[i]]++ ;
	totLength = str.length() ;
	
}
int GetScore( string str ){
	int score = 0  ;
	for( int i = 0 ; i < str.length() ; i++ )
		score += a[str[i]] ;
		return score ;
}
int Judge( string str ){
	count = 0 ;
	memset( temp , 0 , sizeof(temp) ) ;
	for( int  i = 0 ; i < str.length() ; i++ ){
		temp[str[i]]++ ;
		count++ ;
		if(temp[str[i]] > standard[str[i]]){
			return 0 ;
		}
	}
	if( count == totLength )
		return 1 ;
	if( count < totLength )	
		return 2 ;
}
int main(){
	int  i = 0 , j = 0 ; 
	cin >> str ;
	Initial() ;
	while( fin >> dict[i] && dict[i] != ".")
		i++ ;
	totDict = i ;
	cout << GetScore( str ) << endl ;
	for( i = 0 ; i < totDict ; i++  ){
		if(Judge( dict[i] ) == 1 )
		cout << dict[i] << endl ;
		if(Judge( dict[i] ) == 2 ){
			for( j = i ; j < totDict ; j++ )
			if(Judge( dict[i] + dict[j] ) == 1){
				cout<< dict[i] << " "  << dict[j] << endl ;
			}
		}
	}
}
