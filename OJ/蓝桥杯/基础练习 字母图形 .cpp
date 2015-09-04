#include<iostream>
using namespace std;
int m , n ;
bool flag;
int main(){
	int i , j ;
	cin >> n >> m;
	for(i = 'A' ; i < 'A' + n ; i++){
		int out = i;
		flag = false;
		for(j = 1 ; j <= m ; j++){	
		cout << (char)out;
		if(out == 'A')
		flag = true;
		if(flag)
		out++;
		else
		out--;
		}	
		cout << endl; 
	}
}
