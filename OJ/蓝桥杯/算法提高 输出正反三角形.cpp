#include<iostream>
#include<string.h>
using namespace std;
int n , m;
string s; 
int main(){
	int i , j;
	cin >> n >> m;
	for(i = 0 ; i < m ; i++)
	s += " ";
	for(j = 1 ; j <= n ; j++){
	for(i = 1 ; i <= 2 * n ; i++){
		if(i == j * 2)
		cout << s ;
		cout << "*";
	}
	cout << endl;
	}	
}
