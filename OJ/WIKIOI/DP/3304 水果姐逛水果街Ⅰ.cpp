#include<iostream>
#define MAX(a , b) ((a) > (b) ? (a) : (b))
#define MIN(a , b) ((a) < (b) ? (a) : (b))
using namespace std ;
const int MAXN = 200000 + 10 ;
int  p[MAXN] , N , m , x , y ;
int main(){
	int minP , maxP , ans ;
	cin >> N ;
	for(int i = 1 ; i <= N ; i++)
	cin >> p[i] ;
	cin >> m ;
	for(int i = 0 ; i < m ; i++){
		cin >> x >> y ;
		minP = p[x] ;
		ans = 0 ;
		if(x < y){
		for(int  j = x ; j <= y ; j++){
		minP = MIN(minP , p[j]) ;
		ans = MAX(ans , p[j] - minP) ;
		}
		}
		else{
			for(int j = x ; j >= y ; j--){
				minP = MIN(minP , p[j]) ;
				ans = MAX(ans , p[j] - minP) ;
			}
		}
		cout << ans << endl ;
	}
}

