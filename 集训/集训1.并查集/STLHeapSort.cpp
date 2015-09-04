#include<iostream>
#include<queue>
using namespace std ;
priority_queue<int> q ;
int main(){
	int a[] = {2,3,56,0,1,23,44} ;
	for( int  i =0 ; i < 7 ; i++ )
	q.push(a[i]) ;
	while(!q.empty()){
		cout << q.top() << endl ;
		q.pop() ;
	}
	
}
