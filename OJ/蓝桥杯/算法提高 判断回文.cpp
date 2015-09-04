#include<iostream>
#include<string.h>
using namespace std;
string a;
string b;
int main(){
	int i;
	cin >> a;
	b = "";
	for(i = a.length() - 1 ; i >= 0 ; i--){
		b += a[i];
	}
	if(a == b)
	cout << "yes!" << endl;
	else
	cout << "no!" << endl;
	return 0;
}
