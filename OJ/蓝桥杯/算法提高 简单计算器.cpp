#include<iostream>
using namespace std;
int a , b;
char s;
int main(){
	cin >> s >> a >>b;
	switch(s){
		case '+':{
			cout << a + b << endl;
			return 0;
		}
		
		case '-':{
			cout << a - b << endl;
			return 0;
		}
		
		case '*':{
			cout << a * b << endl;
			return 0;
		}
		
		case '/':{
			cout << a / b << endl;
			return 0;
		}
	}
	return 0;
}
