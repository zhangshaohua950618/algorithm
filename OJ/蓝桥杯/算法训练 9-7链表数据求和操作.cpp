#include<iostream>
using namespace std;
int a , b;
int sumA , sumB;
int main(){
	int i;
	for(i = 0 ; i < 10 ; i++){
	cin >> a >> b;
	sumA += a;
	sumB += b;	
	}
	cout << sumA << "+" << sumB << "i" << endl;
	return 0;
}
