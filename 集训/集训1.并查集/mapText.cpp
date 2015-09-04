#include<iostream>
#include<map>
#include<string.h>
using namespace std ;
map< int , string > m ;
int main(){
	m.insert(make_pair( 1 , "one")) ;
	map< int , string >::iterator it = m.find(1) ;
	if(it != m.end() )
	cout << "Find" << endl ;
	else
	cout << "Not Find" << endl ;
	cout << it->first << endl ;
	return 0 ;
}
