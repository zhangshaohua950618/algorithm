#include<fstream>
#include<cstdlib>
using namespace std ;
ifstream cin("skidesign.in") ;
ofstream cout("skidesign.out") ;
const int MAXN = 1000 + 10 ;
int mount[MAXN] , N , minHeight = (1 << 30) , ans ;
int main(){
	cin >> N ;
	for(int i = 0 ; i <= N ; i++){
		cin >> mount[i] ;
		minHeight = min(minHeight , mount[i]) ;
	}
	for(int i = 0 ;i <= N ; i++){
		if(mount[i] - (minHeight + 17) > 0)
		ans += mount[i] - (minHeight + 17) ;
	}
	cout << ans << endl ;
	return 0 ;
}
