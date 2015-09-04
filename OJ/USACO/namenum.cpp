/*
ID: zhangsh35
PROG: namenum 
LANG: C++
*/
#include<fstream>
#include<string.h>
#include<map>
using namespace std ;
map< char , char > m ;
ifstream cinDict("dict.txt") ;
ifstream cin("namenum.in") ;
ofstream cout("namenum.out") ;
string goal  , str ;
bool ok , success;
void Initial(){
	m['A'] = '2' ;
	m['B'] = '2' ;
	m['C'] = '2' ;
	m['D'] = '3' ;
	m['E'] = '3' ;
	m['F'] = '3' ;
	m['G'] = '4' ;
	m['H'] = '4' ;
	m['I'] = '4' ;
	m['J'] = '5' ;
	m['K'] = '5' ;
	m['L'] = '5' ;
	m['M'] = '6' ;
	m['N'] = '6';
	m['O'] = '6' ;
	m['P'] = '7' ;
	m['R'] = '7' ;
	m['S'] = '7' ;
	m['T'] = '8' ;
	m['U'] = '8' ;
	m['V'] = '8' ;
	m['W'] = '9' ;
	m['X'] = '9' ;
	m['Y'] = '9' ;
}
int main(){
	int i , j ;
	Initial() ;
	cin >> goal ;
	for( i = 1 ; i <= 4617 ; i++ ){
		cinDict >> str ;
		success = true ;
		if(goal.length() != str.length() )
		continue ;
		for( j = 0 ; j < str.length() ; j++ ){
			if(goal[j] != m[str[j]]){
				success = false ;
				break ;
			}
		}
		if(success){
			cout << str << endl ;;
			ok = true ;
		}
	}
	if(!ok)
	cout << "NONE" << endl ;
	return 0 ;
	
}
