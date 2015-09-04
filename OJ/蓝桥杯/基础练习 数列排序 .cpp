#include<iostream>
#include<algorithm>
using namespace std ;
const int MAXN = 200 + 10 ;
int N , num[MAXN] ;
int main(){
	int i ;
	cin >> N ;
	for(i = 0 ; i < N ; i++)
	cin >> num[i] ;
	sort(num , num + N) ;
	for(i = 0 ; i < N - 1 ; i++)
	cout << num[i] << " " ;
	cout << num[i] << endl ;
	return 0 ;
}
