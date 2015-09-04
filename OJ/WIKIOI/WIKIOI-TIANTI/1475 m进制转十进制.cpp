#include<iostream>
#include<string.h>
using namespace std ;
int map[200] ;
int  m , power = 1 , sum ;
string n ;
int main(){
	int i , j  = 0;
	for(i = '0' , j = 0 ; i <= '9' ; i++ , j++)
	map[i] = j ;
	for(i = 'A' ; i <= 'F' ; i++ , j++)
	map[i] = j ;
	cin >> n >> m ;
	for(i = n.length() - 1 ; i >= 0 ; i--){
		sum += map[n[i]] * power ;
		power *= m ;
	}
	cout << sum << endl ;
	return 0 ;
}
