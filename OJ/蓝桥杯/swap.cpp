#include<iostream>
using namespace std;
void Swap(int &a , int &b){
	a ^= b;
	b ^= a;
	a ^= b;
}
int main(){
	int a = 3 , b = 4;
	cout << a << " " << b << endl;
	Swap(a , b);
	cout << a << " " << b << endl;
	return 0;
	
}
