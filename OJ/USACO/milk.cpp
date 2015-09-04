/*
ID: zhangsh35
PROG: milk 
LANG: C++
*/
#include<fstream>
#include<fstream>
#include<algorithm>
using namespace std ;
const int MAXN = 5000 + 10 ;
ifstream cin("milk.in") ;
ofstream cout("milk.out") ;
struct Milk{
	int price ;
	int amount ;
} ;
Milk milk[MAXN] ;
int totAmount , totMilk , currentAmount , sum ;
bool cmp( Milk a , Milk b ){
	return a.price < b.price ;
}
int main(){
	int  i ;
	cin >> totAmount >> totMilk ;
	for( i = 0 ; i < totMilk ; i++ )
	cin >> milk[i].price >> milk[i].amount ;
	sort( milk , milk + totMilk , cmp ) ;
	i = 0 ;
	while(currentAmount < totAmount){
		currentAmount += milk[i].amount ;
		sum += milk[i].price * milk[i].amount ; 
		i++ ;
	}
	i-- ;
	sum -= milk[i].price * ( currentAmount - totAmount ) ;
	cout << sum << endl ;
	return 0 ;
}
