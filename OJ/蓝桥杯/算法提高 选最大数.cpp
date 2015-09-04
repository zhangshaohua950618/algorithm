#include<iostream>
#include<cstdlib>
using namespace std;
int a , b , c;
int main(){
	cin >> a >> b >> c;
	cout << max(a , max(b, c)) << endl;
	return 0;
	
}
