/*
ID: zhangsh35
PROG: wormhole
LANG: C++
*/
#include<fstream>
#include<set>
using namespace std ;
ifstream cin("wormhole.in") ;
ofstream cout("wormhole.out") ;
int n , x , y , ans ;
set<int> s ;
pair<set<int>::iterator , bool> p ;
int main(){
	cin >>  n ;
	
	
	for(int i = 0 ; i <  n ; i++){
		cin >> x >> y ;
		p = s.insert(y) ;
		if(!p.second)
		ans++ ;
	}
	
	
	cout << ans << endl ;
	return 0 ;
}

