#include<fstream>
#include<queue>
#include<set>
using namespace std ;
ifstream cin("shuttle.in") ;
ofstream cout("shuttle.out") ;
struct Node{
	string state ;
	int index ;
	string path ;
} ;
set<string> s ;
string start , end ;
int length ;
queue<Node> q ;
string Swap( int a , int b , string str ){
	str[a] ^= str[b] ;
	str[b] ^= str[a] ;
	str[a] ^= str[b] ;
	return str ;
}
void Initial(){
	for( int  i = 0 ; i < length  ; i++ ){
		start += 'W' ;
		end += 'B' ;
	}
	start += ' ' ;	
	end += ' ' ;
	for( int i = 0 ; i < length  ; i++ ){
		start += 'B' ; 
		end += 'W' ;
	}
}
void Display( string path ){
	int i ;
	for( i = 0 ; i < path.length() - 1 ; i++ ){
		cout << path[i] ;
	/*	if(( i + 1 ) % 20 == 0 )
		cout << endl ;
		else
		cout << " " ; */
	}
	cout << path[i] << endl ;
	
}
void Update( Node node ){
	int index = node.index ;
	string path = node.path ;
	string state = node.state ;
	pair<set<string>::iterator , bool> p ;
	if( ( index >= 2 ) && ( state[index - 1] != state[index - 2]) ){
		p = s.insert(Swap(index , index - 2 , state )) ;
		if(p.second){
		//	cout << "1" << endl ;
			q.push((Node){  Swap(index , index - 2 , state ) , index - 2 , path += index - 2 + 1 + '0'});
		}
	}
	if( index >= 1 ){
		p = s.insert(Swap(index , index - 1 , state )) ;
		if(p.second){
	//		cout << "2" << endl ;
			q.push((Node){  Swap(index , index - 1 , state ) , index - 1 , path += index - 1 + 1 + '0'});
		}
	}
	if( index <= length * 2 - 1 ){
		p = s.insert(Swap(index , index + 1 , state )) ;
		if(p.second){
//			cout << "3" << endl ;
			q.push((Node){  Swap(index , index + 1 , state ) , index + 1 , path += index + 1 + 1 + '0'});
		}
	}
	if( ( index <= length * 2 - 2 ) && ( state[index + 1] != state[index + 2]) ){
		p = s.insert(Swap(index , index + 2 , state )) ;
		if(p.second){
//			cout << "4" << endl ;
			q.push((Node){  Swap(index , index + 2 , state ) , index + 2 , path += index + 2 + 1 + '0'});
		}
	}
	
}
int main(){
	int i = 0 ;
	cin >> length ; 
	Initial() ;
	q.push((Node){ start , length , ""}) ;
	s.insert(start) ;
	while( i <= 999999 ){
		Node node = q.front() ;
		q.pop() ;
		Display( node.state ) ;
		if( end == node.state ){
			Display( node.path ) ;
			return 0 ;
		}
		Update(node) ;
		i++ ;
	}
}
