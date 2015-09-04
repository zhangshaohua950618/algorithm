#include<iostream>
using namespace std;
int n;
int main(){
	int i , j;
	cin >> n;
	for(i = 0 ; i < n ; i++){
		for(j = 0 ; j < n - i - 1 ; j++)
		cout << "*" << " ";
		cout << "*" << endl;
	}
	
}
