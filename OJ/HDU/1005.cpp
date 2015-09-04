#include<iostream>
#include<queue>
using namespace std ;
queue<int> q ;
int a , b , n ;
int main(){
	while( cin >> a >> b >> n && ( a || b || n)){
		while( !q.empty() )
		q.pop() ;
		q.push(1) ;
		q.push(1) ;
		n -= 2 ;
		while(n--){
		int temp = q.front() ;
		q.pop() ;//pop f[n - 2]
		q.push( ( a * q.front() + b * temp ) % 7 ) ;
		}
	//	cout << q.size() << endl ;
		q.pop() ;
	//	q.pop() ;
		cout << q.front() << endl ;
		q.pop() ;
	}
	
}

