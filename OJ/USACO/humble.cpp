/*
ID: zhangsh35
PROG: humble 
LANG: C++
*/
#include<fstream>
#include<iostream>
#include<queue>
using namespace std ;
struct Node{
	int date ;
	int pos ;
} ;
struct Humble{
	int date ;
	int num ;
	Humble( int a , int b ){
		date = a;
		num = b  ; 
	}
	bool operator < ( const Humble &a) const{
		return date > a.date ;
	}
} ;
int result[100000 + 10];
int totNode , totHumble ;
Node node[100 + 10] ;
int Calculate(){
	priority_queue<Humble> q ;
	result[0] = 1 ;
	int cnt = 0 ;
	int i ;
	for( i = 0 ; i < totNode ; i++ ){
		q.push(Humble( node[i].date , i )) ; 
	}
	while(cnt <= totHumble){
		if(q.top().date != result[cnt])
		result[++cnt] = q.top().date ;
		int temp = q.top().num ;
		q.pop() ;
		node[temp].pos++ ;
		q.push(Humble( node[temp].date * result[node[temp].pos] , temp )) ;
	}
	return result[totHumble] ;
	
}
int main(){
	ifstream cin("humble.in") ;
	ofstream cout("humble.out") ;
	int  i , j ;
	cin>>totNode>>totHumble ;
	for( i = 0 ; i < totNode ; i++ ){
		cin>>node[i].date ;
	}
	cout<<Calculate()<<endl;
	return 0 ;
	
}
