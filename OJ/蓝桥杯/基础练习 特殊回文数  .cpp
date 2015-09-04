#include<iostream>
using namespace std ;
int N ;
int main(){
	cin >> N ;
	int i , j , k ;
	for(i = 1 ; i < 10 ; i++)
	for(j = 0 ; j < 10 ; j++)
	for(k = 0 ; k < 10 ; k++)
	if(i + i + j + j + k == N )
	cout << i << j << k <<  j << i << endl ;
	for(i = 1 ; i < 10 ; i++)
	for(j = 0 ; j < 10 ; j++)
	for(k = 0 ; k < 10 ; k++)
	if(i + i + j + j + k + k == N )
	cout << i << j << k << k <<  j << i << endl ;
	return 0 ;
}
