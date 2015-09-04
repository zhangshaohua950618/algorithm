#include<iostream>
#include<string.h>
#include<string>
using namespace std ;
const int MAXN = 200 ;
int n ;
string str ;
int main(){
	int i , j ;
	cin >> n ;
	while( n-- ){
		cin >> str ;
		for(  i = 0 ; i < str.length() ; ){
			int  num = 0 ;
			for(  j = i ; str[i] == str[j] ; j++)
			num++ ;
			if(num > 1)
			cout << num ;
			cout << str[i] ;
			i = j ;
		}
		cout << endl ;
		
	}
}
