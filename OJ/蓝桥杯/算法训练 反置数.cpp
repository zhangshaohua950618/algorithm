#include<iostream>
using namespace std;
int a , b;
int Reverse(int num){
	bool ok = false;
	int result = 0;
	while(num){
		int temp = num % 10;
		if(!ok && temp)
			ok = true;
		if(ok)
		result = result * 10 + temp;
		num /= 10;
	}
	return result;
}
int main(){
	cin >> a >> b;
	cout << Reverse(Reverse(a) + Reverse(b)) << endl;
	return 0;
}
