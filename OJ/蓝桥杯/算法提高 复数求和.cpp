#include<iostream>
using namespace std;
int a , b , sumA , sumB , tot;
int main(){
	int i;
	cin >> tot;
	for(i = 0 ;i < tot ; i++){
		cin >> a >> b;
		sumA += a;
		sumB += b;
	}
	cout << sumA << "+" << sumB << "i" << endl;
	return 0;
}
