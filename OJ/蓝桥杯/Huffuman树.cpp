#include<iostream>
#include<queue>
using namespace std ;
priority_queue< int,vector<int>, greater<int> > q ;
int totDate , date , cost , a , b;
int main(){
	while( !q.empty() ){
		q.pop() ;
	}
	cin >> totDate ;
	for( int i = 0 ; i < totDate ; i++ ){
		cin >> date ;
		q.push(date) ;
	}
	while( q.size() > 1 ){
		a = q.top() ;
		q.pop() ;
		cost += a ;
		b = q.top() ;
		q.pop() ;
		cost += b ;
		q.push(a + b) ;
	}
	cout << cost << endl ;
	return 0 ;
	
	
}
