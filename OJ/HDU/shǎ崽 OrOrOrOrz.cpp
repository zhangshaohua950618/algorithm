#include<iostream>
#include<algorithm>
using namespace std ;
const int MAXN = 10000 + 10 ;
int n , num[MAXN] ;
bool ok ;
int main(){
	int i , j ;
	while( cin >> n ){
		for( i = 0 ; i < n ; i++ )
		cin >> num[i] ;
		sort(num , num + n ) ;
		i = 0 , j = n - 1 ;
		ok = false ;
		while( i < j ){
			if(ok){
				cout << num[i] ;
				i++ ;
				if(i != j){
					cout << " " ;
					ok = !ok ;
				}
				else{
					cout<<" "<< num[i] << endl ;
					break ;
				}
			}
			else{
				cout << num[j] ;
				j-- ;
				if(i != j){
					cout << " " ;
					ok = !ok ;
				}
				else{
					cout<<" "<< num[i] << endl ;
					break ;
				}
			}
		}
	}
	return 0  ;
}
