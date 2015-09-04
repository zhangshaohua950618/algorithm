#include<iostream>
using namespace std;
bool ok;
int sum;
int main(){
	int a , b , c;
	cin >> sum;
	
	
	for(a = 1 ; a < 10 ; a++)
	for(b = 0 ; b < 10 ; b++)
	for(c = 0 ; c < 10 ; c++){
		if(2 * a + 2 * b + c == sum){
			cout << a << b << c << b << a << endl;
			ok = true;
		}
	}
	
	
	for(a = 1 ; a < 10 ; a++)
	for(b = 0 ; b < 10 ; b++)
	for(c = 0 ; c < 10 ; c++){
		if(2 * a + 2 * b + 2 * c == sum){
			cout << a << b << c << c << b << a << endl;
			ok = true;
		}
	}
	
	if (!ok)
	cout << -1 << endl;
	return 0;
}
