#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std ;
const int MAXN = 1000 + 10 ;
int t , n  ;
struct P{
	string name ;
	string on ;
	string off ;
} ;
P p[MAXN] ;
bool on(P a ,P b){
	return a.on < b.on ;
}
bool off(P a ,P b ){
	return a.off > b.off ;
}
int main(){
	int i ,j ;
	cin >> t;
	while(t--){
		cin >> n ;
		for( i = 0 ; i < n ; i++ )
		cin >> p[i].name >> p[i].on >> p[i].off ;
		sort(p , p + n , on) ;
		cout << p[0].name ;
		cout << " " ;
		sort(p , p + n , off) ;
		cout << p[0].name ;
		cout << endl ;
		}
}
