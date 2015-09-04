#include<iostream>
#include<list>
using namespace std ;
int totPerson ;
bool ok ;
struct Person{
	int num ;
	bool ok ;
} ;
list<Person> l ;
list<Person>::iterator it  ;
int main(){
	int i , j ;
	while( cin >> totPerson ){
		//initial
		ok = false ;
		for( i = totPerson + 1 ; !ok ; i++ ){
			l.clear() ;
			for( i = 1 ; i  <= totPerson ; i++ )
				l.push_back(Person{i,true}) ;
			for(       ; i  <= totPerson * 2 ; i++ )
				l.push_back(Person{i,false}) ;
			it = l.begin() ;
			ok = false ;
			// kill the  person
			while( l.size() > totPerson ){
			for( j = 1 ; j <= i ; j++){
				it++ ;
				if(it == l.end() )
				it = l.begin() ;
			}
			if( (*it).ok ){
				l.erase(it) ;
				if(l.size()  == totPerson){
					ok = true ;
					break ;
				}
			}
			else{
				break ;
			}
			}
		}
		cout << i << endl ;
	}
	return 0 ;
} 
