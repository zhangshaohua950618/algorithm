#include<iostream>
#include<string.h>
using namespace std;
string a , b;
int main(){
	cin >> a >> b;
	for(int i = 0 ; i < a.length() ; i++)
	if(a[i] - b[i] != 0){
		cout << a[i] - b[i] << endl;
		return 0;
	}
	cout << "0" << endl;
	return 0;
}
