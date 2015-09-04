#include<iostream>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std ;
const int MAXN = 1000 + 10 ;
struct P{
	string name ;
	int score ;
} ;
int s[MAXN],n , m , k , l ;
P p[MAXN] ;
void input(int num){
	int c = 0 , n , m ;
	int i , j ;
	cin >> p[num].name ;
	cin >>  n ;
	for( i = 0 ; i < n ; i++ ){
		cin >> m ;
		c += s[m] ;
	}
	p[num].score = c ;
	if( c >= k )
	l++ ;
}
bool cmp ( P a , P b){
	if(a.score != b.score)
	return a.score > b.score ;
	return a.name < b.name ;
}
int main(){
	std::ios::sync_with_stdio(false) ;
	int i , j ;
	while( cin >> n >> m >> k && n != 0){
		l = 0 ;
		for(i = 1 ; i <= m ; i++ )
		cin >> s[i] ;
		for( i = 0 ; i < n ; i++ )
		input(i) ;
		sort(p , p + n , cmp) ;
		cout << l << endl ;
		for( i = 0; i < l ; i++ )
		cout << p[i].name << " " << p[i].score << endl ;
	}
	return 0 ;
}

