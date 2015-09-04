#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std ;
const int MAXN = 10000 + 10 ;
int cows[MAXN] , t ;
int main(){
	int i ;
	cin >> t ;
	for(i= 0 ; i < t ; i++)
	scanf("%d" , &cows[i]) ;
	sort(cows , cows + t);
	cout << cows[t / 2] << endl ;
	return 0 ;
}

