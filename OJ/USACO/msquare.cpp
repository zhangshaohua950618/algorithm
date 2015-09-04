/*
ID:		zhangsh35
PROG:	msquare
LANG:	C++
*/
#include<fstream>
#include<set>
#include<queue>
#include<set>
using namespace std ;
ifstream cin("msquare.in") ;
ofstream cout("msquare.out") ;
struct Node{
	string state ;
	string path ;
	int length ;
	Node( string st , string pa , int len ){
		state = st ;
		path = pa ;
		length = len ;
	}
} ;
queue<Node> q ;
set<string> s ;
string finalState = "" , input , state  ;
pair<set<string>::iterator , bool> p ;
void Initial(){
	Node initialNode( "12345678" , "" , 0 ) ;
	q.push(initialNode) ;
	s.insert("12345678") ;
	for( int i = 0 ; i < 8 ; i++ ){
		cin >> input ;
		finalState += input ;
	}
}
int main(){
	Initial() ;
	while(!q.empty()){
		Node currentNode(q.front()) ;
		q.pop() ;
		if(currentNode.state == finalState){
			cout << currentNode.length << endl ;
			cout << currentNode.path << endl ;
			return 0 ;
		}
		else{
			state = currentNode.state ;
		//	cout << state << endl ;
			string newState(state.rbegin() , state.rend()) ;
			p = s.insert(newState) ;
			if(p.second){
				q.push(Node( newState , currentNode.path + "A" , currentNode.length + 1 )) ;
			}
			newState = "" ;
			newState = state[3] + state.substr( 0 , 3 ) + state.substr( 5 , 3 ) + state[4] ;
			p = s.insert(newState) ;
			if(p.second){
				q.push(Node( newState , currentNode.path + "B" , currentNode.length + 1 )) ;
			}
			newState = state ;
			newState[1] = state[6] ;
			newState[2] = state[1] ;
			newState[5] = state[2] ;
			newState[6] = state[5] ;
			p = s.insert(newState) ;
			if(p.second){
				q.push(Node( newState , currentNode.path + "C" , currentNode.length + 1 )) ;
			}	
		}
	}
}
