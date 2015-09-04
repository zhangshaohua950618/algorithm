#include<iostream>
#include<string.h>
using namespace std;
string a , b;
int main(){
	cin >> a >> b;
	if(a<b)
	cout << "-1";
	else if(a==b)
	cout << "0";
	else if(a >b)
	cout << "1";
	cout << endl;
	return 0;
}
